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
				direction = Vector2(0.1f, 1.0f);
		}

		Rigidbody2D::~Rigidbody2D()
		{
		}

		void Rigidbody2D::Update()
		{
			renderable.SetPosition(renderable.GetPosition() + veclotiy);
			veclotiy += direction * speed;

			BF_LOG_INFO("%f, %f", veclotiy.x, veclotiy.y);
		}
	}
}