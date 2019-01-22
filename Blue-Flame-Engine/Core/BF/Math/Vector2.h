#pragma once
#include <iostream>
#include <string>

namespace BF
{
	namespace Math
	{
		template<class T>
		class Vector2
		{
			public:
				T x;
				T y;

				Vector2();
				Vector2(T value);
				Vector2(T x, T y);
				~Vector2();

				T Dot(const Vector2& vector) const;
				T Distance(const Vector2& vector) const;
				T Magnitude() const;
				Vector2 Direction(const Vector2& vector) const;
				Vector2 Normalize() const;
				Vector2 Center() const;
				Vector2 Min();
				Vector2 Max();

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

				friend std::string operator+(const std::string& left, const Vector2& right) { return left + "{" + std::to_string(right.x) + ", " + std::to_string(right.y) + "}"; }
				friend std::string operator+(const Vector2& left, const std::string& right) { return "{" + std::to_string(left.x) + ", " + std::to_string(left.y) + "}" + right; }

				friend Vector2 operator+(const Vector2& left, const Vector2& right) { return Vector2(left.x + right.x, left.y + right.y); }
				friend Vector2 operator-(const Vector2& left, const Vector2& right) { return Vector2(left.x - right.x, left.y - right.y); }
				friend Vector2 operator*(const Vector2& left, const Vector2& right) { return Vector2(left.x * right.x, left.y * right.y); }
				friend Vector2 operator/(const Vector2& left, const Vector2& right) { return Vector2(left.x / right.x, left.y / right.y); }

				friend std::ostream& operator<<(std::ostream& os, const Vector2& vector) { return os << "{" << vector.x << ", " << vector.y << "}"; }

				static inline Vector2 Zero()	{ return Vector2(0, 0); }
				static inline Vector2 One()		{ return Vector2(1, 1); }

				static inline Vector2 Up()		{ return Vector2(0, -1); }
				static inline Vector2 Down()	{ return Vector2(0,  1); }

				static inline Vector2 Right()	{ return Vector2( 1, 0); }
				static inline Vector2 Left()	{ return Vector2(-1, 0); }
		};

#include "Vector2.inl"

		typedef Vector2<int> Vector2i;
		typedef Vector2<float> Vector2f;
	}
}