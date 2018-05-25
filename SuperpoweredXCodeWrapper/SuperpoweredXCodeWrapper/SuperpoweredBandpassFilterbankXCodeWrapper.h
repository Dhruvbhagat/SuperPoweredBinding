//
//  SuperpoweredXCodeWrapper.h
//  SuperpoweredXCodeWrapper
//
//  Created by Bryon on 6/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#ifndef __SuperpoweredXCodeWrapper__SuperpoweredXCodeWrapper__
#define __SuperpoweredXCodeWrapper__SuperpoweredXCodeWrapper__

#include <stdio.h>
#include "SuperpoweredBandpassFilterbank.h"

/**
 Create a filterbank instance.

 @param numBands The number of bands. Must be a multiply of 8.
 @param frequencies The center frequencies of the bands.
 @param widths The width of the bands. 1.0f is one octave, 1.0f / 12.0f is one halfnote.
 @param samplerate The initial sample rate.
 */
extern "C" SuperpoweredBandpassFilterbank* SuperpoweredBandpassFilterbank_Create(int numBands, float frequencies[], float widths[], unsigned int samplerate);

/**
 Destroy a filterbank instance.
 
 @param input Pointer to the SuperpoweredBandpassFilterbank object to destroy.
 */
extern "C" void SuperpoweredBandpassFilterbank_Dispose( SuperpoweredBandpassFilterbank* pObject);

/**
 @brief Sets the sample rate.

 @param input Pointer to the SuperpoweredBandpassFilterbank object.
 @param samplerate 44100, 48000, etc.
 */
extern "C" void SuperpoweredBandpassFilterbank_SetSamplerate( SuperpoweredBandpassFilterbank *pObject, unsigned int sampleRate );

/**
 @brief Processes the audio.

 @param input Pointer to the SuperpoweredBandpassFilterbank object.
 @param input 32-bit interleaved stereo input buffer.
 @param bands Frequency band results (magnitudes) will be ADDED to these. For example: bands[0] += result[0] If you divide each with the number of samples, the result will be between 0.0f and 1.0f.
 @param peak Maximum absolute peak value. Will compare against the input value of peak too. For example: peak = max(peak, fabsf(all samples))
 @param sum The cumulated absolute value will be ADDED to this. For example: sum += (sum of all fabsf(samples))
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredBandpassFilterbank_Process(SuperpoweredBandpassFilterbank *pObject, float input[], float bands[], float *peak, float *sum, unsigned int numberOfSamples, int group);

/**
 @brief Processes the audio.
 
 @param input Pointer to the SuperpoweredBandpassFilterbank object.
 @param input 32-bit interleaved stereo input buffer.
 @param bands Frequency band results. If you divide each with the number of samples, the result will be between 0.0f and 1.0f.
 @param peak Maximum absolute peak value. Will compare against the input value of peak too. For example: peak = max(peak, fabsf(all samples))
 @param sum The cumulated absolute value will be ADDED to this. For example: sum += (sum of all fabsf(samples))
 @param numberOfSamples The number of samples to process.
 @param group The group index for advanced "grouped" usage.
 */
extern "C" void SuperpoweredBandpassFilterbank_ProcessNoAdd(SuperpoweredBandpassFilterbank *pObject, float input[], float bands[], float *peak, float *sum, unsigned int numberOfSamples, int group);

#endif /* defined(__SuperpoweredXCodeWrapper__SuperpoweredXCodeWrapper__) */
