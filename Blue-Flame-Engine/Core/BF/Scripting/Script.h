#pragma once
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Scripting
	{
		class BF_API Script : public BF::ECS::Component
		{
			public:
				Script();
				~Script();

				virtual void Start();
				virtual void Update();
		};
	}
}