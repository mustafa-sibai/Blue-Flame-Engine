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
			Vector3(float value);
			Vector3(float x, float y, float z);
			~Vector3();

			float Dot(const Vector3& vector) const;
			float Distance(const Vector3& vector) const;
			float Magnitude() const;
			Vector3 Cross(const Vector3& vector) const;
			Vector3 Direction(const Vector3& vector) const;
			Vector3 Normalize() const;


			friend BF_API Vector3 operator+(const Vector3& left, const Vector3& right);
			friend BF_API Vector3 operator-(const Vector3& left, const Vector3& right);
			friend BF_API Vector3 operator*(const Vector3& left, const Vector3& right);
			friend BF_API Vector3 operator/(const Vector3& left, const Vector3& right);

			Vector3& operator+=(const Vector3& right);
			Vector3& operator-=(const Vector3& right);
			Vector3& operator*=(const Vector3& right);
			Vector3& operator/=(const Vector3& right);

			bool operator>(const Vector3& right);
			bool operator>=(const Vector3& right);
			bool operator<(const Vector3& right);
			bool operator<=(const Vector3& right);

			bool operator==(const Vector3& right);
			bool operator!=(const Vector3& right);

			friend BF_API std::ostream& operator<<(std::ostream& os, const Vector3& vector);
		};
	}
}