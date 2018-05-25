//
//  SuperpoweredFilterXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Rodrique Fru on 10/14/17.
//  Copyright © 2017 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include "SuperpoweredFilterXCodeWrapper.h"

extern "C" SuperpoweredFilter* SuperpoweredFilter_Create(SuperpoweredFilterType filterType, unsigned int samplerate)
{
    try
    {
        return new SuperpoweredFilter(filterType, samplerate);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter().\n");
        
        return nullptr;
    }
    
    
    return new SuperpoweredFilter(filterType, samplerate);
}

extern "C" void SuperpoweredFilter_Dispose( SuperpoweredFilter* pObject)
{
    try
    {
        if( pObject != nullptr )
            delete pObject;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code DisposeSuperpoweredFilterClass().\n" );
    }
}

/**
 @brief Change parameters for resonant filters.
 
 @param frequency The frequency in Hz.
 @param resonance Resonance value.
 */
extern "C" void SuperpoweredFilter_SetResonantParameters(SuperpoweredFilter *pObject, float frequency, float resonance)
{
    try
    {
        if( pObject != nullptr)
            pObject->setResonantParameters(frequency, resonance);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetResonantParameters().\n" );
    }
    
    return;
}
/**
 @brief Change parameters for shelving filters.
 
 @param frequency The frequency in Hz.
 @param slope Slope.
 @param dbGain Gain in decibel.
 */
extern "C" void SuperpoweredFilter_SetShelfParameters(SuperpoweredFilter *pObject, float frequency, float slope, float dbGain)
{
    try
    {
        if( pObject != nullptr)
            pObject->setShelfParameters(frequency, slope, dbGain);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetShelfParameters().\n" );
    }
    
    return;
}
/**
 @brief Change parameters for bandlimited filters.
 
 @param frequency The center frequency in Hz.
 @param octaveWidth Width in octave.
 */
extern "C" void SuperpoweredFilter_SetBandlimitedParameters(SuperpoweredFilter *pObject, float frequency, float octaveWidth)
{
    try
    {
        if( pObject != nullptr)
            pObject->setBandlimitedParameters(frequency, octaveWidth);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetBandlimitedParameters().\n" );
    }
    
    return;
}
/**
 @brief Change parameters for parametric filters.
 
 @param frequency The center frequency in Hz.
 @param octaveWidth Width in octave.
 @param dbGain Gain in decibel.
 */
extern "C" void SuperpoweredFilter_SetParametricParameters(SuperpoweredFilter *pObject, float frequency, float octaveWidth, float dbGain)
{
    try
    {
        if( pObject != nullptr)
            pObject->setParametricParameters(frequency, octaveWidth, dbGain);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetParametricParameters().\n" );
    }
    
    return;
}

/**
 @brief Set params and type at once for resonant filters.
 
 @param frequency The frequency in Hz.
 @param resonance Resonance value.
 @param type Must be lowpass or highpass.
 */
extern "C" void SuperpoweredFilter_SetResonantParametersAndType(SuperpoweredFilter *pObject, float frequency, float resonance, SuperpoweredFilterType type)
{
    try
    {
        if( pObject != nullptr)
            pObject->setResonantParametersAndType(frequency, resonance, type);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetResonantParametersAndType().\n" );
    }
    
    return;
}
/**
 @brief Set params and type at once for shelving filters.
 
 @param frequency The frequency in Hz.
 @param slope Slope.
 @param dbGain Gain in decibel.
 @param type Must be low shelf or high shelf.
 */
extern "C" void SuperpoweredFilter_SetShelfParametersAndType(SuperpoweredFilter *pObject, float frequency, float slope, float dbGain, SuperpoweredFilterType type)
{
    try
    {
        if( pObject != nullptr)
            pObject->setShelfParametersAndType(frequency, slope, dbGain, type);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetShelfParametersAndType().\n" );
    }
    
    return;
}

/**
 @brief Set params and type at once for bandlimited filters.
 
 @param frequency The center frequency in Hz.
 @param octaveWidth Width in octave.
 @param type Must be bandpass or notch.
 */
extern "C" void SuperpoweredFilter_SetBandlimitedParametersAndType(SuperpoweredFilter *pObject, float frequency, float octaveWidth, SuperpoweredFilterType type)
{
    try
    {
        if( pObject != nullptr)
            pObject->setBandlimitedParametersAndType(frequency, octaveWidth, type);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetBandlimitedParametersAndType().\n" );
    }
    
    return;
}

/**
 @brief Set custom coefficients for the filter.
 
 Coefficient changes will be smoothly handled.
 
 @param coefficients Pointer to the 5 coefficients of the first direct form IIR filter.
 */
extern "C" void SuperpoweredFilter_SetCustomCoefficients(SuperpoweredFilter *pObject, float coefficients[])
{
    try
    {
        if( pObject != nullptr)
            pObject->setCustomCoefficients(coefficients);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetCustomCoefficients().\n" );
    }
    
    return;
}

/**
 @brief Turns the effect on/off.
 */
extern "C" void SuperpoweredFilter_Enable(SuperpoweredFilter *pObject, bool flag) // Use this to turn it on/off.
{
    try
    {
        if( pObject != nullptr)
            pObject->enable(flag);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_Enable().\n" );
    }
    
    return;
}

/**
 @brief Sets the sample rate.
 
 @param samplerate 44100, 48000, etc.
 */
extern "C" void SuperpoweredFilter_SetSamplerate(SuperpoweredFilter *pObject, unsigned int samplerate)
{
    try
    {
        if( pObject != nullptr)
            pObject->setSamplerate(samplerate);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetSamplerate().\n" );
    }
    
    return;
}
/**
 @brief Reset all internals, sets the instance as good as new and turns it off.
 */
extern "C" void SuperpoweredFilter_Reset(SuperpoweredFilter *pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->reset();
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_SetSamplerate().\n" );
    }
    
    return;
}

/**
 @brief Processes interleaved audio.
 
 @return Put something into output or not.
 
 @param input 32-bit interleaved stereo input buffer. Can point to the same location with output (in-place processing).
 @param output 32-bit interleaved stereo output buffer. Can point to the same location with input (in-place processing).
 @param numberOfSamples Should be 32 minimum and exactly divisible with 8.
 */
extern "C" bool SuperpoweredFilter_Process(SuperpoweredFilter *pObject, float input[], float output[], unsigned int numberOfSamples)
{
    try
    {
        if( pObject != nullptr)
            return pObject->process(input, output, numberOfSamples);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_Process().\n" );
    }
    
    return false;
}

/**
 @brief Processes mono audio.
 
 @return Put something into output or not.
 
 @param input 32-bit input buffer. Can point to the same location with output (in-place processing).
 @param output 32-bit output buffer. Can point to the same location with input (in-place processing).
 @param numberOfSamples Should be 32 minimum and exactly divisible with 8.
 */
extern "C" bool SuperpoweredFilter_ProcessMono(SuperpoweredFilter *pObject, float input[], float output[], unsigned int numberOfSamples)
{
    try
    {
        if( pObject != nullptr)
            return pObject->processMono(input, output, numberOfSamples);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredFilter_ProcessMono().\n" );
    }
    
    return false;
}


