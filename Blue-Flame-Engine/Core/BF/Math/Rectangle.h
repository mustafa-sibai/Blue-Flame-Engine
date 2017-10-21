#pragma once
#include <iostream>
#include "BF/Math/Vector2.h"
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		struct BF_API Rectangle
		{
			int x, y, width, height;

			Rectangle();
			Rectangle(int x, int y, int width, int height);

			bool Intersect(const Rectangle& rectangle) const;
			Rectangle IntersectRectangle(const Rectangle& rectangle) const;
			int Area() const;
			Vector2 Center() const;

			friend Rectangle operator+(const Rectangle& leftRectangle, const Rectangle& rightRectangle);
			friend Rectangle operator-(const Rectangle& leftRectangle, const Rectangle& rightRectangle);
			friend Rectangle operator*(const Rectangle& leftRectangle, const Rectangle& rightRectangle);
			friend Rectangle operator/(const Rectangle& leftRectangle, const Rectangle& rightRectangle);

			Rectangle& operator+=(const Rectangle& right);
			Rectangle& operator-=(const Rectangle& right);
			Rectangle& operator*=(const Rectangle& right);
			Rectangle& operator/=(const Rectangle& right);

			bool operator>(const Rectangle& right);
			bool operator>=(const Rectangle& right);
			bool operator<(const Rectangle& right);
			bool operator<=(const Rectangle& right);

			bool operator==(const Rectangle& right);
			bool operator!=(const Rectangle& right);

			friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
		};
	}
}