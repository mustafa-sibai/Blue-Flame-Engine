#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API IAnimationNode
			{
				friend class AnimationSystem;

			public:
				enum class Type { StartingNode, NormalNode };

			protected:
				Type type;

			public:
				IAnimationNode(Type type) :
					type(type)
				{
				}
			};
		}
	}
}