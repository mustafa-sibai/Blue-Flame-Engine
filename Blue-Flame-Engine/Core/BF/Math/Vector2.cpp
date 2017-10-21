#include "Vector2.h"
#include "BF/System/Log.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Math
	{
		Vector2::Vector2() :
			x(0.0f), y(0.0f)
		{
		}

		Vector2::Vector2(float value) :
			x(value), y(value)
		{
		}

		Vector2::Vector2(float x, float y) :
			x(x), y(y)
		{
		}

		Vector2::~Vector2()
		{
		}

		float Vector2::Dot(const Vector2& vector) const
		{
			return x * vector.x + y * vector.y;
		}

		float Vector2::Distance(const Vector2& vector) const
		{
			Vector2 d = Direction(vector);
			return sqrt((d.x * d.x + d.y * d.y));
		}

		float Vector2::Magnitude() const
		{
			return (float)sqrt(Dot(*this));
		}

		Vector2 Vector2::Direction(const Vector2& vector) const
		{
			return Vector2(abs(vector.x - x), abs(vector.y - y));
		}

		Vector2 Vector2::Normalize() const
		{
			float length = Magnitude();

			if (length > 0)
				return Vector2(x / length, y / length);
			else
				return Vector2(0);
		}

		Vector2 Vector2::Center() const
		{
			return Vector2(x / 2, y / 2);
		}

		Vector2 Vector2::Min()
		{
			return Vector2(Math::Min(x, y));
		}

		Vector2 Vector2::Max()
		{
			return Vector2(Math::Max(x, y));
		}

		Vector2 operator+(const Vector2& left, const Vector2& right)
		{
			return Vector2(left.x + right.x, left.y + right.y);
		}

		Vector2 operator-(const Vector2& left, const Vector2& right)
		{
			return Vector2(left.x - right.x, left.y - right.y);
		}

		Vector2 operator*(const Vector2& left, const Vector2& right)
		{
			return Vector2(left.x * right.x, left.y * right.y);
		}

		Vector2 operator/(const Vector2& left, const Vector2& right)
		{
			return Vector2(left.x / right.x, left.y / right.y);
		}

		Vector2& Vector2::operator+=(const Vector2& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}

		Vector2& Vector2::operator-=(const Vector2& right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}

		Vector2& Vector2::operator*=(const Vector2& right)
		{
			x *= right.x;
			y *= right.y;
			return *this;
		}

		Vector2& Vector2::operator/=(const Vector2& right)
		{
			x /= right.x;
			y /= right.y;
			return *this;
		}

		bool Vector2::operator>(const Vector2& right)
		{
			return Magnitude() > right.Magnitude();
		}

		bool Vector2::operator>=(const Vector2& right)
		{
			return Magnitude() >= right.Magnitude();
		}

		bool Vector2::operator<(const Vector2& right)
		{
			return Magnitude() < right.Magnitude();
		}

		bool Vector2::operator<=(const Vector2& right)
		{
			return Magnitude() <= right.Magnitude();
		}

		bool Vector2::operator==(const Vector2 &right)
		{
			return x == right.x && y == right.y;
		}

		bool Vector2::operator!=(const Vector2 &right)
		{
			return !(*this == right);
		}

		std::ostream& operator<<(std::ostream& os, const Vector2& vector)
		{
			return os << "{" << vector.x << ", " << vector.y << "}";
		}
	}
}