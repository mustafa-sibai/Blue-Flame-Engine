#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Rectangle.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

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