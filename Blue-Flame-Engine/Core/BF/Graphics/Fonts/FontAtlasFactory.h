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
			class BFE_API FontAtlasFactory
			{
				private:
					static FT_Library library;
					static FT_Error error;
					static FT_Face face;

					static bool freeTypeInitialized;

					static int startUnicode;
					static int endUnicode;

				public:
					enum class Language
					{
						Null, English
					};

				private:
					FontAtlasFactory() = delete;
					~FontAtlasFactory() = delete;

				public:
					static FontAtlas* GetFontAtlas(const std::string& filename, int charPixelSize, Language language);

				public:
					static void LoadFont(const std::string& filename);
					static FontAtlas* Create(const std::string& fontName, int charPixelSize, Language language);
					static void PrepareGlyph(int unicode);
					static void CalculateTextureAtelsSize(int totalGlyphs, int glyphWidth, int glyphHeight, int& width, int& height);
			};
		}
	}
}