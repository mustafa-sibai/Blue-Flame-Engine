#include "Transformable.h"

namespace BF
{
	namespace System
	{
		Transformable::Transformable(Type type) :
			type(type), update(false)
		{
		}

		Transformable::~Transformable()
		{
		}
	}
}