#pragma once
#include <string>
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Math/Math.h"
#include "BF/Graphics/Fonts/Character.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			class BF_API FontAtlas
			{
				public:
					std::string fontName;

					unsigned int fontPixelSize;
					float fontMaxYBearing;

					const API::Texture2D* texture;
					const std::vector<Character>* characters;

				FontAtlas(const std::string& fontName, unsigned int fontPixelSize, float fontMaxYBearing, const API::Texture2D* texture, const std::vector<Character>* characters) :
					fontName(fontName), fontPixelSize(fontPixelSize), fontMaxYBearing(fontMaxYBearing), texture(texture), characters(characters)
				{
				}
			};
		}
	}
}