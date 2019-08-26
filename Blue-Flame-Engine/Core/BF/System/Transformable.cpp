#include "Transformable.h"

namespace BF
{
	namespace System
	{
		Transformable::Transformable(Type type) :
			type(type), updatePivotAndSize(false)
		{
		}

		Transformable::~Transformable()
		{
		}
	}
}