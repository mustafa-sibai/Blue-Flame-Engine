#pragma once
#include <string>
#include <vector>
#include "BF/IO/Resource.h"
#include "BF/Graphics/Animation/KeyFrame.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			struct SpriteAnimationData : public BF::IO::Resource
			{
				std::string textureName;
				std::vector<KeyFrame> keyFrames;

				SpriteAnimationData() : BF::IO::Resource(Type::Animation) { }
			};
		}
	}
}