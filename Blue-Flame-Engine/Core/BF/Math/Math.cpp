#include "Math.h"

namespace BF
{
	namespace Math
	{
		float ToRadians(float Degrees)
		{
			return Degrees * (float)(M_PI / 180.0f);
		}

		float Normalize(float value, float min, float max)
		{
			return (value - min) / (max - min);
		}

		float Lerp(float value1, float value2, float time)
		{
			return value1 + (value2 - value1) * time;
		}

		int Min(int a, int b)
		{
			return a < b ? a : b;
		}

		float Min(float a, float b)
		{
			return a < b ? a : b;
		}

		int Max(int a, int b)
		{
			return a > b ? a : b;
		}

		float Max(float a, float b)
		{
			return a > b ? a : b;
		}

		int Clamp(int value, int lower, int upper)
		{
			return Max(lower, Min(value, upper));
		}

		float Clamp(float value, float lower, float upper)
		{
			return Max(lower, Min(value, upper));
		}
	}
}