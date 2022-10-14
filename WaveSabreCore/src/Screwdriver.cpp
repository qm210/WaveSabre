#include <WaveSabreCore/Screwdriver.h>
#include <WaveSabreCore/Helpers.h>

#include <math.h>

namespace WaveSabreCore
{
	Screwdriver::Screwdriver()
		: Device((int)ParamIndices::NumParams)
	{
        x1 = 0.1f;
        y1 = 0.1f;
        x2 = 0.3f;
        y2 = 0.3f;
        power0 = 1.f;
        power1 = 1.f;
        power2 = 1.f;
		dryWet = 1.0f;
	}

	void Screwdriver::Run(double songPosition, float **inputs, float **outputs, int numSamples)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < numSamples; j++)
			{
				float x = fabs(inputs[i][j]);
                // is there a helper available?
                float sign = inputs[i][j] >= 0. ? 1.f : -1.f;

                // does allocating cost too much?
                float result = x <= x1
                    ? powf(x / x1, power0) * y1
                    : x <= x2
                    ? powf((x - x1) / (x2 - x1), power1) * (y2 - y1) + y1
                    : powf((x - x2) / (1.0f - x2), power2) * (1 - y2) + y2;

                result *= sign;

				outputs[i][j] = Helpers::Mix(inputs[i][j], result, dryWet);
			}
		}
	}

	void Screwdriver::SetParam(int index, float value)
	{
		switch ((ParamIndices)index)
		{
		case ParamIndices::X1: x1 = Helpers::Clamp(value, 0.001f, x2); break;
		case ParamIndices::Y1: y1 = value; break;
		case ParamIndices::X2: x2 = Helpers::Clamp(value, x1, 0.999f); break;
		case ParamIndices::Y2: y2 = value; break;
        case ParamIndices::LogPower0: power0 = Helpers::Exp2F(8.f * value - 4.f); break;
        case ParamIndices::LogPower1: power1 = Helpers::Exp2F(8.f * value - 4.f); break;
        case ParamIndices::LogPower2: power2 = Helpers::Exp2F(8.f * value - 4.f); break;
		case ParamIndices::DryWet: dryWet = value; break;
		}
	}

	float Screwdriver::GetParam(int index) const
	{
		switch ((ParamIndices)index)
		{
		case ParamIndices::X1:
		default:
			return x1;
        case ParamIndices::X2: return x2;
        case ParamIndices::Y1: return y1;
        case ParamIndices::Y2: return y2;
        case ParamIndices::LogPower0: return (4.f + log2f(power0)) / 8.f;
        case ParamIndices::LogPower1: return (4.f + log2f(power1)) / 8.f;
        case ParamIndices::LogPower2: return (4.f + log2f(power2)) / 8.f;
		case ParamIndices::DryWet: return dryWet;
		}
	}
}
