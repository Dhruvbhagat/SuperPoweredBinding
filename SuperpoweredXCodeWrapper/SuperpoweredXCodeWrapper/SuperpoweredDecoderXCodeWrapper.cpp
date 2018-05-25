//
//  SuperpoweredDecoderXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Rodrique Fru on 10/15/17.
//  Copyright © 2017 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include "SuperpoweredDecoderXCodeWrapper.h"

extern "C" SuperpoweredDecoder* SuperpoweredDecoder_Create(SuperpoweredDecoderFullyDownloadedCallback downloadedCallback = 0, void *clientData = 0)
{
    try
    {
        return new SuperpoweredDecoder(downloadedCallback, clientData);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
        
        return nullptr;
    }
    
    return new SuperpoweredDecoder(downloadedCallback, clientData);
}

extern "C" const char *SuperpoweredDecoder_Open(SuperpoweredDecoder* pObject, const char path[], bool metaOnly, int offset, int length, int stemsIndex, char **customHTTPHeaders)
{
    try
    {
        if( pObject != nullptr)
            return pObject->open(path, metaOnly, offset, length, stemsIndex, customHTTPHeaders);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
        
        return nullptr;
    }
    
    return nullptr;
}

extern "C" unsigned char SuperpoweredDecoder_Decode(SuperpoweredDecoder* pObject, short int pcmOutput[], unsigned int samples[])
{
    try
    {
        if( pObject != nullptr)
            return pObject->decode(pcmOutput, samples);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
        
        return 0;
    }
    
    return 0;
}

extern "C" unsigned char SuperpoweredDecoder_Seek(SuperpoweredDecoder* pObject, int64_t sample, bool precise)
{
    try
    {
        if( pObject != nullptr)
            return pObject->seek(sample, precise);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
        
        return 0;
    }
    
    return 0;
}

extern "C" unsigned char SuperpoweredDecoder_GetAudioStartSample(SuperpoweredDecoder* pObject, unsigned int startSample[], unsigned int limitSamples, int decibel)
{
    try
    {
        if( pObject != nullptr)
            return pObject->getAudioStartSample(startSample, limitSamples, decibel);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
        
        return 0;
    }
    
    return 0;
}

extern "C" void SuperpoweredDecoder_ReconnectToMediaserver(SuperpoweredDecoder* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->reconnectToMediaserver();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
    }
}

extern "C" void SuperpoweredDecoder_GetMetaData(SuperpoweredDecoder* pObject, char **artist, char **title, void **image, int *imageSizeBytes, float *bpm, SuperpoweredDecoderID3Callback callback, void *clientData, int maxFrameDataSize)
{
    try
    {
        if( pObject != nullptr)
            pObject->getMetaData(artist, title, image, imageSizeBytes, bpm, callback, clientData, maxFrameDataSize);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
    }
}

extern "C" bool SuperpoweredDecoder_GetStemsInfo(SuperpoweredDecoder* pObject, char *names[4], char *colors[4], stemsCompressor *compressor, stemsLimiter *limiter)
{
    try
    {
        if( pObject != nullptr)
            pObject->getStemsInfo(names, colors, compressor, limiter);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
        
        return  nullptr;
    }
    
    return false;
}

extern "C" void SuperpoweredDecoder_Dispose(SuperpoweredDecoder* pObject)
{
    try
    {
        if( pObject != nullptr)
            delete pObject;
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredDecoder().\n");
    }
}


