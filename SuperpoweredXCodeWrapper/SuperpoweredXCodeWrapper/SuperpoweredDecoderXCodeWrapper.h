//
//  SuperpoweredDecoderXCodeWrapper.h
//  SuperpoweredXCodeWrapper
//
//  Created by Rodrique Fru on 10/15/17.
//  Copyright © 2017 Bryon Baker. All rights reserved.
//

#ifndef SuperpoweredDecoderXCodeWrapper_h
#define SuperpoweredDecoderXCodeWrapper_h

#include <stdio.h>
#include "SuperpoweredDecoder.h"

/**
 @brief Creates an instance of SuperpoweredDecoder.
 
 @param downloadedCallback Callback for progressive download completion.
 @param clientData Custom pointer for the downloadedCallback.
 */
extern "C" SuperpoweredDecoder* SuperpoweredDecoder_Create(SuperpoweredDecoderFullyDownloadedCallback downloadedCallback, void *clientData);

/**
 @brief Opens a file for decoding.
 
 @param path Full file system path or progressive download path (http or https).
 @param metaOnly If true, it opens the file for fast metadata reading only, not for decoding audio. Available for fully available local files only (no network access).
 @param offset Byte offset in the file.
 @param length Byte length from offset. Set offset and length to 0 to read the entire file.
 @param stemsIndex Stems track index for Native Instruments Stems format.
 @param customHTTPHeaders NULL terminated list of custom headers for http communication.
 
 @return NULL if successful, or an error string. If the returned error string equals to "@", it means that the open method needs more time opening an audio file from the network. In this case, iterate over open() until it returns something else than "@". It's recommended to sleep 50-100 ms in every iteration to allow the network stack doing its job without blowing up the CPU.
 */
extern "C" const char *SuperpoweredDecoder_Open(SuperpoweredDecoder* pObject, const char path[], bool metaOnly = false, int offset = 0, int length = 0, int stemsIndex = 0, char **customHTTPHeaders = 0);
/**
 @brief Decodes the requested number of samples.
 
 @return End of file (0), ok (1), error (2) or buffering(3).
 
 @param pcmOutput The buffer to put uncompressed audio. Must be at least this big: (*samples * 4) + 16384 bytes.
 @param samples On input, the requested number of samples. Should be >= samplesPerFrame. On return, the samples decoded.
 */
extern "C" unsigned char SuperpoweredDecoder_Decode(SuperpoweredDecoder* pObject, short int pcmOutput[], unsigned int samples[]);
/**
 @brief Jumps to a specific position.
 
 @return ok (1), error (2) or buffering(3)
 
 @param sample The requested position (a sample index). The actual position (samplePosition) may be different after calling this method.
 @param precise Some codecs may not jump precisely due internal framing. Set precise to true if you want exact positioning (for a little performance penalty of 1 memmove).
 */
extern "C" unsigned char SuperpoweredDecoder_Seek(SuperpoweredDecoder* pObject, int64_t sample, bool precise);
/**
 @return End of file (0), ok (1), error (2) or buffering(3). This function changes position!
 
 @param limitSamples How far to search for. 0 means "the entire audio file".
 @param decibel Optional loudness threshold in decibel. 0 means "any non-zero audio sample". The value -49 is useful for vinyl rips.
 @param startSample Returns with the position where audio starts.
 */
extern "C" unsigned char SuperpoweredDecoder_GetAudioStartSample(SuperpoweredDecoder* pObject, unsigned int startSample[], unsigned int limitSamples = 0, int decibel = 0);
/**
 @brief Call this on a phone call or other interruption.
 
 Apple's built-in codec may be used in some cases, for example ALAC files.
 Call this after a media server reset or audio session interrupt to resume playback.
 */
extern "C" void SuperpoweredDecoder_ReconnectToMediaserver(SuperpoweredDecoder* pObject);
/**
 @brief Returns with often used metadata.
 
 @param artist Artist, set to NULL if you're not interested. Returns NULL if can not be retrieved. Ownership passed (you must free memory after finished using it).
 @param title Title, set to NULL if you're not interested. Returns NULL if can not be retrieved. Ownership passed (you must free memory after finished using it).
 @param image Raw image data (usually PNG or JPG). Set to NULL if you're not interested. Returns NULL if can not be retrieved. Ownership passed (you must free memory after finished using it).
 @param imageSizeBytes Size of the raw image data. Set to NULL if you're not interested.
 @param bpm Tempo in beats per minute. Set to NULL if you're not interested.
 @param callback A callback to process other ID3 frames. Set to NULL if you're not interested.
 @param clientData A custom pointer the callback receives.
 @param maxFrameDataSize The maximum frame size in bytes to receive by the callback, if the decoder can not memory map the entire audio file. Affects memory usage.
 */
extern "C" void SuperpoweredDecoder_GetMetaData(SuperpoweredDecoder* pObject, char **artist, char **title, void **image, int *imageSizeBytes, float *bpm, SuperpoweredDecoderID3Callback callback, void *clientData, int maxFrameDataSize);
/**
 @return True if the file is Native Instruments Stems format.
 
 @param names Returns with 4 pointers of 0 terminated stem name strings or NULL if the file is not Stems. You take ownership (must free memory after used.).
 @param colors Returns with 4 pointers of 0 terminated stem color strings or NULL if the file is not Stems. You take ownership (must free memory after used.).
 @param compressor Struct to receive compressor DSP settings. Can be NULL.
 @param limiter Struct to receive limiter DSP settings. Can be NULL;
 */
extern "C" bool SuperpoweredDecoder_GetStemsInfo(SuperpoweredDecoder* pObject, char *names[4] = 0, char *colors[4] = 0, stemsCompressor *compressor = 0, stemsLimiter *limiter = 0);

extern "C" void SuperpoweredDecoder_Dispose(SuperpoweredDecoder* pObject);

#endif /* SuperpoweredDecoderXCodeWrapper_h */
