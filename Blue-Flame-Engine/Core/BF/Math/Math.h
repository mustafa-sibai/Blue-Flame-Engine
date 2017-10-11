#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "BF/Math/Rectangle.h"
#include "BF/Math/Vector2.h"
#include "BF/Math/Vector3.h"
#include "BF/Math/Vector4.h"
#include "BF/Math/Matrix4.h"

namespace BF
{
	namespace Math
	{
		float BF_API ToRadians(float Degrees);
		float BF_API Normalize(float value, float min, float max);
		float BF_API Lerp(float value1, float value2, float time);

		int BF_API Min(int a, int b);
		float BF_API Min(float a, float b);

		int BF_API Max(int a, int b);
		float BF_API Max(float a, float b);

		int BF_API Clamp(int value, int lower, int upper);
		float BF_API Clamp(float value, float lower, float upper);
	}
}