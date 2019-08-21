#include "ICollider.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::ECS;

		ICollider::ICollider(Type type) :
			PhysicsObject(PhysicsObject::Type::Collider),
			type(type)
		{
		}

		ICollider::~ICollider()
		{
		}
	}
}