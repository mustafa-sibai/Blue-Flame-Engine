#include "AstarNode.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			AstarNode::AstarNode() :
				AstarComponent(AstarComponent::Type::AstarNode),
				gValue(0), hValue(0), fValue(0), walkable(false), inClosedList(false), parent(nullptr)
			{
			}

			AstarNode::~AstarNode()
			{
			}
		}
	}
}