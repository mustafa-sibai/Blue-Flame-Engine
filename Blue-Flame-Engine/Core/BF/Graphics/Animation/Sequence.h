#pragma once
#include <vector>
#include "BF/Graphics/Animation/KeyFrame.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			struct BFE_API Sequence
			{
				std::vector<KeyFrame>* keyframes;

				Sequence(std::vector<KeyFrame>* keyframes) :
					keyframes(keyframes)
				{
				}
			};
		}
	}
}