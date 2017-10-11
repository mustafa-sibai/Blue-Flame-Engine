#pragma once
#include <iostream>
#include <math.h>
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		struct BF_API Vector4
		{
			float x, y, z, w;

			Vector4();
			Vector4(float value);
			Vector4(float x, float y, float z, float w);
			~Vector4();

			float Dot(const Vector4& vector) const;
			float Distance(const Vector4& vector) const;
			float Magnitude() const;
			Vector4 Direction(const Vector4& vector) const;
			Vector4 Normalize() const;

			friend BF_API Vector4 operator+(const Vector4& left, const Vector4& right);
			friend BF_API Vector4 operator-(const Vector4& left, const Vector4& right);
			friend BF_API Vector4 operator*(const Vector4& left, const Vector4& right);
			friend BF_API Vector4 operator/(const Vector4& left, const Vector4& right);

			Vector4& operator+=(const Vector4& right);
			Vector4& operator-=(const Vector4& right);
			Vector4& operator*=(const Vector4& right);
			Vector4& operator/=(const Vector4& right);

			bool operator>(const Vector4& right);
			bool operator>=(const Vector4& right);
			bool operator<(const Vector4& right);
			bool operator<=(const Vector4& right);

			bool operator==(const Vector4& right);
			bool operator!=(const Vector4& right);

			friend BF_API std::ostream& operator<<(std::ostream& os, const Vector4& vector);
		};
	}
}