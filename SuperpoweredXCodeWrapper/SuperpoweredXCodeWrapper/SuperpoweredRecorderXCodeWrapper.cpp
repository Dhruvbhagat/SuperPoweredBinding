//
//  SuperpoweredRecorderXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Rodrique Fru on 10/15/17.
//  Copyright © 2017 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include "SuperpoweredRecorderXCodeWrapper.h"

/**
 @brief Creates a recorder instance.
 
 @warning Filesystem paths in C are different than paths in Java. /sdcard becomes /mnt/sdcard for example.
 
 @param tempPath The full filesystem path of a temporarily file.
 @param samplerate The current samplerate.
 @param minSeconds The minimum length of a recording. If the number of recorded seconds is lower, then a file will not be saved.
 @param numChannels The number of channels.
 @param applyFade If true, the recorder applies a  fade-in at the beginning and a fade-out at the end of the recording. The fade is 64 samples long.
 @param callback Called when the recorder finishes writing after stop().
 @param clientData A custom pointer your callback receives.
 */
extern "C" SuperpoweredRecorder* SuperpoweredRecorder_Create(const char tempPath[], unsigned int samplerate, unsigned int minSeconds, unsigned char numChannels, bool applyFade, SuperpoweredRecorderStoppedCallback callback, void *clientData)
{
    try
    {
        return new SuperpoweredRecorder(tempPath, samplerate, minSeconds, numChannels, applyFade, callback, clientData);
    }
    catch( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder().\n");
        
        return nullptr;
    }
    
    
    return new SuperpoweredRecorder(tempPath, samplerate, minSeconds, numChannels, applyFade, callback, clientData);
}

extern "C" void SuperpoweredRecorder_Dispose(SuperpoweredRecorder* pObject)
{
    try
    {
        if( pObject != nullptr )
            delete pObject;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code DisposeSuperpoweredRecorderClass().\n" );
    }
}
/**
 @brief Starts recording.
 @return False, if another recording is still active or not closed yet.
 
 @param destinationPath The full filesystem path of the successfully finished recording.
 */
extern "C" bool SuperpoweredRecorder_Start(SuperpoweredRecorder* pObject, const char destinationPath[])
{
    try
    {
        if( pObject != nullptr)
            return pObject->start(destinationPath);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder_Start().\n" );
    }
    
    return false;
}
/**
 @brief Stops recording.
 */
extern "C" void SuperpoweredRecorder_Stop(SuperpoweredRecorder* pObject)
{
    try
    {
        if( pObject != nullptr)
            pObject->stop();
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder_Stop().\n" );
    }
    
    return;
}
/**
 @brief Adds an artist + title to the tracklist.
 
 The tracklist is a .txt file placed next to the audio file, if at least one track has been added to it.
 
 @param artist Artist, can be NULL.
 @param title Title, can be NULL.
 @param offsetSeconds When the track began to be audible in this recording, relative to the current time. For example, 0 means "now", -10 means "10 seconds ago".
 @param takeOwnership If true, this class will free artist and title.
 */
extern "C" void SuperpoweredRecorder_AddToTracklist(SuperpoweredRecorder* pObject, char artist[], char title[], int offsetSeconds, bool takeOwnership)
{
    try
    {
        if( pObject != nullptr)
            pObject->addToTracklist(artist, title, offsetSeconds, takeOwnership);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder_AddToTracklist().\n" );
    }
    
    return;
}
/**
 @brief Sets the sample rate.
 
 @param samplerate 44100, 48000, etc.
 */
extern "C" void SuperpoweredRecorder_SetSamplerate(SuperpoweredRecorder* pObject, unsigned int samplerate)
{
    try
    {
        if( pObject != nullptr)
            pObject->setSamplerate(samplerate);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder_SetSamplerate().\n" );
    }
    
    return;
}

/**
 @brief Processes stereo incoming audio.
 
 Special case: set both input0 and input1 to NULL if there is nothing to record yet. You can cut initial silence this way.
 
 @return Seconds recorded so far.
 
 @param input0 Left input channel or stereo interleaved input.
 @param input1 Right input channel. If NULL, input0 is a stereo interleaved input.
 @param numberOfSamples The number of samples in input. Should be 8 minimum.
 */
extern "C" unsigned int SuperpoweredRecorder_Process(SuperpoweredRecorder* pObject, float input0[], float input1[], unsigned int numberOfSamples)
{
    try
    {
        if( pObject != nullptr)
            return pObject->process(input0, input1, numberOfSamples);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder_Process().\n" );
    }
    
    return 0;
}

/**
 @brief Processes incoming interleaved audio.
 
 Special case: set input to NULL if there is nothing to record yet. You can cut initial silence this way.
 
 @return Seconds recorded so far.
 
 @param input Interleaved audio to record.
 @param numberOfSamples The number of samples in input. Should be 8 minimum.
 */
extern "C" unsigned int SuperpoweredRecorder_Process2(SuperpoweredRecorder* pObject, float input[], unsigned int numberOfSamples)
{
    try
    {
        if( pObject != nullptr)
            return pObject->process(input, numberOfSamples);
    }
    catch (...) // You cannot allow an exception to propagate from unmanaged code into managed code.
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredRecorder_Process().\n" );
    }
    
    return 0;
}
