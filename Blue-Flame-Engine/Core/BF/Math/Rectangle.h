#pragma once
#include <iostream>
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		struct BF_API Rectangle
		{
			int x, y, width, height;

			Rectangle();
			Rectangle(const int& x, const int& y, const int& width, const int& height);

			friend Rectangle operator+(const Rectangle& leftRectangle, const Rectangle& rightRectangle);
			friend Rectangle operator-(const Rectangle& leftRectangle, const Rectangle& rightRectangle);
			friend Rectangle operator*(const Rectangle& leftRectangle, const Rectangle& rightRectangle);
			friend Rectangle operator/(const Rectangle& leftRectangle, const Rectangle& rightRectangle);

			friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
		};
	}
}