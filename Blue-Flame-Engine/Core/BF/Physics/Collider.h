#pragma once
#include "BF/Physics/ICollider.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		template <class T>
		class Collider : public ICollider
		{
		public:
			Collider(Type type);
			virtual ~Collider();
		};

#include "Collider.inl"
	}
}