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
			textureAtlas->Create(512, 512, API::Texture::Format::R8);

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

			PrepareGlyph(0x00000041);
			textureAtlas->AddTexture(Math::Rectangle(0, 0, face->glyph->bitmap.width, face->glyph->bitmap.rows), face->glyph->bitmap.buffer);

			PrepareGlyph(0x00000042);
			textureAtlas->AddTexture(Math::Rectangle(100, 100, face->glyph->bitmap.width, face->glyph->bitmap.rows), face->glyph->bitmap.buffer);

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