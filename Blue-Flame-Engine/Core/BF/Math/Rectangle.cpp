#include "Rectangle.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Math
	{
		using namespace std;

		std::vector<Vector2i> corners(4);

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

		Rectangle::~Rectangle()
		{
		}

		bool Rectangle::Intersect(const Rectangle& other) const
		{
			Rectangle thisEdge = GetEdgeOffsetByPivot();
			Rectangle otherEdge = other.GetEdgeOffsetByPivot();

			if (otherEdge.x < thisEdge.x + width && otherEdge.x + other.width > x &&
				otherEdge.y > thisEdge.y - height && otherEdge.y - other.height < y)
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

		Rectangle Rectangle::GetEdgeOffsetByPivot() const
		{
			int offsetWidth = (int)(width * pivot.x);
			int offsetHeight = (int)(height * pivot.y);

			return Rectangle(x - offsetWidth, y + offsetHeight, width - offsetWidth + x, offsetHeight - height + y, pivot);
		}

		vector<Vector2i>& Rectangle::GetCorners()
		{
			Rectangle edges = GetEdgeOffsetByPivot();

			corners[0] = Vector2i(edges.x,		edges.y);
			corners[1] = Vector2i(edges.width,	edges.y);
			corners[2] = Vector2i(edges.width,	edges.height);
			corners[3] = Vector2i(edges.x,		edges.height);

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