#pragma once
#include <string>
#include "BF/Math/Math.h"
#include "BF/Graphics/Fonts/Character.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/IO/Resource.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			struct BFE_API FontAtlas : public BF::IO::Resource
			{
				std::string fontName;

				unsigned int fontPixelSize;
				float fontMaxYBearing;

				const API::Texture2D* texture;
				const std::vector<Character>* characters;

				FontAtlas(const std::string& fontName, unsigned int fontPixelSize, float fontMaxYBearing, const API::Texture2D* texture, const std::vector<Character>* characters) :
					fontName(fontName), fontPixelSize(fontPixelSize), fontMaxYBearing(fontMaxYBearing), texture(texture), characters(characters), Resource(BF::IO::Resource::Type::Font)
				{
				}
			};
		}
	}
}