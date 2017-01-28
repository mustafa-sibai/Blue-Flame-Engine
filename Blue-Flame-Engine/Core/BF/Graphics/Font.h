#pragma once
#include <iostream>
#include <ft2build.h>
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/TextureAtlas.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

#include FT_FREETYPE_H

namespace BF
{
	namespace Graphics
	{
		class BF_API Font
		{
			public:
				FT_Library library;
				FT_Error error;
				FT_Face face;

				TextureAtlas* textureAtlas;
				API::Texture2D* texture;

			public:
				Font(const API::Shader& shader);
				~Font();

				void PrepareGlyph(unsigned int unicode);
		};
	}
}