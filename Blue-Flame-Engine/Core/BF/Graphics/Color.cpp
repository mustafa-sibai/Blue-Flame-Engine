#include "Color.h"

namespace BF
{
	namespace Graphics
	{
		Color::Color() :
			r(0.0f), g(0.0f), b(0.0f), a(0.0f)
		{
		}

		Color::Color(float value) :
			r(value), g(value), b(value), a(value)
		{
		}

		Color::Color(float r, float g, float b, float a) :
			r(r), g(g), b(b), a(a)
		{
		}

		Color::~Color()
		{
		}

		Color Color::Normalize() const
		{
			return Color(r / 255, g / 255, b / 255, a / 255);
		}

		Color operator+(const Color& left, const Color& right)
		{
			return Color(left.r + right.r, left.g + right.g, left.b + right.b, left.a + right.a);
		}

		Color operator-(const Color& left, const Color& right)
		{
			return Color(left.r - right.r, left.g - right.g, left.b - right.b, left.a - right.a);
		}

		Color operator*(const Color& left, const Color& right)
		{
			return Color(left.r * right.r, left.g * right.g, left.b * right.b, left.a * right.a);
		}

		Color operator/(const Color& left, const Color& right)
		{
			return Color(left.r / right.r, left.g / right.g, left.b / right.b, left.a / right.a);
		}

		Color& Color::operator+=(const Color& right)
		{
			r += right.r;
			g += right.g;
			b += right.b;
			a += right.a;
			return *this;
		}

		Color& Color::operator-=(const Color& right)
		{
			r -= right.r;
			g -= right.g;
			b -= right.b;
			a -= right.a;
			return *this;
		}

		Color& Color::operator*=(const Color& right)
		{
			r *= right.r;
			g *= right.g;
			b *= right.b;
			a *= right.a;
			return *this;
		}

		Color& Color::operator/=(const Color& right)
		{
			r /= right.r;
			g /= right.g;
			b /= right.b;
			a /= right.a;
			return *this;
		}

		bool Color::operator>(const Color& right)
		{
			return r > right.r && g > right.g && b > right.b && a > right.a;
		}

		bool Color::operator>=(const Color& right)
		{
			return r >= right.r && g >= right.g && b >= right.b && a >= right.a;
		}

		bool Color::operator<(const Color& right)
		{
			return r < right.r && g < right.g && b < right.b && a < right.a;
		}

		bool Color::operator<=(const Color& right)
		{
			return r <= right.r && g <= right.g && b <= right.b && a <= right.a;
		}

		bool Color::operator==(const Color &right)
		{
			return r == right.r && g == right.g && b == right.b && a == right.a;
		}

		bool Color::operator!=(const Color &right)
		{
			return !(*this == right);
		}

		std::ostream& operator<<(std::ostream& os, const Color& color)
		{
			return os << "{" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << "}";
		}
	}
}