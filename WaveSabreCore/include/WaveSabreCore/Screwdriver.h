#ifndef __WAVESABRECORE_SCREWDRIVER_H__
#define __WAVESABRECORE_SCREWDRIVER_H__

#include "Device.h"

namespace WaveSabreCore
{
	class Screwdriver : public Device
	{
	public:
		enum class ParamIndices
		{
			X1,
            Y1,
            X2,
            Y2,
            LogPower0,
            LogPower1,
            LogPower2,

			DryWet,

			NumParams,
		};

		Screwdriver();

		virtual void Run(double songPosition, float **inputs, float **outputs, int numSamples);

		virtual void SetParam(int index, float value);
		virtual float GetParam(int index) const;

	private:
		float dryWet;
        float x1;
        float y1;
        float x2;
        float y2;
        float power0;
        float power1;
        float power2;
	};
}

#endif
