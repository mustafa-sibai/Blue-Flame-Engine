#include "Math.h"

namespace BF
{
	namespace Math
	{
		float ToRadians(float Degrees)
		{
			return (float)((Degrees * M_PI) / 180.f);
		}
	}
}