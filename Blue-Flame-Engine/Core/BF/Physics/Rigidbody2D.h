#pragma once
#include "BF/Math/Vector2.h"
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class BF_API Rigidbody2D
		{
			public:
				BF::Graphics::Renderers::Renderable& renderable;

				bool useGravity;
				float speed;
				Math::Vector2f direction;
				Math::Vector2f veclotiy;
				//Math::Vector2 testVeclotiy;
				bool correctCollisionPosition = false;

			public:
				Rigidbody2D(BF::Graphics::Renderers::Renderable& renderable);
				~Rigidbody2D();

				void Update();
				BF::Math::Rectangle CheckNextFrameCollision();
		};
	}
}