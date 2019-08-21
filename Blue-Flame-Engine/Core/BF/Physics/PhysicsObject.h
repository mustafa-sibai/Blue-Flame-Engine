#pragma once
#include "BF/Physics/IPhysicsObject.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		template <class T>
		class PhysicsObject : public IPhysicsObject
		{
		public:
			PhysicsObject(Type type);
			virtual ~PhysicsObject();
		};

#include "PhysicsObject.inl"
	}
}