using System;
using static SuperpoweredSDKXamarinWrapper.Constants;
using static SuperpoweredSDKXamarinWrapper.SuperpoweredDecoderWrapper;

namespace SuperpoweredSDKXamarinWrapper
{
    public class SuperpoweredDecoder
    {
        private IntPtr pObject;

        public SuperpoweredDecoder(SuperpoweredDecoderFullyDownloadedCallback downloadedCallback, IntPtr clientData)
        {
            pObject = SuperpoweredDecoderWrapper.Create(downloadedCallback, clientData);

            return;
        }

        ~SuperpoweredDecoder()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredDecoderWrapper.Dispose(pObject);
                pObject = IntPtr.Zero;
            }
        }

        public char[] Open(char[] path, bool metaOnly, int offset, int length, int stemsIndex, char[] customHTTPHeaders)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredDecoderWrapper.Open(pObject, path, metaOnly, offset, length, stemsIndex, customHTTPHeaders);
            }

            return null;
        }

        public char Decode(int[] pcmOutput, uint[] samples)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredDecoderWrapper.Decode(pObject, pcmOutput, samples);
            }

            return ' ';
        }

        public char Seek(Int64 sample, bool precise)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredDecoderWrapper.Seek(pObject, sample, precise);
            }

            return ' ';
        }

        public char GetAudioStartSample(uint[] startSample, uint limitSamples = 0, int decibel = 0)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredDecoderWrapper.GetAudioStartSample(pObject, startSample, limitSamples, decibel);
            }

            return ' ';
        }

        public void ReconnectToMediaserver()
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredDecoderWrapper.ReconnectToMediaserver(pObject);
            }
        }

        public void GetMetaData(char[] artist, char[] title, IntPtr image, int[] imageSizeBytes, float[] bpm, SuperpoweredDecoderID3Callback callback, IntPtr clientData, int maxFrameDataSize)
        {
            if (pObject != IntPtr.Zero)
            {
                SuperpoweredDecoderWrapper.GetMetaData(pObject, artist, title, image, imageSizeBytes, bpm, callback, clientData, maxFrameDataSize);
            }
        }

        public bool GetStemsInfo(char[] names, char[] colors, StemsCompressor compressor, StemsLimiter limiter)
        {
            if (pObject != IntPtr.Zero)
            {
                return SuperpoweredDecoderWrapper.GetStemsInfo(pObject, names, colors, compressor, limiter);
            }

            return false;
        }
    }
}
