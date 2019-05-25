#pragma once
#include <vector>
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			class BFE_API Node
			{
			public:
				float gValue;
				float hValue;
				float fValue;
				bool walkable;
				bool inClosedList;
				std::vector<Node> neighbours;
				Node* parent;

			public:
				Node();
				~Node();
			};
		}
	}
}