#include "AstarNode.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			AstarNode::AstarNode() :
				gValue(0), hValue(0), fValue(0), walkable(false), inClosedList(false), parent(nullptr)
			{
				IComponent::type = IComponent::Type::Astar;
			}

			AstarNode::~AstarNode()
			{
			}
		}
	}
}