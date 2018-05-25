using System;
using System.Runtime.InteropServices;
using static SuperpoweredSDKXamarinWrapper.Constants;

namespace SuperpoweredSDKXamarinWrapper
{
    public static class SuperPoweredFilterWrapper
    {
        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_Create")]
        public static extern IntPtr Create(SuperpoweredFilterType filterType, uint samplerate);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_Dispose")]
        public static extern void Dispose(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetResonantParameters")]
        public static extern void SetResonantParameters(IntPtr pObject, float frequency, float resonance);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetShelfParameters")]
        public static extern void SetShelfParameters(IntPtr pObject, float frequency, float slope, float dbGain);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetBandlimitedParameters")]
        public static extern void SetBandlimitedParameters(IntPtr pObject, float frequency, float octaveWidth);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetParametricParameters")]
        public static extern void SetParametricParameters(IntPtr pObject, float frequency, float octaveWidth, float dbGain);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetResonantParametersAndType")]
        public static extern void SetResonantParametersAndType(IntPtr pObject, float frequency, float resonance, SuperpoweredFilterType type);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetShelfParametersAndType")]
        public static extern void SetShelfParametersAndType(IntPtr pObject, float frequency, float slope, float dbGain, SuperpoweredFilterType type);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetBandlimitedParametersAndType")]
        public static extern void SetBandlimitedParametersAndType(IntPtr pObject, float frequency, float octaveWidth, SuperpoweredFilterType type);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetCustomCoefficients")]
        public static extern void SetCustomCoefficients(IntPtr pObject, float[] coefficients);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_Enable")]
        public static extern void Enable(IntPtr pObject, bool flag);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_SetSamplerate")]
        public static extern void SetSamplerate(IntPtr pObject, uint samplerate);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_Reset")]
        public static extern void Reset(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_Process")]
        public static extern bool Process(IntPtr pObject, float[] input, float[] output, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredFilter_ProcessMono")]
        public static extern bool ProcessMono(IntPtr pObject, float[] input, float[] output, uint numberOfSamples);
    }
}
