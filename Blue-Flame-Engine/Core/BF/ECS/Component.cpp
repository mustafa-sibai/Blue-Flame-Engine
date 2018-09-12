#include "Component.h"

namespace BF
{
	namespace ECS
	{
		int Component::globalID = 0;

		Component::Component() :
			id(0), type(Type::Null), added(false)
		{
			Component::globalID++;
			id = globalID;
		}

		Component::~Component()
		{
		}
	}
}
