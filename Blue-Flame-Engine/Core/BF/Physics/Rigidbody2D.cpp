#include "Rigidbody2D.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::Math;

		Rigidbody2D::Rigidbody2D() :
			PhysicsObject(PhysicsObject::Type::Rigidbody2D),
			useGravity(false), speed(0), direction(0)
		{
			//if (useGravity)
			//direction = Vector2f(0.5f, 1.0f);
		}

		Rigidbody2D::~Rigidbody2D()
		{
		}

		/*BF::Math::Rectangle Rigidbody2D::CheckNextFrameCollision()
		{
			BF::Math::Rectangle rectangle = renderable.GetRectangle();

			rectangle.x += (int)veclotiy.x;
			rectangle.y += (int)veclotiy.y;

			return rectangle;
		}*/
	}
}