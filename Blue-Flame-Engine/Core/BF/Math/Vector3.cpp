#include "Vector3.h"

namespace BF
{
	namespace Math
	{
		Vector3::Vector3() :
			x(0.0f), y(0.0f), z(0.0f)
		{
		}

		Vector3::Vector3(const float& value) :
			x(value), y(value), z(value)
		{
		}

		Vector3::Vector3(const float& x, const float& y, const float& z) :
			x(x), y(y), z(z)
		{
		}

		Vector3::~Vector3()
		{
		}

		float Vector3::Dot(const Vector3& vector) const
		{
			return x * vector.x + y * vector.y + z * vector.z;
		}

		float Vector3::Magnitude() const
		{
			return (float)sqrt(Dot(*this));
		}

		Vector3 Vector3::Normalize() const
		{
			float length = Magnitude();

			if (length > 0)
				return Vector3(x / length, y / length, z / length);
			else
				return Vector3(0);
		}

		Vector3 operator+(const Vector3& left, const Vector3& right)
		{
			return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
		}

		Vector3 operator-(const Vector3& left, const Vector3& right)
		{
			return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
		}

		Vector3 operator*(const Vector3& left, const Vector3& right)
		{
			return Vector3(left.x * right.x, left.y * right.y, left.z * right.z);
		}

		Vector3 operator/(const Vector3& left, const Vector3& right)
		{
			return Vector3(left.x / right.x, left.y / right.y, left.z / right.z);
		}

		Vector3& Vector3::operator+=(const Vector3& right)
		{
			this->x += right.x;
			this->y += right.y;
			this->z += right.z;
			return *this;
		}

		Vector3& Vector3::operator-=(const Vector3& right)
		{
			this->x -= right.x;
			this->y -= right.y;
			this->z -= right.z;
			return *this;
		}

		Vector3& Vector3::operator*=(const Vector3& right)
		{
			this->x *= right.x;
			this->y *= right.y;
			this->z *= right.z;
			return *this;
		}

		Vector3& Vector3::operator/=(const Vector3& right)
		{
			this->x /= right.x;
			this->y /= right.y;
			this->z /= right.z;
			return *this;
		}

		std::ostream& operator<<(std::ostream& os, const Vector3& vector)
		{
			return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}";
		}
	}
}