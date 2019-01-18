#pragma once
#include <vector>
#include "BF/Physics/Rigidbody2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class BFE_API PhysicsEngine
		{
			private:
				static std::vector<Rigidbody2D*> rigidbodies;

			public:
				static void Add(Rigidbody2D* rigidbody2D);
				static void Update();
		};
	}
}