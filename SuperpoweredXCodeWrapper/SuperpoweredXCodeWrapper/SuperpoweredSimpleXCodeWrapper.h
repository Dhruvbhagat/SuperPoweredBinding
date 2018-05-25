//
//  SuperpoweredSimpleXCodeWrapper.h
//  SuperpoweredXCodeWrapper
//
//  Created by Bryon on 6/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#ifndef __SuperpoweredXCodeWrapper__SuperpoweredSimpleXCodeWrapper__
#define __SuperpoweredXCodeWrapper__SuperpoweredSimpleXCodeWrapper__

#include "SuperpoweredSimple.h"

/**
 @fn SuperpoweredInterleave(float *left, float *right, float *output, unsigned int numberOfSamples);
 @brief Makes an interleaved output from two input channels.
 
 @param left Input for left channel.
 @param right Input for right channel.
 @param output Interleaved output.
 @param numberOfSamples The number of samples to process. Should be 4 minimum, must be exactly divisible with 4.
 */
//extern "C" void SuperpoweredSimple_SuperpoweredInterleave(float left[], float right[], float output[], unsigned int numberOfSamples);

/**
 @fn SuperpoweredVolume(float *input, float *output, float volumeStart, float volumeEnd, unsigned int numberOfSamples);
 @brief Applies volume on a single stereo interleaved buffer.
 
 @param input Input buffer.
 @param output Output buffer. Can be equal to input (in-place processing).
 @param volumeStart Volume for the first sample.
 @param volumeEnd Volume for the last sample. Volume will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredVolume(float input[], float output[], float volumeStart, float volumeEnd, unsigned int numberOfSamples);

/**
 @fn SuperpoweredChangeVolume(float *input, float *output, float volumeStart, float volumeChange, unsigned int numberOfSamples);
 @brief Applies volume on a single stereo interleaved buffer.
 
 @param input Input buffer.
 @param output Output buffer. Can be equal to input (in-place processing).
 @param volumeStart Voume for the first sample.
 @param volumeChange Change volume by this amount for every sample.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredChangeVolume(float input[], float output[], float volumeStart, float volumeChange, unsigned int numberOfSamples);

/**
 @fn SuperpoweredVolumeAdd(float *input, float *output, float volumeStart, float volumeEnd, unsigned int numberOfSamples);
 @brief Applies volume on a single stereo interleaved buffer and adds it to the audio in the output buffer.
 
 @param input Input buffer.
 @param output Output buffer.
 @param volumeStart Volume for the first sample.
 @param volumeEnd Volume for the last sample. Volume will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredVolumeAdd(float input[], float output[], float volumeStart, float volumeEnd, unsigned int numberOfSamples);

/**
 @fn SuperpoweredChangeVolumeAdd(float *input, float *output, float volumeStart, float volumeChange, unsigned int numberOfSamples);
 @brief Applies volume on a single stereo interleaved buffer and adds it to the audio in the output buffer.
 
 @param input Input buffer.
 @param output Output buffer.
 @param volumeStart Volume for the first sample.
 @param volumeChange Change volume by this amount for every sample.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredChangeVolumeAdd(float input[], float output[], float volumeStart, float volumeChange, unsigned int numberOfSamples);

/**
 @fn SuperpoweredPeak(float *input, unsigned int numberOfValues);
 @return Returns with the peak value.
 
 @param input An array of floating point values.
 @param numberOfValues The number of values to process. (2 * numberOfSamples for stereo input) Must be a multiply of 8.
 */
extern "C" float SuperpoweredSimple_SuperpoweredPeak(float input[], unsigned int numberOfValues);

/**
 @fn SuperpoweredCharToFloat(signed char *input, float *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 8-bit audio to 32-bit floating point.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_SuperpoweredCharToFloat(signed char input[], float output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredFloatToChar(float *input, signed char *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 32-bit floating point audio 8-bit audio.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_SuperpoweredFloatToChar(float input[], signed char output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn Superpowered24bitToFloat(void *input, float *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 24-bit audio to 32-bit floating point.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_Superpowered24bitToFloat(float input[], float output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredFloatTo24bit(float *input, void *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 32-bit floating point audio to 24-bit.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_SuperpoweredFloatTo24bit(float input[], float output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredIntToFloat(int *input, float *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 32-bit integer audio to 32-bit floating point.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_SuperpoweredIntToFloat(int input[], float output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredFloatToInt(float *input, int *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 32-bit floating point audio to 32-bit integer.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_SuperpoweredFloatToInt(float input[], int output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredFloatToShortInt(float *input, short int *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 32-bit float input to 16-bit signed integer output.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
extern "C" void SuperpoweredSimple_SuperpoweredFloatToShortInt(float input[], short int output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredFloatToShortIntInterleave(float *inputLeft, float *inputRight, short int *output, unsigned int numberOfSamples);
 @brief Converts two 32-bit float input channels to stereo interleaved 16-bit signed integer output.
 
 @param inputLeft 32-bit input for the left side. Should be numberOfSamples + 8 big minimum.
 @param inputRight 32-bit input for the right side. Should be numberOfSamples + 8 big minimum.
 @param output Stereo interleaved 16-bit output. Should be numberOfSamples * 2 + 16 big minimum.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredFloatToShortIntInterleave(float inputLeft[], float inputRight[], short int output[], unsigned int numberOfSamples);

/**
 @fn SuperpoweredShortIntToFloat(short int *input, float *output, unsigned int numberOfSamples, float *peaks);
 @brief Converts a stereo interleaved 16-bit signed integer input to stereo interleaved 32-bit float output.
 
 @param input Stereo interleaved 16-bit input. Should be numberOfSamples + 8 big minimum.
 @param output Stereo interleaved 32-bit output. Should be numberOfSamples + 8 big minimum.
 @param numberOfSamples The number of samples to process.
 @param peaks Peak value result (2 floats: left peak, right peak).
 */
extern "C" void SuperpoweredSimple_SuperpoweredShortIntToFloat(short int input[], float output[], unsigned int numberOfSamples, float peaks[]);

/**
 @fn SuperpoweredShortIntToFloat(short int *input, float *output, unsigned int numberOfSamples, unsigned int numChannels);
 @brief Converts 16-bit signed integer input to 32-bit float output.
 
 @param input Input buffer.
 @param output Output buffer.
 @param numberOfSamples The number of samples to process.
 @param numChannels The number of channels. One sample may be 1 value (1 channels) or N values (N channels).
 */
//extern "C" void SuperpoweredSimple_SuperpoweredShortIntToFloat(short int input[], float output[], unsigned int numberOfSamples, unsigned int numChannels);

/**
 @fn SuperpoweredInterleave(float *left, float *right, float *output, unsigned int numberOfSamples);
 @brief Makes an interleaved output from two input channels.
 
 @param left Input for left channel.
 @param right Input for right channel.
 @param output Interleaved output.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredInterleave(float left[], float right[], float output[], unsigned int numberOfSamples);

/**
 @fn SuperpoweredInterleaveAdd(float *left, float *right, float *output, unsigned int numberOfSamples);
 @brief Makes an interleaved audio from two input channels and adds the result to the output.
 
 @param left Input for left channel.
 @param right Input for right channel.
 @param output Interleaved output.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredInterleaveAdd(float left[], float right[], float output[], unsigned int numberOfSamples);

/**
 @fn SuperpoweredInterleaveAndGetPeaks(float *left, float *right, float *output, unsigned int numberOfSamples, float *peaks);
 @brief Makes an interleaved output from two input channels, and measures the input volume.
 
 @param left Input for left channel.
 @param right Input for right channel.
 @param output Interleaved output.
 @param numberOfSamples The number of samples to process.
 @param peaks Peak value result (2 floats: left peak, right peak).
 */
extern "C" void SuperpoweredSimple_SuperpoweredInterleaveAndGetPeaks(float left[], float right[], float output[], unsigned int numberOfSamples, float peaks[]);

/**
 @fn SuperpoweredDeInterleave(float *input, float *left, float *right, unsigned int numberOfSamples);
 @brief Deinterleaves an interleaved input.
 
 @param input Interleaved input.
 @param left Output for left channel.
 @param right Output for right channel.
 
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredDeInterleave(float input[], float left[], float right[], unsigned int numberOfSamples);

/**
 @fn SuperpoweredDeInterleaveAdd(float *input, float *left, float *right, unsigned int numberOfSamples);
 @brief Deinterleaves an interleaved input and adds the results to the output channels.
 
 @param input Interleaved input.
 @param left Output for left channel.
 @param right Output for right channel.
 
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredDeInterleaveAdd(float input[], float left[], float right[], unsigned int numberOfSamples);

/**
 @fn SuperpoweredHasNonFinite(float *buffer, unsigned int numberOfValues);
 @brief Checks if the samples has non-valid samples, such as infinity or NaN (not a number).
 
 @param buffer The buffer to check.
 @param numberOfValues Number of values in buffer. For stereo buffers, multiply by two!
 */
extern "C" bool SuperpoweredSimple_SuperpoweredHasNonFinite(float buffer[], unsigned int numberOfValues);

/**
 @fn SuperpoweredStereoToMono(float *input, float *output, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);
 @brief Makes mono output from stereo input.
 
 @param input Stereo interleaved input.
 @param output Output.
 @param leftGainStart Gain of the first sample on the left channel.
 @param leftGainEnd Gain for the last sample on the left channel. Gain will be smoothly calculated between start end end.
 @param rightGainStart Gain of the first sample on the right channel.
 @param rightGainEnd Gain for the last sample on the right channel. Gain will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredStereoToMono(float input[], float output[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);

/**
 @fn SuperpoweredStereoToMono2(float *input, float *output0, float *output1, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);
 @brief Makes two mono outputs from stereo input.
 
 @param input Stereo interleaved input.
 @param output0 Output.
 @param output1 Output.
 @param leftGainStart Gain of the first sample on the left channel.
 @param leftGainEnd Gain for the last sample on the left channel. Gain will be smoothly calculated between start end end.
 @param rightGainStart Gain of the first sample on the right channel.
 @param rightGainEnd Gain for the last sample on the right channel. Gain will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredStereoToMono2(float input[], float output0[], float output1[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);

/**
 @fn SuperpoweredCrossMono(float *left, float *right, float *output, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);
 @brief Makes mono output from two separate input channels.
 
 @param left Input for left channel.
 @param right Input for right channel.
 @param output Output.
 @param leftGainStart Gain of the first sample on the left channel.
 @param leftGainEnd Gain for the last sample on the left channel. Gain will be smoothly calculated between start end end.
 @param rightGainStart Gain of the first sample on the right channel.
 @param rightGainEnd Gain for the last sample on the right channel. Gain will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredCrossMono(float left[], float right[], float output[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);

/**
 @fn SuperpoweredCrossMono2(float *left, float *right, float *output0, float *output1, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);
 @brief Makes two mono outputs from two separate input channels.
 
 @param left Input for left channel.
 @param right Input for right channel.
 @param output0 Output.
 @param output1 Output.
 @param leftGainStart Gain of the first sample on the left channel.
 @param leftGainEnd Gain for the last sample on the left channel. Gain will be smoothly calculated between start end end.
 @param rightGainStart Gain of the first sample on the right channel.
 @param rightGainEnd Gain for the last sample on the right channel. Gain will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredCrossMono2(float left[], float right[], float output0[], float output1[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples);

/**
 @fn SuperpoweredCrossStereo(float *inputA, float *inputB, float *output, float gainStart[4], float gainEnd[4], unsigned int numberOfSamples);
 @brief Crossfades two separate input channels.
 
 @param inputA Interleaved stereo input (first).
 @param inputB Interleaved stereo input (second).
 @param output Interleaved stereo output.
 @param gainStart Gain of the first sample (first left, first right, second left, second right).
 @param gainEnd Gain for the last sample (first left, first right, second left, second right). Gain will be smoothly calculated between start end end.
 @param numberOfSamples The number of samples to process.
 */
extern "C" void SuperpoweredSimple_SuperpoweredCrossStereo(float inputA[], float inputB[], float output[], float gainStart[4], float gainEnd[4], unsigned int numberOfSamples);

/**
 @fn SuperpoweredAdd1(float *input, float *output, unsigned int numberOfValues)
 @brief Adds input to output.
 
 @param input Input data.
 @param output Output data.
 @param numberOfValues The length of input.
 */
extern "C" void SuperpoweredSimple_SuperpoweredAdd1(float input[], float output[], unsigned int numberOfValues);

/**
 @fn SuperpoweredAdd2(float *inputA, float *inputB, float *output, unsigned int numberOfValues)
 @brief Adds two inputs to an output.
 
 @param inputA Input data.
 @param inputB Input data.
 @param output Output data.
 @param numberOfValues The length of input.
 */
extern "C" void SuperpoweredSimple_SuperpoweredAdd2(float inputA[], float inputB[], float output[], unsigned int numberOfValues);

/**
 @fn SuperpoweredAdd4(float *inputA, float *inputB, float *inputC, float *inputD, float *output, unsigned int numberOfValues)
 @brief Adds 4 inputs to an output.
 
 @param inputA Input data.
 @param inputB Input data.
 @param inputC Input data.
 @param inputD Input data.
 @param output Output data.
 @param numberOfValues The length of input.
 */
extern "C" void SuperpoweredSimple_SuperpoweredAdd4(float inputA[], float inputB[], float inputC[], float inputD[], float output[], unsigned int numberOfValues);


#endif /* defined(__SuperpoweredXCodeWrapper__SuperpoweredSimpleXCodeWrapper__) */
