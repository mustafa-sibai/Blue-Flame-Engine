#include "StartingAnimationNode.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			StartingAnimationNode::StartingAnimationNode() :
				IAnimationNode(Type::StartingNode),
				transition(nullptr)
			{
			}

			StartingAnimationNode::~StartingAnimationNode()
			{
			}
		}
	}
}