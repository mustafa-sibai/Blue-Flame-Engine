#pragma once
#include <iostream>

namespace BFE
{
	namespace Math
	{
		struct Vector4
		{
			float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;

			Vector4() { }
			Vector4(const float &value) : x(value), y(value), z(value), w(value) { }
			Vector4(const float &x, const float &y, const float &z, const float &w) : x(x), y(y), z(z), w(w) { }

			friend const Vector4 operator+(const Vector4 &leftVector, const Vector4 &rightVector) { return Vector4(leftVector.x + rightVector.x, leftVector.y + rightVector.y, leftVector.z + rightVector.z, leftVector.w + rightVector.w); }
			friend const Vector4 operator-(const Vector4 &leftVector, const Vector4 &rightVector) { return Vector4(leftVector.x - rightVector.x, leftVector.y - rightVector.y, leftVector.z - rightVector.z, leftVector.w - rightVector.w); }
			friend const Vector4 operator*(const Vector4 &leftVector, const Vector4 &rightVector) { return Vector4(leftVector.x * rightVector.x, leftVector.y * rightVector.y, leftVector.z * rightVector.z, leftVector.w * rightVector.w); }
			friend const Vector4 operator/(const Vector4 &leftVector, const Vector4 &rightVector) { return Vector4(leftVector.x / rightVector.x, leftVector.y / rightVector.y, leftVector.z / rightVector.z, leftVector.w / rightVector.w); }

			friend std::ostream& operator<<(std::ostream& os, const Vector4& vector) { return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "}"; }
		};
	}
}