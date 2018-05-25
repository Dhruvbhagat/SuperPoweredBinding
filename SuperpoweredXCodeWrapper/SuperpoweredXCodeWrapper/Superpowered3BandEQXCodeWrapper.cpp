//
//  SuperpoweredFXXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Administrator on 5/15/18.
//  Copyright © 2018 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include "Superpowered3BandEQXCodeWrapper.h"

extern "C" Superpowered3BandEQ* Superpowered3BandEQ_Create(unsigned int samplerate)
{
    try
    {
        return new Superpowered3BandEQ(samplerate);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Superpowered3BandEQ().\n");
        
        return nullptr;
    }
    
    return new Superpowered3BandEQ(samplerate);
}

extern "C" void Superpowered3BandEQ_Enable(Superpowered3BandEQ* pObject, bool flag)
{
    try
    {
        if( pObject != nullptr)
            pObject->enable(flag);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Superpowered3BandEQ().\n");
    }
}

extern "C" void Superpowered3BandEQ_Reset(Superpowered3BandEQ* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->reset();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Superpowered3BandEQ().\n");
    }
}

extern "C" bool Superpowered3BandEQ_Process(Superpowered3BandEQ* pObject, float *input, float *output, unsigned int numberOfSamples)
{
    try
    {
        if( pObject != nullptr)
            return pObject->process(input, output, numberOfSamples);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Superpowered3BandEQ().\n");
        
        return nullptr;
    }
    
    return false;
}

extern "C" void Superpowered3BandEQ_Dispose(Superpowered3BandEQ* pObject)
{
    try
    {
        if( pObject != nullptr)
            delete pObject;
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code Superpowered3BandEQ().\n");
    }
}
