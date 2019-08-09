#pragma once
#include "BF/AI/Astar/IAstarComponent.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			template <class T>
			class AstarComponent : public BF::AI::Astar::IAstarComponent
			{
			public:
				AstarComponent(Type type);
				virtual ~AstarComponent();
			};

#include "AstarComponent.inl"
		}
	}
}