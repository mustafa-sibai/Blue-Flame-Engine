#pragma once
#include <string>
#include <vector>
#include "BF/Math/Vector2.h"
#include "BF/Common.h"

namespace BF
{
	namespace Math
	{
		class BFE_API Rectangle
		{
		public:
			int x, y, width, height;
			Vector2f pivot;

			Rectangle();
			Rectangle(int x, int y, int width, int height);
			Rectangle(int x, int y, int width, int height, const Vector2f& pivot);
			~Rectangle();

			bool Intersect(const Rectangle& other) const;
			Rectangle GetRectangleIntersectionArea(const Rectangle& rectangle) const;
			int Area() const;
			Vector2i Center() const;

			/*
			Returns where all four edges of a rectangle position should be depending on the pivot point
			x		= left
			width	= right
			y		= top
			hieght	= bottom
			@pivot:
			Top left = 0, 0
			Top right = 1, 0
			Center = 0.5f, 0.5f
			Bottom right = 1, 1
			Bottom left = 0, 1
			*/
			Rectangle GetEdgeOffsetByPivot() const;

			/*
			Returns where all four edges of a rectangle position should be depending on the pivot point at the origin
			x		= left
			width	= right
			y		= top
			hieght	= bottom
			@pivot:
			Top left = 0, 0
			Top right = 1, 0
			Center = 0.5f, 0.5f
			Bottom right = 1, 1
			Bottom left = 0, 1
			*/
			Rectangle GetEdgeOffsetByPivotAtOrigin() const;

			friend std::string operator+(const std::string& left, const Rectangle& right) { return left + "{" + std::to_string(right.x) + ", " + std::to_string(right.y) + ", " + std::to_string(right.width) + ", " + std::to_string(right.height) + "}"; }
			friend std::string operator+(const Rectangle& left, const std::string& right) { return "{" + std::to_string(left.x) + ", " + std::to_string(left.y) + ", " + std::to_string(left.width) + ", " + std::to_string(left.height) + "}" + right; }

			bool operator>(const Rectangle& right);
			bool operator>=(const Rectangle& right);
			bool operator<(const Rectangle& right);
			bool operator<=(const Rectangle& right);

			bool operator==(const Rectangle& right);
			bool operator!=(const Rectangle& right);

			friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) { return os << "{" << rectangle.x << ", " << rectangle.y << ", " << rectangle.width << ", " << rectangle.height << "}"; }
		};
	}
}