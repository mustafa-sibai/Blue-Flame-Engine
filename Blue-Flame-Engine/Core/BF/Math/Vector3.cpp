#include "Vector3.h"

namespace BF
{
	namespace Math
	{
		Vector3::Vector3() :
			x(0.0f), y(0.0f), z(0.0f)
		{
		}

		Vector3::Vector3(float value) :
			x(value), y(value), z(value)
		{
		}

		Vector3::Vector3(float x, float y, float z) :
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

		float Vector3::Distance(const Vector3& vector) const
		{
			Vector3 d = Direction(vector);
			return sqrt((d.x * d.x + d.y * d.y + d.z * d.z));
		}

		float Vector3::Magnitude() const
		{
			return (float)sqrt(Dot(*this));
		}

		Vector3 Vector3::Cross(const Vector3& vector) const
		{
			return Vector3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
		}

		Vector3 Vector3::Direction(const Vector3& vector) const
		{
			return Vector3(abs(vector.x - x), abs(vector.y - y), abs(vector.z - z));
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

		bool Vector3::operator>(const Vector3& right)
		{
			return this->Magnitude() > right.Magnitude();
		}

		bool Vector3::operator>=(const Vector3& right)
		{
			return this->Magnitude() >= right.Magnitude();
		}

		bool Vector3::operator<(const Vector3& right)
		{
			return this->Magnitude() < right.Magnitude();
		}

		bool Vector3::operator<=(const Vector3& right)
		{
			return this->Magnitude() <= right.Magnitude();
		}

		bool Vector3::operator==(const Vector3 &right)
		{
			return x == right.x && y == right.y && z == right.z;
		}

		bool Vector3::operator!=(const Vector3 &right)
		{
			return !(*this == right);
		}

		std::ostream& operator<<(std::ostream& os, const Vector3& vector)
		{
			return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}";
		}
	}
}