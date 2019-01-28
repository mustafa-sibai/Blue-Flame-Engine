#include "Rigidbody2D.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::Math;

		Rigidbody2D::Rigidbody2D(BF::Graphics::Renderers::SpriteRendererComponents::IRenderable& renderable) :
			useGravity(false), speed(1.5f), renderable(renderable)
		{
			//if (useGravity)
			direction = Vector2f(0.5f, 1.0f);
		}

		Rigidbody2D::~Rigidbody2D()
		{
		}

		void Rigidbody2D::Update()
		{
			//renderable.SetPosition(renderable.GetPosition() + veclotiy);
			veclotiy += direction * speed;
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