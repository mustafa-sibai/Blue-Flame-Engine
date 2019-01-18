#include "Component.h"

namespace BF
{
	namespace ECS
	{
		int Component::globalID = 0;

		Component::Component(Type type) :
			id(0), type(type), added(false)
		{
			Component::globalID++;
			id = globalID;
		}

		Component::~Component()
		{
		}
	}
}
