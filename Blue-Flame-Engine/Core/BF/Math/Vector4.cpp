#include "Vector4.h"

namespace BF
{
	namespace Math
	{
		Vector4::Vector4() :
			x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
		}

		Vector4::Vector4(float value) :
			x(value), y(value), z(value), w(value)
		{
		}

		Vector4::Vector4(float x, float y, float z, float w) :
			x(x), y(y), z(z), w(w)
		{
		}

		Vector4::~Vector4()
		{
		}

		float Vector4::Dot(const Vector4& vector) const
		{
			return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
		}

		float Vector4::Magnitude() const
		{
			return (float)sqrt(Dot(*this));
		}

		Vector4 Vector4::Normalize() const
		{
			float length = Magnitude();

			if (length > 0)
				return Vector4(x / length, y / length, z / length, w / length);
			else
				return Vector4(0);
		}

		Vector4 operator+(const Vector4& left, const Vector4& right)
		{
			return Vector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
		}

		Vector4 operator-(const Vector4& left, const Vector4& right)
		{
			return Vector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
		}

		Vector4 operator*(const Vector4& left, const Vector4& right)
		{
			return Vector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
		}

		Vector4 operator/(const Vector4& left, const Vector4& right)
		{
			return Vector4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
		}

		Vector4& Vector4::operator+=(const Vector4& right)
		{
			this->x += right.x;
			this->y += right.y;
			this->z += right.z;
			this->w += right.w;
			return *this;
		}

		Vector4& Vector4::operator-=(const Vector4& right)
		{
			this->x -= right.x;
			this->y -= right.y;
			this->z -= right.z;
			this->w -= right.w;
			return *this;
		}

		Vector4& Vector4::operator*=(const Vector4& right)
		{
			this->x *= right.x;
			this->y *= right.y;
			this->z *= right.z;
			this->w *= right.w;
			return *this;
		}

		Vector4& Vector4::operator/=(const Vector4& right)
		{
			this->x /= right.x;
			this->y /= right.y;
			this->z /= right.z;
			this->w /= right.w;
			return *this;
		}

		bool Vector4::operator==(const Vector4 &right)
		{
			return x == right.x && y == right.y && z == right.z && w == right.w ? true : false;
		}

		bool Vector4::operator!=(const Vector4 &right)
		{
			return x != right.x || y != right.y || z != right.z || w != right.w ? true : false;
		}

		std::ostream& operator<<(std::ostream& os, const Vector4& vector)
		{
			return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "}";
		}
	}
}