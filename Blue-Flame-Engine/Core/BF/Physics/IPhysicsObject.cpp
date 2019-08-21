#include "IPhysicsObject.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::ECS;

		IPhysicsObject::IPhysicsObject(Type type) :
			Component(IComponent::Type::Physics),
			type(type)
		{
		}

		IPhysicsObject::~IPhysicsObject()
		{
		}
	}
}