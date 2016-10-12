#pragma once
#include <iostream>
#include "../Common.h"

namespace BF
{
	namespace Math
	{
		struct BF_API Vector3
		{
			float x, y, z;

			Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
			Vector3(const float &value) : x(value), y(value), z(value) { }
			Vector3(const float &x, const float &y, const float &z) : x(x), y(y), z(z) { }

			friend const Vector3 operator+(const Vector3 &leftVector, const Vector3 &rightVector) { return Vector3(leftVector.x + rightVector.x, leftVector.y + rightVector.y, leftVector.z + rightVector.z); }
			friend const Vector3 operator-(const Vector3 &leftVector, const Vector3 &rightVector) { return Vector3(leftVector.x - rightVector.x, leftVector.y - rightVector.y, leftVector.z - rightVector.z); }
			friend const Vector3 operator*(const Vector3 &leftVector, const Vector3 &rightVector) { return Vector3(leftVector.x * rightVector.x, leftVector.y * rightVector.y, leftVector.z * rightVector.z); }
			friend const Vector3 operator/(const Vector3 &leftVector, const Vector3 &rightVector) { return Vector3(leftVector.x / rightVector.x, leftVector.y / rightVector.y, leftVector.z / rightVector.z); }

			friend std::ostream& operator<<(std::ostream& os, const Vector3& vector) { return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}"; }
		};
	}
}