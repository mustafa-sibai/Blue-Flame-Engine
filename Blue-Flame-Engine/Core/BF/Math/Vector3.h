#pragma once
#include <iostream>
#include <math.h>
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		struct BF_API Vector3
		{
			float x, y, z;

			Vector3();
			Vector3(const float& value);
			Vector3(const float& x, const float& y, const float& z);
			~Vector3();

			float Dot(const Vector3& vector) const;
			float Magnitude() const;
			Vector3 Normalize() const;

			friend BF_API Vector3 operator+(const Vector3& left, const Vector3& right);
			friend BF_API Vector3 operator-(const Vector3& left, const Vector3& right);
			friend BF_API Vector3 operator*(const Vector3& left, const Vector3& right);
			friend BF_API Vector3 operator/(const Vector3& left, const Vector3& right);

			Vector3& operator+=(const Vector3& right);
			Vector3& operator-=(const Vector3& right);
			Vector3& operator*=(const Vector3& right);
			Vector3& operator/=(const Vector3& right);

			friend BF_API std::ostream& operator<<(std::ostream& os, const Vector3& vector);
		};
	}
}