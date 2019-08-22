#pragma once
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BFE_API ITransform : public BF::ECS::Component<ITransform>
		{
		public:
			ITransform();
			virtual ~ITransform();
		};
	}
}