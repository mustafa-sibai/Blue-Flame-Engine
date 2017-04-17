#pragma once
#include <iostream>
#include "DependencyHeaders/FreeType/ft2build.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/TextureAtlas.h"
#include "BF/Graphics/Fonts/FontAtlas.h"
#include "BF/Graphics/Fonts/Character.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

#include FT_FREETYPE_H

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			class BF_API Font
			{
			private:
				unsigned int startUnicode, endUnicode;

			public:
				enum class Language
				{
					Null, English
				};

				FT_Library library;
				FT_Error error;
				FT_Face face;

				TextureAtlas textureAtlas;
				API::Texture2D* texture;

				unsigned int charPixelSize = 90;

			public:
				Font(const API::Shader& shader);
				~Font();

				FontAtlas* Load(const std::string& filename, Language language);
				

			private:
				void CreateTextureAtlas(int startUnicode, int endUnicode);
				void PrepareGlyph(unsigned int unicode);
				void CalculateTextureAtelsSize(unsigned int totalGlyphs, unsigned int glyphWidth, unsigned int glyphHeight, unsigned int& width, unsigned int& height);
			};
		}
	}
}