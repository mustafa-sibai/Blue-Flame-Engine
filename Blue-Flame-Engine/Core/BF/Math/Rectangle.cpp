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

		Rectangle::Rectangle(int x, int y, int width, int height, const Vector2f& pivot) :
			x(x), y(y), width(width), height(height), pivot(pivot)
		{
		}

		bool Rectangle::Intersect(const Rectangle& other) const
		{
			Rectangle thisEdge = GetEdgeOffset();
			Rectangle otherEdge = other.GetEdgeOffset();

			int x = this->x + thisEdge.x;
			int y = this->y + thisEdge.y;

			int otherX = other.x + otherEdge.x;
			int otherY = other.y + otherEdge.y;

			if (otherX < x + width && otherX + other.width > x &&
				otherY > y - height && otherY - other.height < y)
				return true;

			return false;
		}

		Rectangle Rectangle::GetRectangleIntersectionArea(const Rectangle& rectangle) const
		{
			if (Intersect(rectangle))
			{
				int left	= Max(x,			rectangle.x);
				int right	= Min(x + width,	rectangle.x + rectangle.width);
				int top		= Max(y,			rectangle.y);
				int bottom	= Min(y + height,	rectangle.y + rectangle.height);

				int width	= abs(left - right);
				int height	= abs(top - bottom);

				return Rectangle(left, top, width, height, Vector2f(0, 0));
			}

			return Rectangle(0, 0, 0, 0, Vector2f(0, 0));
		}

		int Rectangle::Area() const
		{
			return width * height;
		}

		Vector2i Rectangle::Center() const
		{
			return Vector2i(x + (width / 2), y + (height / 2));
		}

		Rectangle Rectangle::GetEdgeOffset() const
		{
			int offsetWidth = (int)(width * pivot.x);
			int offsetHeight = (int)(height * pivot.y);

			return Rectangle(-offsetWidth, offsetHeight, width - offsetWidth, offsetHeight - height, pivot);
		}

		vector<Vector2i> Rectangle::GetCorners() const
		{
			Rectangle edges = GetEdgeOffset();

			vector<Vector2i> corners(4);

			corners[0] = Vector2i(x + edges.x,		y + edges.y);
			corners[1] = Vector2i(x + edges.width,	y + edges.y);
			corners[2] = Vector2i(x + edges.width,	y + edges.height);
			corners[3] = Vector2i(x + edges.x,		y + edges.height);

			return corners;
		}

		bool Rectangle::operator>(const Rectangle& right)
		{
			return Area() > right.Area();
		}

		bool Rectangle::operator>=(const Rectangle& right)
		{
			return Area() >= right.Area();
		}

		bool Rectangle::operator<(const Rectangle& right)
		{
			return Area() < right.Area();
		}

		bool Rectangle::operator<=(const Rectangle& right)
		{
			return Area() <= right.Area();
		}

		bool Rectangle::operator==(const Rectangle& right)
		{
			return Area() == right.Area();
		}

		bool Rectangle::operator!=(const Rectangle& right)
		{
			return !(*this == right);
		}
	}
}