#include "ICollider.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::ECS;

		ICollider::ICollider(Type type) :
			Component(IComponent::Type::Physics),
			type(type)
		{
		}

		ICollider::~ICollider()
		{
		}
	}
}