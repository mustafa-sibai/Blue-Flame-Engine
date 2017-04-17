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
		float ToRadians(float Degrees);
		float Normalize(float value, float min, float max);

		int Min(int a, int b);
		float Min(float a, float b);

		int Max(int a, int b);
		float Max(float a, float b);

		int Clamp(int value, int lower, int upper);
		float Clamp(float value, float lower, float upper);
	}
}