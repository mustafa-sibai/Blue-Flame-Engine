#pragma once
#include <string>
#include "BF/Math/Math.h"
#include "BF/Graphics/Fonts/Character.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/IO/Resource.h"
#include "BF/Graphics/Fonts/Character.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class SpriteRenderer;

			namespace SpriteRendererComponents
			{
				class Text;
			}
		}

		namespace Fonts
		{
			class BFE_API Font : public BF::IO::Resource
			{
				friend class BF::Graphics::Renderers::SpriteRendererComponents::Text;
				friend class BF::Graphics::Renderers::SpriteRenderer;

			public:
				std::string fontName;

				unsigned int fontPixelSize;
				float fontMaxYBearing;

				API::Texture2D* texture;
				std::vector<Character>* characters;

			public:
				Font(const std::string& fontName, unsigned int fontPixelSize, float fontMaxYBearing, API::Texture2D* texture, std::vector<Character>* characters);
				~Font();
			};
		}
	}
}