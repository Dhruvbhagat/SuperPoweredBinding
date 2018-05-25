using System;
using static SuperpoweredSDKXamarinWrapper.Constants;

namespace SuperpoweredSDKXamarinWrapper
{
    public class SuperPoweredFilter
    {
        private IntPtr pObject;

        public SuperPoweredFilter(SuperpoweredFilterType filterType, uint samplerate)
        {
            pObject = SuperPoweredFilterWrapper.Create(filterType, samplerate);
            return;
        }

        ~SuperPoweredFilter()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.Dispose(pObject);
                pObject = IntPtr.Zero;
            }
        }

        public void SetResonantParameters(float frequency, float resonance)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetResonantParameters(pObject, frequency, resonance);
            }
        }

        public void SetShelfParameters(float frequency, float slope, float dbGain)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetShelfParameters(pObject, frequency, slope, dbGain);
            }
        }

        public void SetBandlimitedParameters(float frequency, float octaveWidth)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetBandlimitedParameters(pObject, frequency, octaveWidth);
            }
        }

        public void SetParametricParameters(float frequency, float octaveWidth, float dbGain)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetParametricParameters(pObject, frequency, octaveWidth, dbGain);
            }
        }

        public void SetResonantParametersAndType(float frequency, float resonance, SuperpoweredFilterType type)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetResonantParametersAndType(pObject, frequency, resonance, type);
            }
        }

        public void SetShelfParametersAndType(float frequency, float slope, float dbGain, SuperpoweredFilterType type)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetShelfParametersAndType(pObject, frequency, slope, dbGain, type);
            }
        }

        public void SetBandlimitedParametersAndType(float frequency, float octaveWidth, SuperpoweredFilterType type)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetBandlimitedParametersAndType(pObject, frequency, octaveWidth, type);
            }
        }

        public void SetCustomCoefficients(float[] coefficients)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetCustomCoefficients(pObject, coefficients);
            }
        }

        public void Enable(bool flag)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.Enable(pObject, flag);
            }
        }

        public void SetSamplerate(uint samplerate)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.SetSamplerate(pObject, samplerate);
            }
        }

        public void Reset(IntPtr pObject)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperPoweredFilterWrapper.Reset(pObject);
            }
        }

        public bool Process(float[] input, float[] output, uint numberOfSamples)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperPoweredFilterWrapper.Process(pObject, input, output, numberOfSamples);
            }

            return false;
        }

        public bool ProcessMono(float[] input, float[] output, uint numberOfSamples)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperPoweredFilterWrapper.ProcessMono(pObject, input, output, numberOfSamples);
            }

            return false;
        }
    }
}
