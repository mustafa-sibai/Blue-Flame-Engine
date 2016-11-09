#include "Rectangle.h"

namespace BF
{
	namespace Math
	{
		using namespace std;

		Rectangle::Rectangle() :
			x(0), y(0), width(0), height(0)
		{
		}

		Rectangle::Rectangle(const int& x, const int& y, const int& width, const int& height) :
			x(x), y(y), width(width), height(height)
		{
		}

		Rectangle operator+(const Rectangle& leftRectangle, const Rectangle& rightRectangle)
		{
			return Rectangle(leftRectangle.x + rightRectangle.x, leftRectangle.y + rightRectangle.y, leftRectangle.width + rightRectangle.width, leftRectangle.height + rightRectangle.height);
		}

		Rectangle operator-(const Rectangle& leftRectangle, const Rectangle& rightRectangle)
		{
			return Rectangle(leftRectangle.x - rightRectangle.x, leftRectangle.y - rightRectangle.y, leftRectangle.width - rightRectangle.width, leftRectangle.height * rightRectangle.height);
		}

		Rectangle operator*(const Rectangle& leftRectangle, const Rectangle& rightRectangle)
		{
			return Rectangle(leftRectangle.x * rightRectangle.x, leftRectangle.y * rightRectangle.y, leftRectangle.width * rightRectangle.width, leftRectangle.height * rightRectangle.height);
		}

		Rectangle operator/(const Rectangle& leftRectangle, const Rectangle& rightRectangle)
		{
			return Rectangle(leftRectangle.x / rightRectangle.x, leftRectangle.y / rightRectangle.y, leftRectangle.width / rightRectangle.width, leftRectangle.height / rightRectangle.height);
		}

		ostream& operator<<(ostream& os, const Rectangle& rectangle)
		{
			return os << "{" << rectangle.x << ", " << rectangle.y << ", " << rectangle.width << ", " << rectangle.height << "}";
		}
	}
}