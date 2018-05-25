//
//  SuperpoweredAdvancedAudioPlayerXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by mac on 5/24/18.
//  Copyright © 2018 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include "SuperpoweredAdvancedAudioPlayerXCodeWrapper.h"

extern "C" SuperpoweredAdvancedAudioPlayer* SuperpoweredAdvancedAudioPlayer_Create(void *clientData, SuperpoweredAdvancedAudioPlayerCallback callback, unsigned int sampleRate, unsigned char cachedPointCount, unsigned int internalBufferSizeSeconds, unsigned int negativeSeconds)
{
    try
    {
        return new SuperpoweredAdvancedAudioPlayer(clientData, callback, sampleRate, cachedPointCount, internalBufferSizeSeconds, negativeSeconds);
        
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer().\n");
        
        return nullptr;
    }
    
    return new SuperpoweredAdvancedAudioPlayer(clientData, callback, sampleRate, cachedPointCount, internalBufferSizeSeconds, negativeSeconds);
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Dispose(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            delete pObject;
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Dispose().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetTempFolder(SuperpoweredAdvancedAudioPlayer* pObject, const char *path)
{
    try
    {
        if( pObject != nullptr)
            pObject->setTempFolder(path);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetTempFolder().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_ClearTempFolder(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->clearTempFolder();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_ClearTempFolder().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Open1(SuperpoweredAdvancedAudioPlayer* pObject, const char *path, char **customHTTPHeaders)
{
    try
    {
        WriteErrorToSyslog( path );
        
        if( pObject != nullptr)
            pObject->open(path, customHTTPHeaders);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Open1().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Open(SuperpoweredAdvancedAudioPlayer* pObject, const char *path, int offset, int length, char **customHTTPHeaders)
{
    try
    {
        if( pObject != nullptr)
            pObject->open(path, offset, length, customHTTPHeaders);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Open().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_OpenHLS(SuperpoweredAdvancedAudioPlayer* pObject, const char *url, char **customHTTPHeaders)
{
    try
    {
        if( pObject != nullptr)
            pObject->openHLS(url, customHTTPHeaders);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_OpenHLS().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Play(SuperpoweredAdvancedAudioPlayer* pObject, bool synchronised)
{
    try
    {
        WriteErrorToSyslog( "In SuperpoweredAdvancedAudioPlayer_Play().\n");
        
        if( pObject != nullptr)
            pObject->play(synchronised);
        
        const char* isplaying = pObject->playing ? "true" : "false";
        
        WriteErrorToSyslog(isplaying);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Play().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Pause(SuperpoweredAdvancedAudioPlayer* pObject, float decelerateSeconds , unsigned int slipMs)
{
    try
    {
        if( pObject != nullptr)
            pObject->pause(decelerateSeconds, slipMs);
        
        const char* isplaying = pObject->playing ? "true" : "false";
        
        WriteErrorToSyslog(isplaying);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Pause().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_TogglePlayback(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->togglePlayback();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_TogglePlayback().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Seek(SuperpoweredAdvancedAudioPlayer* pObject, double percent)
{
    try
    {
        if( pObject != nullptr)
            pObject->seek(percent);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Seek().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetPosition(SuperpoweredAdvancedAudioPlayer* pObject, double ms, bool andStop, bool synchronisedStart, bool forceDefaultQuantum, bool preferWaitingforSynchronisedStart)
{
    try
    {
        if( pObject != nullptr)
            pObject->setPosition(ms, andStop, synchronisedStart, forceDefaultQuantum, preferWaitingforSynchronisedStart);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetPosition().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_CachePosition(SuperpoweredAdvancedAudioPlayer* pObject, double ms, unsigned char pointID)
{
    try
    {
        if( pObject != nullptr)
            pObject->cachePosition(ms, pointID);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_CachePosition().\n");
    }
}

extern "C" bool SuperpoweredAdvancedAudioPlayer_Loop(SuperpoweredAdvancedAudioPlayer* pObject, double startMs, double lengthMs, bool jumpToStartMs, unsigned char pointID, bool synchronisedStart, bool forceDefaultQuantum, bool preferWaitingforSynchronisedStart)
{
    try
    {
        if( pObject != nullptr)
            return pObject->loop(startMs, lengthMs, jumpToStartMs, pointID, synchronisedStart, forceDefaultQuantum, preferWaitingforSynchronisedStart);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Loop().\n");
        
        return nullptr;
    }
    
    return nullptr;
}

extern "C" bool SuperpoweredAdvancedAudioPlayer_LoopBetween(SuperpoweredAdvancedAudioPlayer* pObject, double startMs, double endMs, bool jumpToStartMs, unsigned char pointID, bool synchronisedStart, bool forceDefaultQuantum, bool preferWaitingforSynchronisedStart)
{
    try
    {
        if( pObject != nullptr)
            return pObject->loopBetween(startMs, endMs, jumpToStartMs, pointID, synchronisedStart, forceDefaultQuantum, preferWaitingforSynchronisedStart);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_LoopBetween().\n");
        
        return nullptr;
    }
    
    return nullptr;
}

extern "C" void SuperpoweredAdvancedAudioPlayer_ExitLoop(SuperpoweredAdvancedAudioPlayer* pObject, bool synchronisedStart)
{
    try
    {
        if( pObject != nullptr)
            pObject->exitLoop(synchronisedStart);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_ExitLoop().\n");
    }
}

extern "C" bool SuperpoweredAdvancedAudioPlayer_MsInLoop(SuperpoweredAdvancedAudioPlayer* pObject, double ms)
{
    try
    {
        if( pObject != nullptr)
            return pObject->msInLoop(ms);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_MsInLoop().\n");
        
        return nullptr;
    }
    
    return nullptr;
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetBpm(SuperpoweredAdvancedAudioPlayer* pObject, double newBpm)
{
    try
    {
        if( pObject != nullptr)
            pObject->setBpm(newBpm);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetBpm().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetFirstBeatMs(SuperpoweredAdvancedAudioPlayer* pObject, double ms)
{
    try
    {
        if( pObject != nullptr)
            pObject->setFirstBeatMs(ms);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetFirstBeatMs().\n");
    }
}

extern "C" double SuperpoweredAdvancedAudioPlayer_ClosestBeatMs(SuperpoweredAdvancedAudioPlayer* pObject, double ms, unsigned char *beatIndex)
{
    try
    {
        if( pObject != nullptr)
            return pObject->closestBeatMs(ms, beatIndex);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_ClosestBeatMs().\n");
        
        return 0;
    }
    
    return 0;
}

extern "C" void SuperpoweredAdvancedAudioPlayer_JogTouchBegin(SuperpoweredAdvancedAudioPlayer* pObject, int ticksPerTurn, SuperpoweredAdvancedAudioPlayerJogMode mode, unsigned int scratchSlipMs)
{
    try
    {
        if( pObject != nullptr)
            pObject->jogTouchBegin(ticksPerTurn, mode, scratchSlipMs);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_JogTouchBegin().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_JogTick(SuperpoweredAdvancedAudioPlayer* pObject, int value, bool bendStretch, float bendMaxPercent, unsigned int bendHoldMs, bool parameterMode)
{
    try
    {
        if( pObject != nullptr)
            pObject->jogTick(value, bendStretch, bendMaxPercent, bendHoldMs, parameterMode);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_JogTick().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_JogTouchEnd(SuperpoweredAdvancedAudioPlayer* pObject, float decelerate, bool synchronisedStart)
{
    try
    {
        if( pObject != nullptr)
            pObject->jogTouchEnd(decelerate, synchronisedStart);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_JogTouchEnd().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetTempo(SuperpoweredAdvancedAudioPlayer* pObject, double tempo, bool masterTempo)
{
    try
    {
        if( pObject != nullptr)
            pObject->setTempo(tempo, masterTempo);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetTempo().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetPitchShift(SuperpoweredAdvancedAudioPlayer* pObject, int pitchShift)
{
    try
    {
        if( pObject != nullptr)
            pObject->setPitchShift(pitchShift);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetPitchShift().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetPitchShiftCents(SuperpoweredAdvancedAudioPlayer* pObject, int pitchShiftCents)
{
    try
    {
        if( pObject != nullptr)
            pObject->setPitchShiftCents(pitchShiftCents);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetPitchShiftCents().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetReverse(SuperpoweredAdvancedAudioPlayer* pObject, bool reverse, unsigned int slipMs)
{
    try
    {
        if( pObject != nullptr)
            pObject->setReverse(reverse, slipMs);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetReverse().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_PitchBend(SuperpoweredAdvancedAudioPlayer* pObject, float maxPercent, bool bendStretch, bool faster, unsigned int holdMs)
{
    try
    {
        if( pObject != nullptr)
            pObject->pitchBend(maxPercent, bendStretch, faster, holdMs);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_PitchBend().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_EndContinuousPitchBend(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->endContinuousPitchBend();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_EndContinuousPitchBend().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_ResetBendMsOffset(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->resetBendMsOffset();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_ResetBendMsOffset().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_StartScratch(SuperpoweredAdvancedAudioPlayer* pObject, unsigned int slipMs, bool stopImmediately)
{
    try
    {
        if( pObject != nullptr)
            pObject->startScratch(slipMs, stopImmediately);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_StartScratch().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_Scratch(SuperpoweredAdvancedAudioPlayer* pObject, double pitch, float smoothing)
{
    try
    {
        if( pObject != nullptr)
            pObject->scratch(pitch, smoothing);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Scratch().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_EndScratch(SuperpoweredAdvancedAudioPlayer* pObject, bool returnToStateBeforeScratch)
{
    try
    {
        if( pObject != nullptr)
            pObject->endScratch(returnToStateBeforeScratch);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_EndScratch().\n");
    }
}

extern "C" double SuperpoweredAdvancedAudioPlayer_LastProcessMs(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            return pObject->lastProcessMs();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_LastProcessMs().\n");
        
        return 0;
    }
    
    return 0;
}

extern "C" void SuperpoweredAdvancedAudioPlayer_SetSamplerate(SuperpoweredAdvancedAudioPlayer* pObject, unsigned int sampleRate)
{
    try
    {
        if( pObject != nullptr)
            pObject->setSamplerate(sampleRate);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_SetSamplerate().\n");
    }
}

extern "C" void SuperpoweredAdvancedAudioPlayer_OnMediaserverInterrupt(SuperpoweredAdvancedAudioPlayer* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->onMediaserverInterrupt();
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_OnMediaserverInterrupt().\n");
    }
}

extern "C" double SuperpoweredAdvancedAudioPlayer_GetMsDifference(SuperpoweredAdvancedAudioPlayer* pObject, double phase, double quantum)
{
    try
    {
        if( pObject != nullptr)
            return pObject->getMsDifference(phase, quantum);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_GetMsDifference().\n");
        
        return 0;
    }
    
    return 0;
}

extern "C" bool SuperpoweredAdvancedAudioPlayer_Process(SuperpoweredAdvancedAudioPlayer* pObject, float *buffer, bool bufferAdd, unsigned int numberOfSamples, float volume, double masterBpm, double masterMsElapsedSinceLastBeat, double phase, double quantum)
{
    try
    {
        if( pObject != nullptr)
            return pObject->process(buffer, bufferAdd, numberOfSamples, volume, masterBpm, masterMsElapsedSinceLastBeat, phase, quantum);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_Process().\n");
        
        return nullptr;
    }
    
    return nullptr;
}

extern "C" bool SuperpoweredAdvancedAudioPlayer_ProcessMulti(SuperpoweredAdvancedAudioPlayer* pObject, float **buffers, bool *bufferAdds, unsigned int numberOfSamples, float *volumes, double masterBpm, double masterMsElapsedSinceLastBeat, double phase, double quantum)
{
    try
    {
        if( pObject != nullptr)
            return pObject->processMulti(buffers, bufferAdds, numberOfSamples, volumes, masterBpm, masterMsElapsedSinceLastBeat, phase, quantum);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredAdvancedAudioPlayer_ProcessMulti().\n");
        
        return nullptr;
    }
    
    return nullptr;
}

