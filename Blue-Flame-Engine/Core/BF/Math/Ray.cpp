#include "Ray.h"

namespace BF
{
	namespace Math
	{
		Ray::Ray(const Vector3f& origin, const Vector3f& direction, float length) :
			origin(origin), direction(direction), length(length)
		{
		}

		Ray::~Ray()
		{
		}

		bool Ray::Intersect()
		{
			return false;
		}
	}
}