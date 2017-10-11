#include "Rigidbody2D.h"
#include "BF/System/Log.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::Math;

		Rigidbody2D::Rigidbody2D(BF::Graphics::Renderers::Renderable& renderable) :
			useGravity(false), speed(1.5f), renderable(renderable)
		{
			//if (useGravity)
			direction = Vector2(0.5f, 1.0f);
		}

		Rigidbody2D::~Rigidbody2D()
		{
		}

		void Rigidbody2D::Update()
		{
			renderable.SetPosition(renderable.GetPosition() + veclotiy);
			veclotiy += direction * speed;
		}

		BF::Math::Rectangle Rigidbody2D::CheckNextFrameCollision()
		{
			BF::Math::Rectangle rectangle = renderable.GetRectangle();

			rectangle.x += veclotiy.x;
			rectangle.y += veclotiy.y;

			return rectangle;
		}
	}
}