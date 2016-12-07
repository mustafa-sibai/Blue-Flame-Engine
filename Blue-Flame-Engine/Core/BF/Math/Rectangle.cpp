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

		Rectangle::Rectangle(int x, int y, int width, int height) :
			x(x), y(y), width(width), height(height)
		{
		}

		bool Rectangle::Intersect(const Rectangle& rectangle)
		{
			if (y < rectangle.y + rectangle.height && y + height > rectangle.y && x + width > rectangle.x && x < rectangle.x + rectangle.width)
				return true;

			return false;
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