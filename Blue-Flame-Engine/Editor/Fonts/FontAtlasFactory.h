#pragma once
#include <iostream>
#include <ft2build.h>
#include "BF/Graphics/Fonts/Font.h"

#include FT_FREETYPE_H

namespace Editor
{
	namespace Fonts
	{
		class FontAtlasFactory
		{
		private:
			FT_Library library;
			FT_Error error;
			FT_Face face;

			bool freeTypeInitialized;

			int startUnicode;
			int endUnicode;

		public:
			enum class Language
			{
				Null, English
			};

		public:
			FontAtlasFactory();
			~FontAtlasFactory();

			BF::Graphics::Fonts::Font* GetFont(const std::string& filename, int charPixelSize, Language language);
		
		private:
			void LoadFont(const std::string& filename);
			BF::Graphics::Fonts::Font* Create(const std::string& fontName, int charPixelSize, Language language);

			void PrepareGlyph(int unicode);
			void CalculateTextureAtelsSize(int totalGlyphs, int glyphWidth, int glyphHeight, int& width, int& height);
		};
	}
}