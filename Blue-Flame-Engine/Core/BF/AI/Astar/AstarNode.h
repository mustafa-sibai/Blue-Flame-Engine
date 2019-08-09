#pragma once
#include <vector>
#include "BF/AI/Astar/AstarComponent.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			class BFE_API AstarNode : public AstarComponent<AstarNode>
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