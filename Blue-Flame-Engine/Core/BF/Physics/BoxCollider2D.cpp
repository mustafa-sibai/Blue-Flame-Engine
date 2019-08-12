#include "BoxCollider2D.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::Math;

		BoxCollider2D::BoxCollider2D() :
			Collider(Type::BoxCollider2D),
			x(0), y(0), width(0), height(0), pivot(),
			leftEdge(0), rightEdge(0), topEdge(0), bottomEdge(0)
		{
		}

		BoxCollider2D::BoxCollider2D(int x, int y, int width, int height) :
			Collider(Type::BoxCollider2D),
			x(x), y(y), width(width), height(height), pivot(0.5f),
			leftEdge(0), rightEdge(0), topEdge(0), bottomEdge(0)
		{
		}

		BoxCollider2D::BoxCollider2D(int x, int y, int width, int height, const Vector2f& pivot) :
			Collider(Type::BoxCollider2D),
			x(x), y(y), width(width), height(height), pivot(pivot),
			leftEdge(0), rightEdge(0), topEdge(0), bottomEdge(0)
		{
		}

		BoxCollider2D::~BoxCollider2D()
		{
		}

		void BoxCollider2D::CalculateEdges(int offsetX, int offsetY)
		{
			int offsetWidth		= (int)(width * pivot.x);
			int offsetHeight	= (int)(height * pivot.y);

			leftEdge			= offsetX - x - offsetWidth;
			rightEdge			= width - offsetWidth + x + offsetX;
			topEdge				= offsetY + y + offsetHeight;
			bottomEdge			= offsetHeight - height + y + offsetY;
		}
	}
}