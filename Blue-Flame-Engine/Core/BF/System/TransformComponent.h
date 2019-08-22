#pragma once
#include "BF/System/ITransform.h"

namespace BF
{
	namespace System
	{
		template <class T>
		class TransformComponent : public ITransform
		{
		public:
			TransformComponent();
			virtual ~TransformComponent();
		};

#include "BF/System/TransformComponent.inl"

	}
}