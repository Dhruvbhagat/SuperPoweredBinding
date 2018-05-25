using System;
using UIKit;
using CoreAnimation;
using CoreGraphics;
using SuperpoweredSDKBinding;
using Foundation;
using static SuperpoweredSDKXamarinWrapper.SuperpoweredAdvancedAudioPlayerWrapper;
using ObjCRuntime;
using static SuperpoweredSDKXamarinWrapper.Constants;
using System.IO;
using SuperpoweredSDKXamarinWrapper;

namespace XamarinSpectrumAnalyser
{
	public partial class ViewController : UIViewController
	{
		uint interruptCounter = 0;

		CADisplayLink	displayLink;
		const int maxFrequencies = 52;
		CALayer[]	layers = new CALayer[maxFrequencies];
		bool runFlag = false;
		SuperpoweredFrequencies superpowered;

        SuperpoweredAdvancedAudioPlayer aAudioPlayer;

		/// <summary>
		/// Initializes a new instance of the <see cref="XamarinSpectrumAnalyser.ViewController"/> class.
		/// </summary>
		/// <param name="handle">Handle.</param>
		public ViewController (IntPtr handle) : base (handle)
		{
            aAudioPlayer = new SuperpoweredAdvancedAudioPlayer(handle, AudioPlayerCallback, 44100, 0);
			return;
		}

		[MonoPInvokeCallback(typeof(SuperpoweredAdvancedAudioPlayerCallback))]
		private static void AudioPlayerCallback(IntPtr clientData, SuperpoweredAdvancedAudioPlayerEvent event1, IntPtr value1)
		{
            if(event1 == SuperpoweredAdvancedAudioPlayerEvent.SuperpoweredAdvancedAudioPlayerEvent_LoadSuccess)
            {
                //Handle if track successfully loaded
            }
		}

		/// <summary>
		/// Views the did load.
		/// </summary>
		public override void ViewDidLoad ()
		{
			base.ViewDidLoad ();
			// Perform any additional setup after loading the view, typically from a nib.

			UIColor color = new UIColor (0f, 0.6f, 0.8f, 1.0f);

			for (int i = 0; i < maxFrequencies; i++) {
				layers [i] = new CALayer ();
				layers [i].BackgroundColor = color.CGColor;
				layers [i].Frame = new CGRect ();
				View.Layer.AddSublayer( layers[i] );
			}

			superpowered = new SuperpoweredFrequencies();

			displayLink = CADisplayLink.Create (onDisplayLink);
            displayLink.PreferredFramesPerSecond = 1;
			displayLink.AddToRunLoop (NSRunLoop.Current, NSRunLoopMode.Common);

			bRunStop.SetTitle( runFlag ? "Stop" : "Run", UIControlState.Normal );

            var path = "lycka.mp3";
			var sourcePath = Path.Combine(NSBundle.MainBundle.BundlePath, path);

            aAudioPlayer.Open1(sourcePath); //fixme - this will not generate error even if empty string passed as track path
		}

		/// <summary>
		/// Dids the receive memory warning.
		/// </summary>
		public override void DidReceiveMemoryWarning ()
		{
			base.DidReceiveMemoryWarning ();

			Console.WriteLine( "MEMORY WARNING!!!" );

			// Release any cached data, images, etc that aren't in use.

			return;
		}
			
		/// <summary>
		/// Ons the display link.
		/// </summary>
		void onDisplayLink()
		{
			interruptCounter++;
			if (runFlag) {
				float[] frequencies = new float[maxFrequencies];
				GetFrequencies (frequencies);

				DisplaySpectrum( ref frequencies );
			}

			return;
		}

		/// <summary>
		/// A method that uses unsafe code to take the address of the float array and then calls the Objective-C binding.
		/// </summary>
		/// <param name="frequencies">Frequencies.</param>
		unsafe void GetFrequencies (float[] frequencies)
		{
			fixed (float* ip = &frequencies [0] )
			{
				superpowered.GetFrequencies ((IntPtr)ip);
			}

			return;
		}

		/// <summary>
		/// Displaies the spectrum.
		/// </summary>
		/// <param name="spectrum">Spectrum.</param>
		void DisplaySpectrum( ref float[] spectrum )
		{
			CGPoint tmpLocation = new CGPoint();
			CGSize tmpSize = new CGSize();

			CGColor octaveColour = new UIColor (1.0f, 0.0f, 0.0f, 1.0f).CGColor;

			// Wrapping the UI changes in a CATransaction block like this prevents animation/smoothing.
			CATransaction.Begin ();
			CATransaction.AnimationDuration = 0;
			CATransaction.DisableActions = true;

			nfloat originY = View.Frame.Size.Height - 20;
			nfloat width = (View.Frame.Size.Width - 62) / 52;     	// -52 allows for one point gap -10 allows 5 point lhs rhs

			CGRect frame = new CGRect (0, 0, width, 0);

			tmpLocation = frame.Location;
			tmpLocation.X = 5;

			for (int i = 0; i < maxFrequencies; i++) {
				if ((i - 8) % 12 == 0)								// Use a different colour for each C note.
					layers [i].BackgroundColor = octaveColour;
				
				tmpSize = frame.Size;
				tmpSize.Height = spectrum [i] * 12000;
				frame.Size = tmpSize;								// Scale it so we can see something

				// Need to work through intermediate objects because you cannot set the value of a return value.
				tmpLocation.Y  = originY - frame.Size.Height;
				frame.Y = tmpLocation.Y;

				layers [i].Frame = frame;

				tmpLocation.X += width + 1;;
				frame.Location = tmpLocation;
			}

			CATransaction.Commit ();

			return;
		}

		/// <summary>
		/// Toggles the run state of the spectrum analyser.
		/// </summary>
		/// <param name="sender">Sender.</param>
		partial void bRunStop_TouchUpInside (UIButton sender)
		{
			runFlag = !runFlag;
			bRunStop.SetTitle( runFlag ? "Stop" : "Run", UIControlState.Normal );
			Console.WriteLine( interruptCounter );

            if(runFlag)
            {
                aAudioPlayer.Play(false); //fixme - This won't actually play the track even if proper path passed to open() function
			}
            else
            {
                aAudioPlayer.Pause();
            }
	
			return;
		}
	}
}

