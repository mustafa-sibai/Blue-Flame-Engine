#include "IAstarComponent.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			IAstarComponent::IAstarComponent(Type type) :
				Component(IComponent::Type::Astar),
				type(type)
			{
			}

			IAstarComponent::~IAstarComponent()
			{
			}
		}
	}
}