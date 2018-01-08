#pragma once
#include <vector>
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class BF_API PhysicsLayer
			{
				private:
					//std::vector<PhysicsObject> physicsObjects;

				public:
					PhysicsLayer();
					~PhysicsLayer();

					void Add(/*const PhysicsObject& physicsObject*/);
					void Remove(/*const PhysicsObject& physicsObject*/);
			};
		}
	}
}