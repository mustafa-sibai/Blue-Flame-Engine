#pragma once
#include <iostream>

namespace BF
{
	namespace Math
	{
		struct Rectangle
		{
			int x = 0, y = 0, width = 0, height = 0;

			Rectangle() { }
			Rectangle(const int &x, const int &y, const int &width, const int &height) : x(x), y(y), width(width), height(height) {}

			friend const Rectangle operator+(const Rectangle &leftRectangle, const Rectangle &rightRectangle) { return Rectangle(leftRectangle.x + rightRectangle.x, leftRectangle.y + rightRectangle.y, leftRectangle.width + rightRectangle.width, leftRectangle.height + rightRectangle.height); }
			friend const Rectangle operator-(const Rectangle &leftRectangle, const Rectangle &rightRectangle) { return Rectangle(leftRectangle.x - rightRectangle.x, leftRectangle.y - rightRectangle.y, leftRectangle.width - rightRectangle.width, leftRectangle.height * rightRectangle.height); }
			friend const Rectangle operator*(const Rectangle &leftRectangle, const Rectangle &rightRectangle) { return Rectangle(leftRectangle.x * rightRectangle.x, leftRectangle.y * rightRectangle.y, leftRectangle.width * rightRectangle.width, leftRectangle.height * rightRectangle.height); }
			friend const Rectangle operator/(const Rectangle &leftRectangle, const Rectangle &rightRectangle) { return Rectangle(leftRectangle.x / rightRectangle.x, leftRectangle.y / rightRectangle.y, leftRectangle.width / rightRectangle.width, leftRectangle.height / rightRectangle.height); }

			friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) { return os << "{" << rectangle.x << ", " << rectangle.y << ", " << rectangle.width << ", " << rectangle.height << "}"; }
		};
	}
}