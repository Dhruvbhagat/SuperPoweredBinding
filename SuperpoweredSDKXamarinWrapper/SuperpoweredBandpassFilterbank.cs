using System;


namespace SuperpoweredSDKXamarinWrapper
{
	public class SuperpoweredBandpassFilterbank
	{
		private IntPtr pObject;

		/// <summary>
		/// Initializes a new instance of the <see cref="SuperpoweredSDKXamarinWrapper.SuperpoweredBandpassFilterbank"/> class.
		/// </summary>
		/// <param name="numBands">Number bands.</param>
		/// <param name="frequencies">Frequencies.</param>
		/// <param name="widths">Widths.</param>
		/// <param name="samplerate">Samplerate.</param>
		public SuperpoweredBandpassFilterbank( int numBands, float[] frequencies, float[] widths, uint samplerate )
		{
			pObject = SuperpoweredBandpassFilterbankWrapper.Create( numBands, frequencies, widths, samplerate );

			return;
		}

		/// <summary>
		/// Releases unmanaged resources and performs other cleanup operations before the
		/// <see cref="SuperpoweredSDKXamarinWrapper.SuperpoweredBandpassFilterbank"/> is reclaimed by garbage collection.
		/// </summary>
		~SuperpoweredBandpassFilterbank()
		{
			if (pObject != IntPtr.Zero) {
				SuperpoweredBandpassFilterbankWrapper.Dispose(pObject);
				pObject = IntPtr.Zero;
			}
		}

		/// <summary>
		/// Sets the samplerate.
		/// </summary>
		/// <param name="sampleRate">Sample rate.</param>
		public void SetSamplerate( uint sampleRate )
		{
			if (pObject != IntPtr.Zero) {
				SuperpoweredBandpassFilterbankWrapper.SetSamplerate (pObject, sampleRate);
			}
		}

		/// <summary>
		/// Process the specified input, bands, peak, sum and numberOfSamples.
		/// </summary>
		/// <param name="input">Input.</param>
		/// <param name="bands">Bands.</param>
		/// <param name="peak">Peak.</param>
		/// <param name="sum">Sum.</param>
		/// <param name="numberOfSamples">Number of samples.</param>
		public void Process( float[] input, float[] bands, float[] peak, float[] sum, uint numberOfSamples, int group = 0)
		{
			if (pObject != IntPtr.Zero) {
                SuperpoweredBandpassFilterbankWrapper.Process (pObject, input, bands, peak, sum, numberOfSamples, group);
			}
		}

        public void ProcessNoAdd(float[] input, float[] bands, float[] peak, float[] sum, uint numberOfSamples, int group = 0)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredBandpassFilterbankWrapper.ProcessNoAdd(pObject, input, bands, peak, sum, numberOfSamples, group);
            }
        }
	}
}

