using System;
using ObjCRuntime;
using static SuperpoweredSDKXamarinWrapper.Constants;

namespace SuperpoweredSDKXamarinWrapper
{
    public static class Constants
    {
        [Native]
        public enum SuperpoweredFilterType
        {
            SuperpoweredFilter_Resonant_Lowpass,
            SuperpoweredFilter_Resonant_Highpass,
            SuperpoweredFilter_Bandlimited_Bandpass,
            SuperpoweredFilter_Bandlimited_Notch,
            SuperpoweredFilter_LowShelf,
            SuperpoweredFilter_HighShelf,
            SuperpoweredFilter_Parametric,
            SuperpoweredFilter_CustomCoefficients
        };

        public struct StemsCompressor
        {
            bool enabled;
            float inputGainDb;
            float outputGainDb;
            float dryWetPercent;
            float ratio;
            float attackSec;
            float releaseSec;
            float thresholdDb;
            float hpCutoffHz;
        };

        public struct StemsLimiter
        {
            bool enabled;
            float releaseSec;
            float thresholdDb;
            float ceilingDb;
        };

        public struct stemsInfo
        {
            char[] names;
            char[] colors;
            StemsCompressor compressor;
            StemsLimiter limiter;
        };

        [Native]
        public enum SuperpoweredAdvancedAudioPlayerSyncMode
        {
            SuperpoweredAdvancedAudioPlayerSyncMode_None,
            SuperpoweredAdvancedAudioPlayerSyncMode_Tempo,
            SuperpoweredAdvancedAudioPlayerSyncMode_TempoAndBeat
        };

        [Native]
        public enum SuperpoweredAdvancedAudioPlayerJogMode
        {
            SuperpoweredAdvancedAudioPlayerJogMode_Scratch,
            SuperpoweredAdvancedAudioPlayerJogMode_PitchBend,
            SuperpoweredAdvancedAudioPlayerJogMode_Parameter
        };

        [Native]
        public enum SuperpoweredAdvancedAudioPlayerEvent
        {
            SuperpoweredAdvancedAudioPlayerEvent_LoadSuccess,
            SuperpoweredAdvancedAudioPlayerEvent_LoadError,
            SuperpoweredAdvancedAudioPlayerEvent_HLSNetworkError,
            SuperpoweredAdvancedAudioPlayerEvent_ProgressiveDownloadError,
            SuperpoweredAdvancedAudioPlayerEvent_EOF,
            SuperpoweredAdvancedAudioPlayerEvent_JogParameter,
            SuperpoweredAdvancedAudioPlayerEvent_DurationChanged,
            SuperpoweredAdvancedAudioPlayerEvent_LoopEnd,
        };

        public struct hlsStreamAlternative
        {
            char[] uri, name, language, groupid;
            int bps;
            bool isDefault, isMp4a;
        };
    }
}
