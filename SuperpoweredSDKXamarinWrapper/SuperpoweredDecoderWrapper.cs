using System;
using System.Runtime.InteropServices;
using static SuperpoweredSDKXamarinWrapper.Constants;

namespace SuperpoweredSDKXamarinWrapper
{
    public static class SuperpoweredDecoderWrapper
    {
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void SuperpoweredDecoderFullyDownloadedCallback(IntPtr obj, IntPtr decoder);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void SuperpoweredDecoderID3Callback(IntPtr clientData, IntPtr frameName, IntPtr frameData, int frameDataSize);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_Create")]
        public static extern IntPtr Create(SuperpoweredDecoderFullyDownloadedCallback downloadedCallback, IntPtr clientData);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_Open")]
        public static extern char[] Open(IntPtr pObject, char[] path, bool metaOnly, int offset, int length, int stemsIndex, char[] customHTTPHeaders);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_Decode")]
        public static extern char Decode(IntPtr pObject, int[] pcmOutput, uint[] samples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_Seek")]
        public static extern char Seek(IntPtr pObject, Int64 sample, bool precise);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_GetAudioStartSample")]
        public static extern char GetAudioStartSample(IntPtr pObject, uint[] startSample, uint limitSamples = 0, int decibel = 0);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_ReconnectToMediaserver")]
        public static extern void ReconnectToMediaserver(IntPtr pObject);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_GetMetaData")]
        public static extern void GetMetaData(IntPtr pObject, char[] artist, char[] title, IntPtr image, int[] imageSizeBytes, float[] bpm, SuperpoweredDecoderID3Callback callback, IntPtr clientData, int maxFrameDataSize);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_GetStemsInfo")]
        public static extern bool GetStemsInfo(IntPtr pObject, char[] names, char[] colors, StemsCompressor compressor, StemsLimiter limiter);

        [DllImport("__Internal", EntryPoint = "SuperpoweredDecoder_Dispose")]
        public static extern void Dispose(IntPtr pObject);
    }
}
