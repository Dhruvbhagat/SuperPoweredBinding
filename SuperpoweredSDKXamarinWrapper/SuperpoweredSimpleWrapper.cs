using System;
using System.Runtime.InteropServices;

namespace SuperpoweredSDKXamarinWrapper
{
	public static class SuperpoweredSimpleWrapper
	{
		[DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredInterleave")]
		public static extern void SuperpoweredInterleave(float[] left, float[] right, float[] output, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredVolume")]
        public static extern void SuperpoweredVolume(float[] input, float[] output, float volumeStart, float volumeEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredChangeVolume")]
        public static extern void SuperpoweredChangeVolume(float[] input, float[] output, float volumeStart, float volumeChange, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredVolumeAdd")]
        public static extern void SuperpoweredVolumeAdd(float[] input, float[] output, float volumeStart, float volumeEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredChangeVolumeAdd")]
        public static extern void SuperpoweredChangeVolumeAdd(float[] input, float[] output, float volumeStart, float volumeChange, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredPeak")]
        public static extern float SuperpoweredPeak(float[] input, uint numberOfValues);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredCharToFloat")]
        public static extern void SuperpoweredCharToFloat(char[] input, float[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredFloatToChar")]
        public static extern void SuperpoweredFloatToChar(float[] input, char[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_Superpowered24bitToFloat")]
        public static extern void Superpowered24bitToFloat(float[] input, float[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredFloatTo24bit")]
        public static extern void SuperpoweredFloatTo24bit(float[] input, float[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredIntToFloat")]
        public static extern void SuperpoweredIntToFloat(int[] input, float[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredFloatToInt")]
        public static extern void SuperpoweredFloatToInt(float[] input, int[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredFloatToShortInt")]
        public static extern void SuperpoweredFloatToShortInt(float[] input, int[] output, uint numberOfSamples, uint numChannels);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredFloatToShortIntInterleave")]
        public static extern void SuperpoweredFloatToShortIntInterleave(float[] inputLeft, float[] inputRight, int[] output, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredShortIntToFloat")]
        public static extern void SuperpoweredShortIntToFloat(int[] input, float[] output, uint numberOfSamples, float[] peaks);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredInterleaveAdd")]
        public static extern void SuperpoweredInterleaveAdd(float[] left, float[] right, float[] output, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredInterleaveAndGetPeaks")]
        public static extern void SuperpoweredInterleaveAndGetPeaks(float[] left, float[] right, float[] output, uint numberOfSamples, float[] peaks);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredDeInterleave")]
        public static extern void SuperpoweredDeInterleave(float[] input, float[] left, float[] right, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredDeInterleaveAdd")]
        public static extern void SuperpoweredDeInterleaveAdd(float[] input, float[] left, float[] right, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredHasNonFinite")]
        public static extern bool SuperpoweredHasNonFinite(float[] buffer, uint numberOfValues);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredStereoToMono")]
        public static extern void SuperpoweredStereoToMono(float[] input, float[] output, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredStereoToMono2")]
        public static extern void SuperpoweredStereoToMono2(float[] input, float[] output0, float[] output1, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredCrossMono")]
        public static extern void SuperpoweredCrossMono(float[] left, float[] right, float[] output, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredCrossMono2")]
        public static extern void SuperpoweredCrossMono2(float[] left, float[] right, float[] output0, float output1, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredCrossStereo")]
        public static extern void SuperpoweredCrossStereo(float[] inputA, float[] inputB, float[] output, float[] gainStart, float[] gainEnd, uint numberOfSamples);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredAdd1")]
        public static extern void SuperpoweredAdd1(float[] input, float[] output, uint numberOfValues);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredAdd2")]
        public static extern void SuperpoweredAdd2(float[] inputA, float[] inputB, float[] output, uint numberOfValues);

        [DllImport("__Internal", EntryPoint = "SuperpoweredSimple_SuperpoweredAdd4")]
        public static extern void SuperpoweredAdd4(float[] inputA, float[] inputB, float[] inputC, float[] inputD, float[] output, uint numberOfValues);
	}
}

