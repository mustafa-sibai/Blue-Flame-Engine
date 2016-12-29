#pragma once
#include <string>
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Math/Math.h"
#include "Character.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			class FontAtlas
			{
				public:
					std::string fontName;
					unsigned int textSize;
					const API::Texture2D* texture;
					const std::vector<Character>* characters;

				FontAtlas(const std::string& fontName, unsigned int textSize, const API::Texture2D* texture, const std::vector<Character>* characters) :
					fontName(fontName), textSize(textSize), texture(texture), characters(characters)
				{
				}
			};
		}
	}
}