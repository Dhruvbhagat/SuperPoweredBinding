//
//  SuperpoweredFilterXCodeWrapper.h
//  SuperpoweredXCodeWrapper
//
//  Created by Rodrique Fru on 10/14/17.
//  Copyright © 2017 Bryon Baker. All rights reserved.
//

#ifndef SuperpoweredFilterXCodeWrapper_h
#define SuperpoweredFilterXCodeWrapper_h

#include <stdio.h>
#include "SuperpoweredFilter.h"

extern "C" SuperpoweredFilter* SuperpoweredFilter_Create(SuperpoweredFilterType filterType, unsigned int samplerate);

extern "C" void SuperpoweredFilter_Dispose(SuperpoweredFilter* pObject);

/**
 @brief Change parameters for resonant filters.
 
 @param frequency The frequency in Hz.
 @param resonance Resonance value.
 */
extern "C" void SuperpoweredFilter_SetResonantParameters(SuperpoweredFilter *pObject, float frequency, float resonance);
/**
 @brief Change parameters for shelving filters.
 
 @param frequency The frequency in Hz.
 @param slope Slope.
 @param dbGain Gain in decibel.
 */
extern "C" void SuperpoweredFilter_SetShelfParameters(SuperpoweredFilter *pObject, float frequency, float slope, float dbGain);
/**
 @brief Change parameters for bandlimited filters.
 
 @param frequency The center frequency in Hz.
 @param octaveWidth Width in octave.
 */
extern "C" void SuperpoweredFilter_SetBandlimitedParameters(SuperpoweredFilter *pObject, float frequency, float octaveWidth);
/**
 @brief Change parameters for parametric filters.
 
 @param frequency The center frequency in Hz.
 @param octaveWidth Width in octave.
 @param dbGain Gain in decibel.
 */
extern "C" void SuperpoweredFilter_SetParametricParameters(SuperpoweredFilter *pObject, float frequency, float octaveWidth, float dbGain);

/**
 @brief Set params and type at once for resonant filters.
 
 @param frequency The frequency in Hz.
 @param resonance Resonance value.
 @param type Must be lowpass or highpass.
 */
extern "C" void SuperpoweredFilter_SetResonantParametersAndType(SuperpoweredFilter *pObject, float frequency, float resonance, SuperpoweredFilterType type);
/**
 @brief Set params and type at once for shelving filters.
 
 @param frequency The frequency in Hz.
 @param slope Slope.
 @param dbGain Gain in decibel.
 @param type Must be low shelf or high shelf.
 */
extern "C" void SuperpoweredFilter_SetShelfParametersAndType(SuperpoweredFilter *pObject, float frequency, float slope, float dbGain, SuperpoweredFilterType type);

/**
 @brief Set params and type at once for bandlimited filters.
 
 @param frequency The center frequency in Hz.
 @param octaveWidth Width in octave.
 @param type Must be bandpass or notch.
 */
extern "C" void SuperpoweredFilter_SetBandlimitedParametersAndType(SuperpoweredFilter *pObject, float frequency, float octaveWidth, SuperpoweredFilterType type);

/**
 @brief Set custom coefficients for the filter.
 
 Coefficient changes will be smoothly handled.
 
 @param coefficients Pointer to the 5 coefficients of the first direct form IIR filter.
 */
extern "C" void SuperpoweredFilter_SetCustomCoefficients(SuperpoweredFilter *pObject, float coefficients[]);

/**
 @brief Turns the effect on/off.
 */
extern "C" void SuperpoweredFilter_Enable(SuperpoweredFilter *pObject, bool flag); // Use this to turn it on/off.

/**
 @brief Sets the sample rate.
 
 @param samplerate 44100, 48000, etc.
 */
extern "C" void SuperpoweredFilter_SetSamplerate(SuperpoweredFilter *pObject, unsigned int samplerate);
/**
 @brief Reset all internals, sets the instance as good as new and turns it off.
 */
extern "C" void SuperpoweredFilter_Reset(SuperpoweredFilter *pObject);

/**
 @brief Processes interleaved audio.
 
 @return Put something into output or not.
 
 @param input 32-bit interleaved stereo input buffer. Can point to the same location with output (in-place processing).
 @param output 32-bit interleaved stereo output buffer. Can point to the same location with input (in-place processing).
 @param numberOfSamples Should be 32 minimum and exactly divisible with 8.
 */
extern "C" bool SuperpoweredFilter_Process(SuperpoweredFilter *pObject, float input[], float output[], unsigned int numberOfSamples);

/**
 @brief Processes mono audio.
 
 @return Put something into output or not.
 
 @param input 32-bit input buffer. Can point to the same location with output (in-place processing).
 @param output 32-bit output buffer. Can point to the same location with input (in-place processing).
 @param numberOfSamples Should be 32 minimum and exactly divisible with 8.
 */
extern "C" bool SuperpoweredFilter_ProcessMono(SuperpoweredFilter *pObject, float input[], float output[], unsigned int numberOfSamples);

#endif /* SuperpoweredFilterXCodeWrapper_h */
