//
//  SuperpoweredXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Bryon on 6/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//
#include "SuperpoweredWrapperUtilities.h"
#include "SuperpoweredBandpassFilterbankXCodeWrapper.h"

//
// Local function prototyes.
//
extern "C" SuperpoweredBandpassFilterbank* SuperpoweredBandpassFilterbank_Create(int numBands, float frequencies[], float widths[], unsigned int samplerate)
{
    try
    {
        return new SuperpoweredBandpassFilterbank( numBands, frequencies, widths, samplerate );
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredBandpassFilterbank().\n");
        
        return nullptr;
    }
    
    
    return new SuperpoweredBandpassFilterbank( numBands, frequencies, widths, samplerate );
}

extern "C" void SuperpoweredBandpassFilterbank_Dispose( SuperpoweredBandpassFilterbank* pObject)
{
    try
    {
        if( pObject != nullptr )
            delete pObject;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.

    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code DisposeSuperpoweredBandpassFilterbankClass().\n" );
    }
}

extern "C" void SuperpoweredBandpassFilterbank_SetSamplerate( SuperpoweredBandpassFilterbank *pObject, unsigned int sampleRate )
{
    try
    {
        if( pObject != nullptr)
            pObject->setSamplerate( sampleRate);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SetSampleRate().\n" );
    }
    
    return;
}

extern "C" void SuperpoweredBandpassFilterbank_Process(SuperpoweredBandpassFilterbank *pObject, float input[], float bands[], float *peak, float *sum, unsigned int numberOfSamples, int group)
{
     try
    {
        if( pObject != nullptr)
            pObject->process(input, bands, peak, sum, numberOfSamples, group);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Process().\n" );
    }
    
    return;
    
}

extern "C" void SuperpoweredBandpassFilterbank_ProcessNoAdd(SuperpoweredBandpassFilterbank *pObject, float input[], float bands[], float *peak, float *sum, unsigned int numberOfSamples, int group)
{
    try
    {
        if( pObject != nullptr)
            pObject->processNoAdd(input, bands, peak, sum, numberOfSamples, group);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Process().\n" );
    }
    
    return;
    
}
