#import "SuperpoweredFrequencies.h"
#import "SuperpoweredIOSAudioOutput.h"
#include "SuperpoweredBandpassFilterbank.h"
#include "SuperpoweredDecoder.h"
#include "SuperpoweredSimple.h"
#include "SuperpoweredRecorder.h"
#include "SuperpoweredTimeStretching.h"
#include "SuperpoweredAudioBuffers.h"
#include "SuperpoweredFilter.h"
#include "SuperpoweredAnalyzer.h"
#include <pthread.h>

#define NUM_BANDS   (4*13)      // Must be a multiple of 4
#define FREQ_OFFSET (int)-29

@implementation SuperpoweredFrequencies {
    SuperpoweredIOSAudioOutput *audioIO;
    SuperpoweredBandpassFilterbank *filters;
    float bands[NUM_BANDS];
    pthread_mutex_t mutex;
    unsigned int samplerate, samplesProcessedForOneDisplayFrame;
}

- (id)init {
    self = [super init];
    if (!self) return nil;
    samplerate = 44100;
    samplesProcessedForOneDisplayFrame = 0;
    memset(bands, 0, NUM_BANDS * sizeof(float));
    
    // We use a mutex to prevent simultaneous reading/writing of bands.
    pthread_mutex_init(&mutex, NULL);
    
    // float frequencies[8] = { 55, 110, 220, 440, 880, 1760, 3520, 7040 };
    // float widths[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    float frequencies[NUM_BANDS];
    float widths[NUM_BANDS];
    float bandWidth = 1.0f / 48.0f;
    for( int n = 0; n < NUM_BANDS; n++ )
    {
        frequencies[n] = 440.0f * powf(2, (float)(n+FREQ_OFFSET)/12.0f);
        widths[n] = bandWidth;
    }
    
    filters = new SuperpoweredBandpassFilterbank(NUM_BANDS, frequencies, widths, samplerate);
    
    audioIO = [[SuperpoweredIOSAudioOutput alloc] initWithDelegate:(id<SuperpoweredIOSAudioIODelegate>)self preferredBufferSize:12 preferredMinimumSamplerate:44100 audioSessionCategory:AVAudioSessionCategoryPlayAndRecord multiChannels:2 fixReceiver:2];
    audioIO.inputEnabled = true;
    [audioIO start];
    
    return self;
}

- (void)dealloc {
    delete filters;
    pthread_mutex_destroy(&mutex);
    audioIO = nil;
}

- (void)interruptionEnded {}

- (bool)audioProcessingCallback:(float **)buffers inputChannels:(unsigned int)inputChannels outputChannels:(unsigned int)outputChannels numberOfSamples:(unsigned int)numberOfSamples samplerate:(unsigned int)currentsamplerate hostTime:(UInt64)hostTime {
    if (samplerate != currentsamplerate) {
        samplerate = currentsamplerate;
        filters->setSamplerate(samplerate);
    };
    
    // Mix the non-interleaved input to interleaved.
    float interleaved[numberOfSamples * 2 + 16];
    SuperpoweredInterleave(buffers[0], buffers[1], interleaved, numberOfSamples);
    
    // Detect frequency magnitudes.
    float peak, sum;
    pthread_mutex_lock(&mutex);
    samplesProcessedForOneDisplayFrame += numberOfSamples;
    filters->process(interleaved, bands, &peak, &sum, numberOfSamples);
    pthread_mutex_unlock(&mutex);
    
    return false;
}

/*
 It's important to understand that the audio processing callback and the screen update (getFrequencies) are never in sync. 
 More than 1 audio processing turns can happen between two consecutive screen updates.
 */

- (void)getFrequencies:(float *)freqs {
    pthread_mutex_lock(&mutex);
    if (samplesProcessedForOneDisplayFrame > 0) {
        for (int n = 0; n < NUM_BANDS; n++)
            freqs[n] = bands[n] / float(samplesProcessedForOneDisplayFrame);
        memset(bands, 0, NUM_BANDS * sizeof(float));
        samplesProcessedForOneDisplayFrame = 0;
    } else
        memset(freqs, 0, NUM_BANDS * sizeof(float));
    pthread_mutex_unlock(&mutex);
}

// EXAMPLE 1: reading an audio file, applying a simple effect (filter) and saving the result to WAV
- (void)offlineFilter:(NSURL *)url outputs:(NSString *)outputFile progress:(double *)progress {
    // Open the input file.
    SuperpoweredDecoder *decoder = new SuperpoweredDecoder();
    const char *openError = decoder->open([[url absoluteString] UTF8String], false, 0, 0);
    if (openError) {
        NSLog(@"open error: %s", openError);
        delete decoder;
        return;
    };
    
    // Create the output WAVE file. The destination is accessible in iTunes File Sharing.
    NSString *destinationPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0] stringByAppendingPathComponent:outputFile];
    FILE *fd = createWAV([destinationPath fileSystemRepresentation], decoder->samplerate, 2);
    if (!fd) {
        NSLog(@"File creation error.");
        delete decoder;
        return;
    };
    
    // Creating the filter.
    SuperpoweredFilter *filter = new SuperpoweredFilter(SuperpoweredFilter_Resonant_Lowpass, decoder->samplerate);
    filter->setResonantParameters(1000.0f, 0.1f);
    filter->enable(true);
    
    // Create a buffer for the 16-bit integer samples coming from the decoder.
    short int *intBuffer = (short int *)malloc(decoder->samplesPerFrame * 2 * sizeof(short int) + 32768);
    // Create a buffer for the 32-bit floating point samples required by the effect.
    float *floatBuffer = (float *)malloc(decoder->samplesPerFrame * 2 * sizeof(float) + 32768);
    
    // Processing.
    while (true) {
        // Decode one frame. samplesDecoded will be overwritten with the actual decoded number of samples.
        unsigned int samplesDecoded = decoder->samplesPerFrame;
        if (decoder->decode(intBuffer, &samplesDecoded) == SUPERPOWEREDDECODER_ERROR) break;
        if (samplesDecoded < 1) break;
        
        // Convert the decoded PCM samples from 16-bit integer to 32-bit floating point.
        SuperpoweredShortIntToFloat(intBuffer, floatBuffer, samplesDecoded);
        
        // Apply the effect.
        filter->process(floatBuffer, floatBuffer, samplesDecoded);
        
        // Convert the PCM samples from 32-bit floating point to 16-bit integer.
        SuperpoweredFloatToShortInt(floatBuffer, intBuffer, samplesDecoded);
        
        // Write the audio to disk.
        fwrite(intBuffer, 1, samplesDecoded * 4, fd);
        
        // Update the progress indicator.
        *progress = ((double)decoder->samplePosition / (double)decoder->durationSamples);
    };
    
    // iTunes File Sharing: https://support.apple.com/en-gb/HT201301
    NSLog(@"The file is available in iTunes File Sharing, and locally at %@.", destinationPath);
    
    // Cleanup.
    closeWAV(fd);
    delete decoder;
    delete filter;
    free(intBuffer);
    free(floatBuffer);
}

// EXAMPLE 2: reading an audio file, applying time stretching and saving the result to WAV
- (void)offlineTimeStretching:(NSURL *)url outputs:(NSString *) outputFile progress:(double *)progress {
    // Open the input file.
    SuperpoweredDecoder *decoder = new SuperpoweredDecoder();
    const char *openError = decoder->open([[url absoluteString] UTF8String], false, 0, 0);
    if (openError) {
        NSLog(@"open error: %s", openError);
        delete decoder;
        return;
    };
    
    // Create the output WAVE file. The destination is accessible in iTunes File Sharing.
    NSString *destinationPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0] stringByAppendingPathComponent:@"SuperpoweredOfflineTest.wav"];
    FILE *fd = createWAV([destinationPath fileSystemRepresentation], decoder->samplerate, 2);
    if (!fd) {
        NSLog(@"File creation error.");
        delete decoder;
        return;
    };
    
    /*
     Due to it's nature, a time stretcher can not operate with fixed buffer sizes.
     This problem can be solved with variable size buffer chains (complex) or FIFO buffering (easier).
     
     Memory bandwidth on mobile devices is way lower than on desktop (laptop), so we need to use variable size buffer chains here.
     This solution provides almost 2x performance increase over FIFO buffering!
     */
    SuperpoweredTimeStretching *timeStretch = new SuperpoweredTimeStretching(decoder->samplerate);
    timeStretch->setRateAndPitchShift(1.04f, 0); // Audio will be 4% faster.
    // This buffer list will receive the time-stretched samples.
    SuperpoweredAudiopointerList *outputBuffers = new SuperpoweredAudiopointerList(8, 16);
    
    // Create a buffer for the 16-bit integer samples.
    short int *intBuffer = (short int *)malloc(decoder->samplesPerFrame * 2 * sizeof(short int) + 32768);
    
    // Processing.
    while (true) {
        // Decode one frame. samplesDecoded will be overwritten with the actual decoded number of samples.
        unsigned int samplesDecoded = decoder->samplesPerFrame;
        if (decoder->decode(intBuffer, &samplesDecoded) == SUPERPOWEREDDECODER_ERROR) break;
        if (samplesDecoded < 1) break;
        
        // Create an input buffer for the time stretcher.
        SuperpoweredAudiobufferlistElement inputBuffer;
        inputBuffer.samplePosition = decoder->samplePosition;
        inputBuffer.startSample = 0;
        inputBuffer.samplesUsed = 0;
        inputBuffer.endSample = samplesDecoded; // <-- Important!
        inputBuffer.buffers[0] = SuperpoweredAudiobufferPool::getBuffer(samplesDecoded * 8 + 64);
        inputBuffer.buffers[1] = inputBuffer.buffers[2] = inputBuffer.buffers[3] = NULL;
        
        // Convert the decoded PCM samples from 16-bit integer to 32-bit floating point.
        SuperpoweredShortIntToFloat(intBuffer, (float *)inputBuffer.buffers[0], samplesDecoded);
        
        // Time stretching.
        timeStretch->process(&inputBuffer, outputBuffers);
        
        // Do we have some output?
        if (outputBuffers->makeSlice(0, outputBuffers->sampleLength)) {
            
            while (true) { // Iterate on every output slice.
                // Get pointer to the output samples.
                int numSamples = 0;
                float *timeStretchedAudio = (float *)outputBuffers->nextSliceItem(&numSamples);
                if (!timeStretchedAudio) break;
                
                // Convert the time stretched PCM samples from 32-bit floating point to 16-bit integer.
                SuperpoweredFloatToShortInt(timeStretchedAudio, intBuffer, numSamples);
                
                // Write the audio to disk.
                fwrite(intBuffer, 1, numSamples * 4, fd);
            };
            
            // Clear the output buffer list.
            outputBuffers->clear();
        };
        
        // Update the progress indicator.
        *progress = (double)decoder->samplePosition / (double)decoder->durationSamples;
    };
    
    // iTunes File Sharing: https://support.apple.com/en-gb/HT201301
    NSLog(@"The file is available in iTunes File Sharing, and locally at %@.", destinationPath);
    
    // Cleanup.
    closeWAV(fd);
    delete decoder;
    delete timeStretch;
    delete outputBuffers;
    free(intBuffer);
}

// EXAMPLE 3: reading an audio file and analyzing it (for bpm, beatgrid, etc.)
- (void)offlineAnalyze:(NSURL *)url progress:(double *)progress {
    // Open the input file.
    SuperpoweredDecoder *decoder = new SuperpoweredDecoder();
    const char *openError = decoder->open([[url absoluteString] UTF8String], false, 0, 0);
    if (openError) {
        NSLog(@"open error: %s", openError);
        delete decoder;
        return;
    };
    
    // Create the analyzer.
    SuperpoweredOfflineAnalyzer *analyzer = new SuperpoweredOfflineAnalyzer(decoder->samplerate, 0, decoder->durationSeconds);
    
    // Create a buffer for the 16-bit integer samples coming from the decoder.
    short int *intBuffer = (short int *)malloc(decoder->samplesPerFrame * 2 * sizeof(short int) + 32768);
    // Create a buffer for the 32-bit floating point samples required by the effect.
    float *floatBuffer = (float *)malloc(decoder->samplesPerFrame * 2 * sizeof(float) + 32768);
    
    // Processing.
    while (true) {
        // Decode one frame. samplesDecoded will be overwritten with the actual decoded number of samples.
        unsigned int samplesDecoded = decoder->samplesPerFrame;
        if (decoder->decode(intBuffer, &samplesDecoded) == SUPERPOWEREDDECODER_ERROR) break;
        if (samplesDecoded < 1) break;
        
        // Convert the decoded PCM samples from 16-bit integer to 32-bit floating point.
        SuperpoweredShortIntToFloat(intBuffer, floatBuffer, samplesDecoded);
        
        // Submit samples to the analyzer.
        analyzer->process(floatBuffer, samplesDecoded);
        
        // Update the progress indicator.
        *progress = (double)decoder->samplePosition / (double)decoder->durationSamples;
    };
    
    // Get the result.
    unsigned char *averageWaveform = NULL, *lowWaveform = NULL, *midWaveform = NULL, *highWaveform = NULL, *peakWaveform = NULL, *notes = NULL;
    int waveformSize, overviewSize, keyIndex;
    char *overviewWaveform = NULL;
    float loudpartsAverageDecibel, peakDecibel, bpm, averageDecibel, beatgridStartMs = 0;
    analyzer->getresults(&averageWaveform, &peakWaveform, &lowWaveform, &midWaveform, &highWaveform, &notes, &waveformSize, &overviewWaveform, &overviewSize, &averageDecibel, &loudpartsAverageDecibel, &peakDecibel, &bpm, &beatgridStartMs, &keyIndex);
    
    // Cleanup.
    delete decoder;
    delete analyzer;
    free(intBuffer);
    free(floatBuffer);
    
    // Do something with the result.
    NSLog(@"Bpm is %f, average loudness is %f db, peak volume is %f db.", bpm, loudpartsAverageDecibel, peakDecibel);
    
    // Done with the result, free memory.
    if (averageWaveform) free(averageWaveform);
    if (lowWaveform) free(lowWaveform);
    if (midWaveform) free(midWaveform);
    if (highWaveform) free(highWaveform);
    if (peakWaveform) free(peakWaveform);
    if (notes) free(notes);
    if (overviewWaveform) free(overviewWaveform);
}


@end
