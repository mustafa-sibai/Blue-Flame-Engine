#pragma once
#include <iostream>

namespace BF
{
	namespace Math
	{
		template<typename T>
		struct Vector3
		{
			T x;
			T y;
			T z;

			Vector3();
			Vector3(T value);
			Vector3(T x, T y, T z);
			~Vector3();

			T Dot(const Vector3& vector) const;
			T Distance(const Vector3& vector) const;
			T Magnitude() const;
			Vector3 Cross(const Vector3& vector) const;
			Vector3 Direction(const Vector3& vector) const;
			Vector3 Normalize() const;
			Vector3 Center() const;
			Vector3 Min();
			Vector3 Max();

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

			friend Vector3 operator+(const Vector3& left, const Vector3& right) { return Vector3(left.x + right.x, left.y + right.y, left.z + right.z); }
			friend Vector3 operator-(const Vector3& left, const Vector3& right) { return Vector3(left.x - right.x, left.y - right.y, left.z - right.z); }
			friend Vector3 operator*(const Vector3& left, const Vector3& right) { return Vector3(left.x * right.x, left.y * right.y, left.z * right.z); }
			friend Vector3 operator/(const Vector3& left, const Vector3& right) { return Vector3(left.x / right.x, left.y / right.y, left.z / right.z); }

			friend std::ostream& operator<<(std::ostream& os, const Vector3& vector) { return os << "{" << vector.x << ", " << vector.y << ", " << vector.z "}"; }
		};

#include "Vector3.inl"

		typedef Vector3<int> Vector3i;
		typedef Vector3<float> Vector3f;
	}
}