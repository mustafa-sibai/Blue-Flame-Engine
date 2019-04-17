#pragma once
#include <vector>
#include "BF/Graphics/Animation/AnimationNode.h"
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
				std::vector<BF::Graphics::Animation::AnimationNode> nodes;
				std::vector<BF::Graphics::Animation::IDataType> dataTypes;

				AnimationController();
				~AnimationController();
			};
		}
	}
}