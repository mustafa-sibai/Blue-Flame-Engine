#pragma once
#include "BF/Math/Rectangle.h"
#include "BF/Math/Vector2.h"
#include "BF/Math/Vector3.h"
#include "BF/Math/Vector4.h"
#include "BF/Math/Matrix4.h"
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		float BFE_API ToRadians(float Degrees);
		float BFE_API Normalize(float value, float min, float max);
		float BFE_API Lerp(float value1, float value2, float time);

		float BFE_API Infinity();
		float BFE_API PI();

		int BFE_API Min(int a, int b);
		float BFE_API Min(float a, float b);

		int BFE_API Max(int a, int b);
		float BFE_API Max(float a, float b);

		int BFE_API Clamp(int value, int lower, int upper);
		float BFE_API Clamp(float value, float lower, float upper);
	}
}