using System;
namespace SuperpoweredSDKXamarinWrapper
{
    public class Superpowered3BandEQ
    {
        private IntPtr pObject;

        public Superpowered3BandEQ(uint samplerate)
        {
            pObject = Superpowered3BandEQWrapper.Create(samplerate);

            return;
        }

        ~Superpowered3BandEQ()
        {
            if (pObject != IntPtr.Zero)
            {
                Superpowered3BandEQWrapper.Dispose(pObject);
                pObject = IntPtr.Zero;
            }
        }

        public void Enable(bool flag)
        {
            if (pObject != IntPtr.Zero)
            {
                Superpowered3BandEQWrapper.Enable(pObject, flag);
            }
        }

        public void Reset()
        {
            if (pObject != IntPtr.Zero)
            {
                Superpowered3BandEQWrapper.Reset(pObject);
            }
        }

        public bool Process(float[] input, float[] output, uint numberOfSamples)
        {
            if (pObject != IntPtr.Zero)
            {
                return Superpowered3BandEQWrapper.Process(pObject,  input, output, numberOfSamples);
            }

            return false;
        }
    }
}
