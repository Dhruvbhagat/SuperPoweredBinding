//
//  SuperpoweredAdvancedAudioPlayerXCodeWrapper.h
//  SuperpoweredXCodeWrapper
//
//  Created by mac on 5/24/18.
//  Copyright © 2018 Bryon Baker. All rights reserved.
//

#ifndef SuperpoweredAdvancedAudioPlayerXCodeWrapper_h
#define SuperpoweredAdvancedAudioPlayerXCodeWrapper_h

#include <stdio.h>
#include "SuperpoweredAdvancedAudioPlayer.h"

extern "C"  SuperpoweredAdvancedAudioPlayer* SuperpoweredAdvancedAudioPlayer_Create(void *clientData, SuperpoweredAdvancedAudioPlayerCallback callback, unsigned int sampleRate, unsigned char cachedPointCount, unsigned int internalBufferSizeSeconds = 2, unsigned int negativeSeconds = 0);

extern "C" void SuperpoweredAdvancedAudioPlayer_Dispose(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetTempFolder(SuperpoweredAdvancedAudioPlayer* pObject, const char *path);

extern "C" void SuperpoweredAdvancedAudioPlayer_ClearTempFolder(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" void SuperpoweredAdvancedAudioPlayer_Open1(SuperpoweredAdvancedAudioPlayer* pObject, const char *path, char **customHTTPHeaders = 0);

extern "C" void SuperpoweredAdvancedAudioPlayer_Open(SuperpoweredAdvancedAudioPlayer* pObject, const char *path, int offset, int length, char **customHTTPHeaders = 0);

extern "C" void SuperpoweredAdvancedAudioPlayer_OpenHLS(SuperpoweredAdvancedAudioPlayer* pObject, const char *url, char **customHTTPHeaders = 0);

extern "C" void SuperpoweredAdvancedAudioPlayer_Play(SuperpoweredAdvancedAudioPlayer* pObject, bool synchronised);

extern "C" void SuperpoweredAdvancedAudioPlayer_Pause(SuperpoweredAdvancedAudioPlayer* pObject, float decelerateSeconds = 0, unsigned int slipMs = 0);

extern "C" void SuperpoweredAdvancedAudioPlayer_TogglePlayback(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" void SuperpoweredAdvancedAudioPlayer_Seek(SuperpoweredAdvancedAudioPlayer* pObject, double percent);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetPosition(SuperpoweredAdvancedAudioPlayer* pObject, double ms, bool andStop, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false);

extern "C" void SuperpoweredAdvancedAudioPlayer_CachePosition(SuperpoweredAdvancedAudioPlayer* pObject, double ms, unsigned char pointID);

extern "C" bool SuperpoweredAdvancedAudioPlayer_Loop(SuperpoweredAdvancedAudioPlayer* pObject, double startMs, double lengthMs, bool jumpToStartMs, unsigned char pointID, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false);

extern "C" bool SuperpoweredAdvancedAudioPlayer_LoopBetween(SuperpoweredAdvancedAudioPlayer* pObject, double startMs, double endMs, bool jumpToStartMs, unsigned char pointID, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false);

extern "C" void SuperpoweredAdvancedAudioPlayer_ExitLoop(SuperpoweredAdvancedAudioPlayer* pObject, bool synchronisedStart = false);

extern "C" bool SuperpoweredAdvancedAudioPlayer_MsInLoop(SuperpoweredAdvancedAudioPlayer* pObject, double ms);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetBpm(SuperpoweredAdvancedAudioPlayer* pObject, double newBpm);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetFirstBeatMs(SuperpoweredAdvancedAudioPlayer* pObject, double ms);

extern "C" double SuperpoweredAdvancedAudioPlayer_ClosestBeatMs(SuperpoweredAdvancedAudioPlayer* pObject, double ms, unsigned char *beatIndex);

extern "C" void SuperpoweredAdvancedAudioPlayer_JogTouchBegin(SuperpoweredAdvancedAudioPlayer* pObject, int ticksPerTurn, SuperpoweredAdvancedAudioPlayerJogMode mode, unsigned int scratchSlipMs);

extern "C" void SuperpoweredAdvancedAudioPlayer_JogTick(SuperpoweredAdvancedAudioPlayer* pObject, int value, bool bendStretch, float bendMaxPercent, unsigned int bendHoldMs, bool parameterMode);

extern "C" void SuperpoweredAdvancedAudioPlayer_JogTouchEnd(SuperpoweredAdvancedAudioPlayer* pObject, float decelerate, bool synchronisedStart);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetTempo(SuperpoweredAdvancedAudioPlayer* pObject, double tempo, bool masterTempo);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetPitchShift(SuperpoweredAdvancedAudioPlayer* pObject, int pitchShift);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetPitchShiftCents(SuperpoweredAdvancedAudioPlayer* pObject, int pitchShiftCents);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetReverse(SuperpoweredAdvancedAudioPlayer* pObject, bool reverse, unsigned int slipMs);

extern "C" void SuperpoweredAdvancedAudioPlayer_PitchBend(SuperpoweredAdvancedAudioPlayer* pObject, float maxPercent, bool bendStretch, bool faster, unsigned int holdMs);

extern "C" void SuperpoweredAdvancedAudioPlayer_EndContinuousPitchBend(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" void SuperpoweredAdvancedAudioPlayer_ResetBendMsOffset(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" void SuperpoweredAdvancedAudioPlayer_StartScratch(SuperpoweredAdvancedAudioPlayer* pObject, unsigned int slipMs, bool stopImmediately);

extern "C" void SuperpoweredAdvancedAudioPlayer_Scratch(SuperpoweredAdvancedAudioPlayer* pObject, double pitch, float smoothing);

extern "C" void SuperpoweredAdvancedAudioPlayer_EndScratch(SuperpoweredAdvancedAudioPlayer* pObject, bool returnToStateBeforeScratch);

extern "C" double SuperpoweredAdvancedAudioPlayer_LastProcessMs(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" void SuperpoweredAdvancedAudioPlayer_SetSamplerate(SuperpoweredAdvancedAudioPlayer* pObject, unsigned int sampleRate);

extern "C" void SuperpoweredAdvancedAudioPlayer_OnMediaserverInterrupt(SuperpoweredAdvancedAudioPlayer* pObject);

extern "C" double SuperpoweredAdvancedAudioPlayer_GetMsDifference(SuperpoweredAdvancedAudioPlayer* pObject, double phase, double quantum);

extern "C" bool SuperpoweredAdvancedAudioPlayer_Process(SuperpoweredAdvancedAudioPlayer* pObject, float *buffer, bool bufferAdd, unsigned int numberOfSamples, float volume = 1.0f, double masterBpm = 0.0f, double masterMsElapsedSinceLastBeat = -1.0, double phase = -1.0, double quantum = -1.0);

extern "C" bool SuperpoweredAdvancedAudioPlayer_ProcessMulti(SuperpoweredAdvancedAudioPlayer* pObject, float **buffers, bool *bufferAdds, unsigned int numberOfSamples, float *volumes, double masterBpm = 0.0f, double masterMsElapsedSinceLastBeat = -1.0, double phase = -1.0, double quantum = -1.0);

#endif /* SuperpoweredAdvancedAudioPlayerXCodeWrapper_h */
