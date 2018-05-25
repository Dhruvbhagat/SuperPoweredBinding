using System;
using System.Runtime.InteropServices;
using static SuperpoweredSDKXamarinWrapper.Constants;

namespace SuperpoweredSDKXamarinWrapper
{
    public static class SuperpoweredAdvancedAudioPlayerWrapper
    {
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void SuperpoweredAdvancedAudioPlayerCallback(IntPtr clientData, SuperpoweredAdvancedAudioPlayerEvent event1, IntPtr value1);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Create")]
        public static extern IntPtr Create(IntPtr clientData, SuperpoweredAdvancedAudioPlayerCallback callback, uint sampleRate, byte cachedPointCount, uint internalBufferSizeSeconds = 2, uint negativeSeconds = 0);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Dispose")]
        public static extern void Dispose(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetTempFolder")]
        public static extern void SetTempFolder(IntPtr pObject, char[] path);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_ClearTempFolder")]
        public static extern void ClearTempFolder(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Open1")]
        public static extern void Open1(IntPtr pObject, string path, char[] customHTTPHeaders = null);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Open")]
        public static extern void Open(IntPtr pObject, string path, int offset, int length, char[] customHTTPHeaders);
        //public static extern void Open(IntPtr pObject, char[] path, int offset, int length, char[] customHTTPHeaders);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_OpenHLS")]
        public static extern void OpenHLS(IntPtr pObject, string url, char[] customHTTPHeaders);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Play")]
        public static extern void Play(IntPtr pObject, bool synchronised);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Pause")]
        public static extern void Pause(IntPtr pObject, float decelerateSeconds = 0, uint slipMs = 0);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_TogglePlayback")]
        public static extern void TogglePlayback(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Seek")]
        public static extern void Seek(IntPtr pObject, double percent);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetPosition")]
        public static extern void SetPosition(IntPtr pObject, double ms, bool andStop, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_CachePosition")]
        public static extern void CachePosition(IntPtr pObject, double ms, byte pointID);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Loop")]
        public static extern bool Loop(IntPtr pObject, double startMs, double lengthMs, bool jumpToStartMs, byte pointID, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_LoopBetween")]
        public static extern bool LoopBetween(IntPtr pObject, double startMs, double endMs, bool jumpToStartMs, byte pointID, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_ExitLoop")]
        public static extern void ExitLoop(IntPtr pObject, bool synchronisedStart = false);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_MsInLoop")]
        public static extern bool MsInLoop(IntPtr pObject, double ms);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetBpm")]
        public static extern void SetBpm(IntPtr pObject, double newBpm);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetFirstBeatMs")]
        public static extern void SetFirstBeatMs(IntPtr pObject, double ms);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_ClosestBeatMs")]
        public static extern double ClosestBeatMs(IntPtr pObject, double ms, byte[] beatIndex);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_JogTouchBegin")]
        public static extern void JogTouchBegin(IntPtr pObject, int ticksPerTurn, SuperpoweredAdvancedAudioPlayerJogMode mode, uint scratchSlipMs);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_JogTick")]
        public static extern void JogTick(IntPtr pObject, int value, bool bendStretch, float bendMaxPercent, uint bendHoldMs, bool parameterMode);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_JogTouchEnd")]
        public static extern void JogTouchEnd(IntPtr pObject, float decelerate, bool synchronisedStart);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetTempo")]
        public static extern void SetTempo(IntPtr pObject, double tempo, bool masterTempo);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetPitchShift")]
        public static extern void SetPitchShift(IntPtr pObject, int pitchShift);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetPitchShiftCents")]
        public static extern void SetPitchShiftCents(IntPtr pObject, int pitchShiftCents);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetReverse")]
        public static extern void SetReverse(IntPtr pObject, bool reverse, uint slipMs);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_PitchBend")]
        public static extern void PitchBend(IntPtr pObject, float maxPercent, bool bendStretch, bool faster, uint holdMs);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_EndContinuousPitchBend")]
        public static extern void EndContinuousPitchBend(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_ResetBendMsOffset")]
        public static extern void ResetBendMsOffset(IntPtr pObject); 

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_StartScratch")]
        public static extern void StartScratch(IntPtr pObject, uint slipMs, bool stopImmediately);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Scratch")]
        public static extern void Scratch(IntPtr pObject, double pitch, float smoothing); 

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_EndScratch")]
        public static extern void EndScratch(IntPtr pObject, bool returnToStateBeforeScratch);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_LastProcessMs")]
        public static extern double LastProcessMs(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_SetSamplerate")]
        public static extern void SetSamplerate(IntPtr pObject, uint sampleRate);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_OnMediaserverInterrupt")]
        public static extern void OnMediaserverInterrupt(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_GetMsDifference")]
        public static extern double GetMsDifference(IntPtr pObject, double phase, double quantum);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_Process")]
        public static extern bool Process(IntPtr pObject, float[] buffer, bool bufferAdd, uint numberOfSamples, float volume = 1.0f, double masterBpm = 0.0f, double masterMsElapsedSinceLastBeat = -1.0, double phase = -1.0, double quantum = -1.0);

        [DllImport("__Internal", EntryPoint = "SuperpoweredAdvancedAudioPlayer_ProcessMulti")]
        public static extern bool ProcessMulti(IntPtr pObject, float[] buffers, bool[] bufferAdds, uint numberOfSamples, float[] volumes, double masterBpm = 0.0f, double masterMsElapsedSinceLastBeat = -1.0, double phase = -1.0, double quantum = -1.0);
    }
}
