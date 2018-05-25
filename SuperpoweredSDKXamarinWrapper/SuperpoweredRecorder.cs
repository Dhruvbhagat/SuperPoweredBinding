using System;
using System.Runtime.InteropServices;
using static SuperpoweredSDKXamarinWrapper.SuperpoweredRecorderWrapper;

namespace SuperpoweredSDKXamarinWrapper
{
    public class SuperpoweredRecorder
    {
        private IntPtr pObject;

        public SuperpoweredRecorder(char[] tempPath, uint samplerate, uint minSeconds, byte numChannels, bool applyFade, SuperpoweredRecorderStoppedCallback callback, IntPtr clientData)
        {
            pObject = SuperpoweredRecorderWrapper.Create(tempPath, samplerate, minSeconds, numChannels, applyFade, callback, clientData);
        }

        ~SuperpoweredRecorder()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredRecorderWrapper.Dispose(pObject);
                pObject = IntPtr.Zero;
            }
        }

        public bool Start(char[] destinationPath)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredRecorderWrapper.Start(pObject, destinationPath);
            }

            return false;
        }

        void Stop()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredRecorderWrapper.Stop(pObject);
            }
        }

        void AddToTracklist(char[] artist, char[] title, int offsetSeconds, bool takeOwnership)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredRecorderWrapper.AddToTracklist(pObject, artist, title, offsetSeconds, takeOwnership);
            }
        }

        void SetSamplerate(uint samplerate)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredRecorderWrapper.SetSamplerate(pObject, samplerate);
            }
        }

        uint Process(float[] input0, float[] input1, uint numberOfSamples)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredRecorderWrapper.Process(pObject, input0, input1, numberOfSamples);
            }

            return 0;
        }

        uint Process2(float[] input, uint numberOfSamples)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredRecorderWrapper.Process2(pObject, input, numberOfSamples);
            }

            return 0;
        }
    }
}
