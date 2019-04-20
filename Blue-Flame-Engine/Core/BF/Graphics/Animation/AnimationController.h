#pragma once
#include <vector>
#include "BF/Graphics/Animation/StartingAnimationNode.h"
//#include "BF/Graphics/Animation/AnimationNode.h"
#include "BF/Graphics/Animation/DataType.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API AnimationController
			{
			public:
				StartingAnimationNode* startingAnimationNode;
				IAnimationNode* currentAnimationNode;

				std::vector<IDataType*> dataTypes;

				AnimationController();
				~AnimationController();
			};
		}
	}
}