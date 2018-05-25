using System;
using System.Runtime.InteropServices;

namespace SuperpoweredSDKXamarinWrapper
{
    public static class Superpowered3BandEQWrapper
    {
        [DllImport("__Internal", EntryPoint = "Superpowered3BandEQ_Create")]
        public static extern IntPtr Create(uint samplerate);

        [DllImport("__Internal", EntryPoint = "Superpowered3BandEQ_Dispose")]
        public static extern void Dispose(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "Superpowered3BandEQ_Enable")]
        public static extern void Enable(IntPtr pObject, bool flag);

        [DllImport("__Internal", EntryPoint = "Superpowered3BandEQ_Reset")]
        public static extern void Reset(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "Superpowered3BandEQ_Process")]
        public static extern bool Process(IntPtr pObject, float[] input, float[] output, uint numberOfSamples);
    }
}
