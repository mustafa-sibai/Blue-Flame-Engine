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
			return (value - max) / (max - min);
		}
	}
}