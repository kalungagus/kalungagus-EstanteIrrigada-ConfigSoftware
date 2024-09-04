//***************************************************************************************
//                                    AnalogSignals
//***************************************************************************************
#pragma once

//***************************************************************************************
// Namespace
//***************************************************************************************
namespace AnalogSignals
{
	using namespace System;

	//***********************************************************************************
	// Delegates
	//***********************************************************************************
	public delegate void ZeroCross(Object^);

	//***************************************************************************************
	// Classes
	//***************************************************************************************
	public ref class AnalogSignal
	{
		protected:
			double squaredPeriodSampleSum;
			double lastSample;
			double dcOffset;
			double samplingPeriod;
			double signalPeriod;
			double rmsValue;

		public:
			ZeroCross^ onZeroCross;

			//===========================================================================
			// Construtores
			//===========================================================================
			AnalogSignal(double dcOff, double sPeriod)
			{
				dcOffset = dcOff;
				lastSample = dcOff;
				samplingPeriod = sPeriod;
				signalPeriod = 0.0f;
				squaredPeriodSampleSum = 0.0f;
				rmsValue = 0.0f;
			}

			//===========================================================================
			// Propriedades
			//===========================================================================
			property double RMS
			{
				virtual double get(void)
				{
					return(rmsValue);
				}
			}

			//===========================================================================
			// Métodos
			//===========================================================================
			void addSample(double sample)
			{
				// Novo período
				if (lastSample < 0 && sample >= 0)
				{
					rmsValue = Math::Sqrt(squaredPeriodSampleSum / signalPeriod);

					signalPeriod = 0.0f;
					squaredPeriodSampleSum = sample;

					onZeroCross(this);
				}
				else
				{
					squaredPeriodSampleSum += sample * sample;
					signalPeriod += samplingPeriod;
				}

				lastSample = sample;
			}

			void addSample(void)
			{
				squaredPeriodSampleSum += lastSample * lastSample;
				signalPeriod += samplingPeriod;
			}
	};
}