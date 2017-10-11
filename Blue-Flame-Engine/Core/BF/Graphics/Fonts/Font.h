#pragma once
#include "BF/Graphics/Fonts/FontAtlasFactory.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class Text;
			class SpriteRenderer;
		}

		namespace Fonts
		{
			class BF_API Font
			{
				friend class BF::Graphics::Renderers::Text;
				friend class BF::Graphics::Renderers::SpriteRenderer;

				private:
					const API::Shader& shader;
					FontAtlas* fontAtlas;

				public:
					Font(const API::Shader& shader);
					~Font();

					void Load(const std::string& filename, unsigned int charPixelSize, FontAtlasFactory::Language language);

					inline const std::string& GetName() const { return fontAtlas->fontName; }
					inline unsigned int GetPixelSize() const { return fontAtlas->fontPixelSize; }
			};
		}
	}
}