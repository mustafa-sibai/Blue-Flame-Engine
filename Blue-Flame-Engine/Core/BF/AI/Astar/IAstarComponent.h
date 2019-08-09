#pragma once
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			class AstarSystem;

			class BFE_API IAstarComponent : public BF::ECS::Component<IAstarComponent>
			{
				friend class BF::AI::Astar::AstarSystem;

			public:
				enum class Type { None, AstarNode, AstarAgent };
				Type type;

			public:
				IAstarComponent(Type type);
				virtual ~IAstarComponent();
			};
		}
	}
}