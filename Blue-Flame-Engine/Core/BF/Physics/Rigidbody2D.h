#pragma once
#include "BF/Math/Vector2.h"
#include "BF/Physics/PhysicsObject.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class BFE_API Rigidbody2D : public PhysicsObject<Rigidbody2D>
		{
		public:
			bool useGravity;
			float speed;
			BF::Math::Vector2f direction;
			BF::Math::Vector2f veclotiy;
			bool correctCollisionPosition = false;

		public:
			Rigidbody2D();
			virtual ~Rigidbody2D();
		};
	}
}