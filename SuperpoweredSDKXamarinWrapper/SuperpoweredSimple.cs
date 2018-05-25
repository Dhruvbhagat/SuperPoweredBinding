using System;
namespace SuperpoweredSDKXamarinWrapper
{
    public class SuperpoweredSimple
    {
        public SuperpoweredSimple()
        {
        }

        public void SuperpoweredInterleave(float[] left, float[] right, float[] output, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredInterleave(left, right, output, numberOfSamples);
        }

        public void SuperpoweredVolume(float[] input, float[] output, float volumeStart, float volumeEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredVolume(input, output, volumeStart, volumeEnd, numberOfSamples);
        }

        public void SuperpoweredChangeVolume(float[] input, float[] output, float volumeStart, float volumeChange, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredChangeVolume(input, output, volumeStart, volumeChange, numberOfSamples);
        }

        public void SuperpoweredVolumeAdd(float[] input, float[] output, float volumeStart, float volumeEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredVolumeAdd(input, output, volumeStart, volumeEnd, numberOfSamples);
        }

        public void SuperpoweredChangeVolumeAdd(float[] input, float[] output, float volumeStart, float volumeChange, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredChangeVolumeAdd(input, output, volumeStart, volumeChange, numberOfSamples);
        }

        public float SuperpoweredPeak(float[] input, uint numberOfValues)
        {
            return SuperpoweredSimpleWrapper.SuperpoweredPeak(input, numberOfValues);
        }

        public void SuperpoweredCharToFloat(char[] input, float[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.SuperpoweredCharToFloat(input, output, numberOfSamples, numChannels);
        }

        public void SuperpoweredFloatToChar(float[] input, char[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.SuperpoweredFloatToChar(input, output, numberOfSamples, numChannels);
        }

        public void Superpowered24bitToFloat(float[] input, float[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.Superpowered24bitToFloat(input, output, numberOfSamples, numChannels);
        }

        public void SuperpoweredFloatTo24bit(float[] input, float[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.SuperpoweredFloatTo24bit(input, output, numberOfSamples, numChannels);
        }

        public void SuperpoweredIntToFloat(int[] input, float[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.SuperpoweredIntToFloat(input, output, numberOfSamples, numChannels);
        }

        public void SuperpoweredFloatToInt(float[] input, int[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.SuperpoweredFloatToInt(input, output, numberOfSamples, numChannels);
        }

        public void SuperpoweredFloatToShortInt(float[] input, int[] output, uint numberOfSamples, uint numChannels)
        {
            SuperpoweredSimpleWrapper.SuperpoweredFloatToShortInt(input, output, numberOfSamples, numChannels);
        }

        public void SuperpoweredFloatToShortIntInterleave(float[] inputLeft, float[] inputRight, int[] output, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredFloatToShortIntInterleave(inputLeft, inputRight, output, numberOfSamples);
        }

        public void SuperpoweredShortIntToFloat(int[] input, float[] output, uint numberOfSamples, float[] peaks)
        {
            SuperpoweredSimpleWrapper.SuperpoweredShortIntToFloat(input, output, numberOfSamples, peaks);
        }

        public void SuperpoweredInterleaveAdd(float[] left, float[] right, float[] output, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredInterleaveAdd(left, right, output, numberOfSamples);
        }

        public void SuperpoweredInterleaveAndGetPeaks(float[] left, float[] right, float[] output, uint numberOfSamples, float[] peaks)
        {
            SuperpoweredSimpleWrapper.SuperpoweredInterleaveAndGetPeaks(left, right, output, numberOfSamples, peaks);
        }

        public void SuperpoweredDeInterleave(float[] input, float[] left, float[] right, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredDeInterleave(input, left, right, numberOfSamples);
        }

        public void SuperpoweredDeInterleaveAdd(float[] input, float[] left, float[] right, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredDeInterleaveAdd(input, left, right, numberOfSamples);
        }

        public bool SuperpoweredHasNonFinite(float[] buffer, uint numberOfValues)
        {
            return SuperpoweredSimpleWrapper.SuperpoweredHasNonFinite(buffer, numberOfValues);
        }

        public void SuperpoweredStereoToMono(float[] input, float[] output, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredStereoToMono(input, output, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        }

        public void SuperpoweredStereoToMono2(float[] input, float[] output0, float[] output1, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredStereoToMono2(input, output0, output1, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        }

        public void SuperpoweredCrossMono(float[] left, float[] right, float[] output, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredCrossMono(left, right, output, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        }

        public void SuperpoweredCrossMono2(float[] left, float[] right, float[] output0, float output1, float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredCrossMono2(left, right, output0, output1, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        }

        public void SuperpoweredCrossStereo(float[] inputA, float[] inputB, float[] output, float[] gainStart, float[] gainEnd, uint numberOfSamples)
        {
            SuperpoweredSimpleWrapper.SuperpoweredCrossStereo(inputA, inputB, output, gainStart, gainEnd, numberOfSamples);
        }

        public void SuperpoweredAdd1(float[] input, float[] output, uint numberOfValues)
        {
            SuperpoweredSimpleWrapper.SuperpoweredAdd1(input, output, numberOfValues);
        }

        public void SuperpoweredAdd2(float[] inputA, float[] inputB, float[] output, uint numberOfValues)
        {
            SuperpoweredSimpleWrapper.SuperpoweredAdd2(inputA, inputB, output, numberOfValues);
        }

        public void SuperpoweredAdd4(float[] inputA, float[] inputB, float[] inputC, float[] inputD, float[] output, uint numberOfValues)
        {
            SuperpoweredSimpleWrapper.SuperpoweredAdd4(inputA, inputB, inputC, inputD, output, numberOfValues);
        }
    }
}
