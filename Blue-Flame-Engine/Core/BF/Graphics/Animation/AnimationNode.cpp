#include "AnimationNode.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			AnimationNode::AnimationNode() :
				IAnimationNode(Type::NormalNode),
				animation(nullptr)
			{
			}

			AnimationNode::~AnimationNode()
			{
			}
		}
	}
}