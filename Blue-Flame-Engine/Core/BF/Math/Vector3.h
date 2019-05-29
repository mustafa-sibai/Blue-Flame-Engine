#pragma once
#include <iostream>
#include <string>

namespace BF
{
	namespace Math
	{
		template<class T>
		class Vector3
		{
		public:
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

			friend std::string operator+(const std::string& left, const Vector3& right) { return left + "{" + std::to_string(right.x) + ", " + std::to_string(right.y) + ", " + std::to_string(right.z) + "}"; }
			friend std::string operator+(const Vector3& left, const std::string& right) { return "{" + std::to_string(left.x) + ", " + std::to_string(left.y) + ", " + std::to_string(left.z) + "}" + right; }

			friend Vector3 operator+(const Vector3& left, const Vector3& right) { return Vector3(left.x + right.x, left.y + right.y, left.z + right.z); }
			friend Vector3 operator-(const Vector3& left, const Vector3& right) { return Vector3(left.x - right.x, left.y - right.y, left.z - right.z); }
			friend Vector3 operator*(const Vector3& left, const Vector3& right) { return Vector3(left.x * right.x, left.y * right.y, left.z * right.z); }
			friend Vector3 operator/(const Vector3& left, const Vector3& right) { return Vector3(left.x / right.x, left.y / right.y, left.z / right.z); }

			friend std::ostream& operator<<(std::ostream& os, const Vector3& vector) { return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}"; }

			static inline Vector3 Zero() { return Vector3(0, 0, 0); }
			static inline Vector3 One() { return Vector3(1, 1, 1); }

			static inline Vector3 Up() { return Vector3(0, 1, 0); }
			static inline Vector3 Down() { return Vector3(0, -1, 0); }

			static inline Vector3 Right() { return Vector3(1, 0, 0); }
			static inline Vector3 Left() { return Vector3(-1, 0, 0); }

			static inline Vector3 Forward() { return Vector3(0, 0, 1); }
			static inline Vector3 Back() { return Vector3(0, 0, -1); }
		};

#include "Vector3.inl"

		typedef Vector3<int> Vector3i;
		typedef Vector3<float> Vector3f;
	}
}