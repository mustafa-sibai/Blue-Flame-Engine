#pragma once
#include "BF/Math/Vector3.h"
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		class BF_API Ray
		{
			public:
				Vector3f origin;
				Vector3f direction;
				float length;

			public:
				Ray(const Vector3f& origin, const Vector3f& direction, float length);
				~Ray();

				bool Intersect(/*Spehere*/);
		};
	}
}