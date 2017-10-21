#pragma once
#include <iostream>
#include <math.h>
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		struct BF_API Vector2
		{
			float x, y;

			Vector2();
			Vector2(float value);
			Vector2(float x, float y);
			~Vector2();

			float Dot(const Vector2& vector) const;
			float Distance(const Vector2& vector) const;
			float Magnitude() const;
			Vector2 Direction(const Vector2& vector) const;
			Vector2 Normalize() const;
			Vector2 Center() const;
			Vector2 Min();
			Vector2 Max();

			friend BF_API Vector2 operator+(const Vector2& left, const Vector2& right);
			friend BF_API Vector2 operator-(const Vector2& left, const Vector2& right);
			friend BF_API Vector2 operator*(const Vector2& left, const Vector2& right);
			friend BF_API Vector2 operator/(const Vector2& left, const Vector2& right);

			Vector2& operator+=(const Vector2& right);
			Vector2& operator-=(const Vector2& right);
			Vector2& operator*=(const Vector2& right);
			Vector2& operator/=(const Vector2& right);

			bool operator>(const Vector2& right);
			bool operator>=(const Vector2& right);
			bool operator<(const Vector2& right);
			bool operator<=(const Vector2& right);

			bool operator==(const Vector2& right);
			bool operator!=(const Vector2& right);

			friend BF_API std::ostream& operator<<(std::ostream& os, const Vector2& vector);
		};
	}
}