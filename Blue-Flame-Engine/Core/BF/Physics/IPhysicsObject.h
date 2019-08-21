#pragma once
#include "BF/ECS/GameObject.h"
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class PhysicsEngine;

		class BFE_API IPhysicsObject : public BF::ECS::Component<IPhysicsObject>
		{
			friend class BF::Physics::PhysicsEngine;

		protected:
			enum class Type { None, Rigidbody2D, Collider };
			Type type;

		public:
			IPhysicsObject(Type type);
			virtual ~IPhysicsObject();
		};
	}
}