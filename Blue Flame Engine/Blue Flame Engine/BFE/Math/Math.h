#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Rectangle.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

namespace BFE
{
	namespace Math
	{
		static float ToRadians(float Degrees)
		{
			return (float)((Degrees * M_PI) / 180.f);
		}
	}
}