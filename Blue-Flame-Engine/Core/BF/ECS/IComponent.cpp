#include "IComponent.h"

namespace BF
{
	namespace ECS
	{
		int IComponent::globalID = 0;

		IComponent::IComponent(Type type) :
			type(type), id(0), added(false), gameObject(nullptr)
		{
			IComponent::globalID++;
			id = globalID;
		}

		IComponent::~IComponent()
		{
		}
	}
}