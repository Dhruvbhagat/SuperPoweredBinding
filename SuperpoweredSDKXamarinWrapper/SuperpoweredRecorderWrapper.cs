using System;
using System.Runtime.InteropServices;

namespace SuperpoweredSDKXamarinWrapper
{
    public static class SuperpoweredRecorderWrapper
    {
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void SuperpoweredRecorderStoppedCallback(IntPtr obj);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_Create")]
        public static extern IntPtr Create(char[] tempPath, uint samplerate, uint minSeconds, byte numChannels, bool applyFade, SuperpoweredRecorderStoppedCallback callback, IntPtr clientData);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_Dispose")]
        public static extern void Dispose(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_Start")]
        public static extern bool Start(IntPtr pObject, char[] destinationPath);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_Stop")]
        public static extern void Stop(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_AddToTracklist")]
        public static extern void AddToTracklist(IntPtr pObject, char[] artist, char[] title, int offsetSeconds, bool takeOwnership);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_SetSamplerate")]
        public static extern void SetSamplerate(IntPtr pObject, uint samplerate);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_Process")]
        public static extern uint Process(IntPtr pObject, float[] input0, float[] input1, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredRecorder_Process2")]
        public static extern uint Process2(IntPtr pObject, float[] input, uint numberOfSamples);
    }
}
