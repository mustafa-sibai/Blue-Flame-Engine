#include "Font.h"

namespace BF
{
	namespace Graphics
	{
		Font::Font(const API::Context* context, const API::Shader* shader) :
			textureAtlas(nullptr), texture(nullptr)
		{
			texture = new API::Texture2D(context, shader);
			textureAtlas = new TextureAtlas();
			

			error = FT_Init_FreeType(&library);
			if (error != FT_Err_Ok)
				std::cout << "ERROR !!" << std::endl;
			else
				std::cout << "OK !!" << std::endl;

			error = FT_New_Face(library, "Assets/Fonts/arial.ttf", 0, &face);

			if (error == FT_Err_Unknown_File_Format)
				std::cout << "ERROR: Unknown File Format !!" << std::endl;
			else if (error)
				std::cout << "ERROR: file not found !!" << std::endl;

			std::cout << "family_name: " << face->family_name << " style_name: " << face->style_name << std::endl;
			std::cout << "face_index: " << face->face_index << " num_faces: " << face->num_faces << " num_glyphs: " << face->num_glyphs << std::endl;

			error = FT_Set_Pixel_Sizes(face, 0, 48);
			if (error != FT_Err_Ok)
				std::cout << "ERROR !!" << std::endl;
			else
				std::cout << "OK !!" << std::endl;


			int smallestUnicode = 0x00000020;
			int biggestUnicode = 0x0000007E;

			int rowsAndColumnsSize = ceil(sqrt(biggestUnicode - smallestUnicode));
			int altalSize = 48 * rowsAndColumnsSize;

			textureAtlas->Create(altalSize, altalSize, API::Texture::Format::R8);


			for (unsigned int y = 0; y < rowsAndColumnsSize; y++)
			{
				for (unsigned int x = 0; x < rowsAndColumnsSize; x++)
				{
					int unicode = smallestUnicode + (x + y * rowsAndColumnsSize);

					if (unicode <= biggestUnicode)
					{
						PrepareGlyph(unicode);
						textureAtlas->AddTexture(Math::Rectangle(x * 48, y * 48, face->glyph->bitmap.width, face->glyph->bitmap.rows), face->glyph->bitmap.buffer);
					}
				}
			}

			texture->Create(textureAtlas->GetWidth(), textureAtlas->GetHeight(), BF::Graphics::API::Texture2D::Format::R8, textureAtlas->GetBuffer());
		}

		Font::~Font()
		{
		}

		void Font::PrepareGlyph(unsigned int unicode)
		{
			FT_UInt glyph_index = FT_Get_Char_Index(face, unicode);

			error = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
			if (error != FT_Err_Ok)
				std::cout << "ERROR !!" << std::endl;
			else
				std::cout << "a OK !!" << std::endl;

			error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

			if (error != FT_Err_Ok)
				std::cout << "ERROR !!" << std::endl;
			else
				std::cout << "a OK !!" << std::endl;
		}
	}
}