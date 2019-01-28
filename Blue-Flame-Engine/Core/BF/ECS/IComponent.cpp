#include "IComponent.h"

namespace BF
{
	namespace ECS
	{
		int IComponent::globalID = 0;

		IComponent::IComponent() :
			id(0), added(false)
		{
			IComponent::globalID++;
			id = globalID;
		}

		IComponent::~IComponent()
		{
		}
	}
}