#include "Rectangle.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Math
	{
		using namespace std;

		Rectangle::Rectangle() :
			x(0), y(0), width(0), height(0)
		{
		}

		Rectangle::Rectangle(int x, int y, int width, int height) :
			x(x), y(y), width(width), height(height)
		{
		}

		bool Rectangle::Intersect(const Rectangle& rectangle) const
		{
			if (y < rectangle.y + rectangle.height && y + height > rectangle.y && x + width > rectangle.x && x < rectangle.x + rectangle.width)
				return true;

			return false;
		}

		Rectangle Rectangle::IntersectRectangle(const Rectangle& rectangle) const
		{
			if (Intersect(rectangle))
			{
				int left = Max(this->x, rectangle.x);
				int right = Min(this->x + this->width, rectangle.x + rectangle.width);
				int top = Max(this->y, rectangle.y);
				int bottom = Min(this->y + this->height, rectangle.y + rectangle.height);

				int width = abs(left - right);
				int height = abs(top - bottom);

				return Rectangle(left, top, width, height);
			}

			return Rectangle(0, 0, 0, 0);
		}

		int Rectangle::Area() const
		{
			return this->width * this->height;
		}

		Vector2i Rectangle::Center() const
		{
			return Vector2i(x + (width / 2), y + (height / 2));
		}

		void Rectangle::SetPivotPoint(Vector2f pivot)
		{
			int offsetWidth = (int)(this->width * pivot.x);
			int offsetHeight = (int)(this->height * pivot.y);

			this->x -= offsetWidth;
			this->y = offsetHeight - this->y;
			this->width -= offsetWidth;
			this->height = offsetHeight - this->height;
		}

		Rectangle& Rectangle::operator+=(const Rectangle& right)
		{
			this->x += right.x;
			this->y += right.y;
			this->width += right.width;
			this->height += right.height;
			return *this;
		}

		Rectangle& Rectangle::operator-=(const Rectangle& right)
		{
			this->x -= right.x;
			this->y -= right.y;
			this->width -= right.width;
			this->height -= right.height;
			return *this;
		}

		Rectangle& Rectangle::operator*=(const Rectangle& right)
		{
			this->x *= right.x;
			this->y *= right.y;
			this->width *= right.width;
			this->height *= right.height;
			return *this;
		}

		Rectangle& Rectangle::operator/=(const Rectangle& right)
		{
			this->x /= right.x;
			this->y /= right.y;
			this->width /= right.width;
			this->height /= right.height;
			return *this;
		}

		bool Rectangle::operator>(const Rectangle& right)
		{
			return this->Area() > right.Area();
		}

		bool Rectangle::operator>=(const Rectangle& right)
		{
			return this->Area() >= right.Area();
		}

		bool Rectangle::operator<(const Rectangle& right)
		{
			return this->Area() < right.Area();
		}

		bool Rectangle::operator<=(const Rectangle& right)
		{
			return this->Area() <= right.Area();
		}

		bool Rectangle::operator==(const Rectangle& right)
		{
			return this->Area() == right.Area();
		}

		bool Rectangle::operator!=(const Rectangle& right)
		{
			return !(*this == right);
		}

		Rectangle operator+(const Rectangle& left, const Rectangle& right)
		{
			return Rectangle(left.x + right.x, left.y + right.y, left.width + right.width, left.height + right.height);
		}

		Rectangle operator-(const Rectangle& left, const Rectangle& right)
		{
			return Rectangle(left.x - right.x, left.y - right.y, left.width - right.width, left.height * right.height);
		}

		Rectangle operator*(const Rectangle& left, const Rectangle& right)
		{
			return Rectangle(left.x * right.x, left.y * right.y, left.width * right.width, left.height * right.height);
		}

		Rectangle operator/(const Rectangle& left, const Rectangle& right)
		{
			return Rectangle(left.x / right.x, left.y / right.y, left.width / right.width, left.height / right.height);
		}
	}
}