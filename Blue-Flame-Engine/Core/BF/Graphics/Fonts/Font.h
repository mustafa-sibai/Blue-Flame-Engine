#pragma once
#include "BF/Graphics/Fonts/FontAtlasFactory.h"
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
			class BFE_API Font
			{;
				friend class BF::Graphics::Renderers::SpriteRendererComponents::Text;
				friend class BF::Graphics::Renderers::SpriteRenderer;

				private:
					FontAtlas* fontAtlas;

				public:
					Font();
					~Font();

					void Load(const std::string& filename, unsigned int charPixelSize, FontAtlasFactory::Language language);

					inline const std::string& GetName() const { return fontAtlas->fontName; }
					inline unsigned int GetPixelSize() const { return fontAtlas->fontPixelSize; }
			};
		}
	}
}