#pragma once
#include <vector>
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			class BFE_API AstarNode : public BF::ECS::Component<AstarNode>
			{
			public:
				float gValue;
				float hValue;
				float fValue;
				bool walkable;
				bool inClosedList;
				std::vector<AstarNode*> neighbours;
				AstarNode* parent;

			public:
				AstarNode();
				~AstarNode();
			};
		}
	}
}