using System;
using ObjCRuntime;
using static SuperpoweredSDKXamarinWrapper.Constants;
using static SuperpoweredSDKXamarinWrapper.SuperpoweredAdvancedAudioPlayerWrapper;

namespace SuperpoweredSDKXamarinWrapper
{
    public class SuperpoweredAdvancedAudioPlayer
    {
        private IntPtr pObject;

        public SuperpoweredAdvancedAudioPlayer(IntPtr clientData, SuperpoweredAdvancedAudioPlayerCallback callback, uint sampleRate, byte cachedPointCount, uint internalBufferSizeSeconds = 2, uint negativeSeconds = 0)
        {
            pObject = SuperpoweredAdvancedAudioPlayerWrapper.Create(clientData, callback, sampleRate, cachedPointCount, internalBufferSizeSeconds, negativeSeconds);
            return;
        }

        ~SuperpoweredAdvancedAudioPlayer()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.Dispose(pObject);
                pObject = IntPtr.Zero;
            }
        }

        public void SetTempFolder(char[] path)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetTempFolder(pObject, path);
            }
        }

        public void ClearTempFolder()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.ClearTempFolder(pObject);
            }
        }

        public void Open1(string path, char[] customHTTPHeaders = null)
        {
			if (pObject != IntPtr.Zero)
			{
				SuperpoweredAdvancedAudioPlayerWrapper.Open1(pObject, path, customHTTPHeaders);
			}
        }

        //public void Open(char[] path, int offset, int length, char[] customHTTPHeaders)
        public void Open(string path, int offset, int length, char[] customHTTPHeaders)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.Open(pObject, path, offset, length, customHTTPHeaders);
            }
        }

        public void OpenHLS(string url, char[] customHTTPHeaders)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.OpenHLS(pObject, url, customHTTPHeaders);
            }
        }

        public void Play(bool synchronised)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.Play(pObject, synchronised);
            }
        }

        public void Pause(float decelerateSeconds = 0, uint slipMs = 0)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.Pause(pObject, decelerateSeconds, slipMs);
            }
        }

        public void TogglePlayback()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.TogglePlayback(pObject);
            }
        }

        public void Seek(double percent)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.Seek(pObject, percent);
            }
        }

        public void SetPosition(double ms, bool andStop, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetPosition(pObject, ms, andStop, synchronisedStart, forceDefaultQuantum, preferWaitingforSynchronisedStart);
            }
        }

        public void CachePosition(double ms, byte pointID)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.CachePosition(pObject, ms, pointID);
            }
        }

        public bool Loop(double startMs, double lengthMs, bool jumpToStartMs, byte pointID, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.Loop(pObject, startMs, lengthMs, jumpToStartMs, pointID, synchronisedStart, forceDefaultQuantum, preferWaitingforSynchronisedStart);
            }

            return false;
        }

        public bool LoopBetween(double startMs, double endMs, bool jumpToStartMs, byte pointID, bool synchronisedStart, bool forceDefaultQuantum = false, bool preferWaitingforSynchronisedStart = false)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.LoopBetween(pObject, startMs, endMs, jumpToStartMs, pointID, synchronisedStart, forceDefaultQuantum, preferWaitingforSynchronisedStart);
            }

            return false;
        }

        public void ExitLoop(bool synchronisedStart = false)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.ExitLoop(pObject, synchronisedStart);
            }
        }

        public bool MsInLoop(double ms)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.MsInLoop(pObject, ms);
            }

            return false;
        }

        public void SetBpm(double newBpm)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetBpm(pObject, newBpm);
            }
        }

        public void SetFirstBeatMs(double ms)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetFirstBeatMs(pObject, ms);
            }
        }

        public double ClosestBeatMs(double ms, byte[] beatIndex)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.ClosestBeatMs(pObject, ms, beatIndex);
            }

            return 0;
        }

        public void JogTouchBegin(int ticksPerTurn, SuperpoweredAdvancedAudioPlayerJogMode mode, uint scratchSlipMs)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.JogTouchBegin(pObject, ticksPerTurn, mode, scratchSlipMs);
            }
        }

        public void JogTick(int value, bool bendStretch, float bendMaxPercent, uint bendHoldMs, bool parameterMode)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.JogTick(pObject, value, bendStretch, bendMaxPercent, bendHoldMs, parameterMode);
            }
        }

        public void JogTouchEnd(float decelerate, bool synchronisedStart)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.JogTouchEnd(pObject, decelerate, synchronisedStart);
            }
        }

        public void SetTempo(double tempo, bool masterTempo)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetTempo(pObject, tempo, masterTempo);
            }
        }

        public void SetPitchShift(int pitchShift)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetPitchShift(pObject, pitchShift);
            }
        }

        public void SetPitchShiftCents(int pitchShiftCents)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetPitchShiftCents(pObject, pitchShiftCents);
            }
        }

        public void SetReverse(bool reverse, uint slipMs)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetReverse(pObject, reverse, slipMs);
            }
        }

        public void PitchBend(float maxPercent, bool bendStretch, bool faster, uint holdMs)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.PitchBend(pObject, maxPercent, bendStretch, faster, holdMs);
            }
        }

        public void EndContinuousPitchBend()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.EndContinuousPitchBend(pObject);
            }
        }

        public void ResetBendMsOffset()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.ResetBendMsOffset(pObject);
            }
        }

        public void StartScratch(uint slipMs, bool stopImmediately)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.StartScratch(pObject, slipMs, stopImmediately);
            }
        }

        public void Scratch(double pitch, float smoothing)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.Scratch(pObject, pitch, smoothing);
            }
        }

        public void EndScratch(bool returnToStateBeforeScratch)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.EndScratch(pObject, returnToStateBeforeScratch);
            }
        }

        public double LastProcessMs()
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.LastProcessMs(pObject);
            }

            return 0;
        }

        public void SetSamplerate(uint sampleRate)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.SetSamplerate(pObject, sampleRate);
            }
        }

        public void OnMediaserverInterrupt()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredAdvancedAudioPlayerWrapper.OnMediaserverInterrupt(pObject);
            }
        }

        public double GetMsDifference(double phase, double quantum)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.GetMsDifference(pObject, phase, quantum);
            }

            return 0;
        }

        public bool Process(float[] buffer, bool bufferAdd, uint numberOfSamples, float volume = 1.0f, double masterBpm = 0.0f, double masterMsElapsedSinceLastBeat = -1.0, double phase = -1.0, double quantum = -1.0)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.Process(pObject, buffer, bufferAdd, numberOfSamples, volume, masterBpm, masterMsElapsedSinceLastBeat, phase, quantum);
            }

            return false;
        }

        public bool ProcessMulti(float[] buffers, bool[] bufferAdds, uint numberOfSamples, float[] volumes, double masterBpm = 0.0f, double masterMsElapsedSinceLastBeat = -1.0, double phase = -1.0, double quantum = -1.0)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredAdvancedAudioPlayerWrapper.ProcessMulti(pObject, buffers, bufferAdds, numberOfSamples, volumes, masterBpm, masterMsElapsedSinceLastBeat, phase, quantum);
            }

            return false;
        }
    }
}
