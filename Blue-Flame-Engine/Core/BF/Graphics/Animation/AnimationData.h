#pragma once
#include <string>
#include <vector>
#include "BF/IO/Resource.h"
#include "BF/Graphics/Animation/Sequence.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			struct AnimationData : public BF::IO::Resource
			{
				std::string textureName;
				std::vector<Sequence>* sequences;

				AnimationData(const std::string& textureName, std::vector<Sequence>* sequences) :
					textureName(textureName), sequences(sequences),
					BF::IO::Resource(Type::Animation)
				{
				}
			};
		}
	}
}