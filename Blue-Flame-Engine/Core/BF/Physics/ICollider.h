#pragma once
#include "BF/ECS/GameObject.h"
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class PhysicsEngine;

		class BFE_API ICollider : public BF::ECS::Component<ICollider>
		{
			friend class BF::Physics::PhysicsEngine;

		protected:
			enum class Type { None, BoxCollider2D };
			Type type;

		public:
			ICollider(Type type);
			virtual ~ICollider();
		};
	}
}