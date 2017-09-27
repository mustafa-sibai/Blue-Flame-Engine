#pragma once
#include <vector>
#include "BF/Physics/Rigidbody2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class BF_API PhysicsEngine
		{
			private:
				static std::vector<BF::Physics::Rigidbody2D*> rigidbodies;

			public:
				static void Add(BF::Physics::Rigidbody2D* rigidbody2D);
				static void Update();
		};
	}
}