using System;
using System.Runtime.InteropServices;

namespace SuperpoweredSDKXamarinWrapper
{
	public static class SuperpoweredBandpassFilterbankWrapper
	{
		[DllImport("__Internal", EntryPoint = "SuperpoweredBandpassFilterbank_Create")]
		public static extern IntPtr Create(int numBands, float[] frequencies, float[] widths, uint samplerate);

		[DllImport("__Internal", EntryPoint = "SuperpoweredBandpassFilterbank_Dispose")]
		public static extern void Dispose( IntPtr pObject );

		[DllImport("__Internal", EntryPoint = "SuperpoweredBandpassFilterbank_SetSamplerate")]
		public static extern void SetSamplerate( IntPtr pObject, uint sampleRate );

		[DllImport("__Internal", EntryPoint = "SuperpoweredBandpassFilterbank_Process")]
		public static extern void Process(IntPtr pObject, float[] input, float[] bands, float[] peak, float[] sum, uint numberOfSamples, int group);

        [DllImport("__Internal", EntryPoint = "SuperpoweredBandpassFilterbank_ProcessNoAdd")]
        public static extern void ProcessNoAdd(IntPtr pObject, float[] input, float[] bands, float[] peak, float[] sum, uint numberOfSamples, int group);
	}
}