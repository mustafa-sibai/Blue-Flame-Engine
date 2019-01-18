#include "FontAtlasFactory.h"
#include "BF/System/Debug.h"
#include "BF/IO/ResourceManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Math;
			using namespace BF::IO;

			struct Glyph
			{
				unsigned int unicode;
				unsigned int width, height;
				unsigned int bufferSize;
				uint8_t* buffer;

				Vector2i bearing;
				Vector2i advance;

				Glyph() = default;
				Glyph(int unicode, int width, int height, const Vector2i& bearing, const Vector2i& advance, uint8_t* data) :
					unicode(unicode), width(width), height(height), bearing(bearing), advance(advance)
				{
					bufferSize = width * height;
					buffer = new uint8_t[bufferSize];
					memcpy(buffer, data, sizeof(uint8_t) * bufferSize);
				}
			};

			FT_Library FontAtlasFactory::library;
			FT_Error FontAtlasFactory::error;
			FT_Face FontAtlasFactory::face;

			bool FontAtlasFactory::freeTypeInitialized = false;

			int FontAtlasFactory::startUnicode = 0;
			int FontAtlasFactory::endUnicode = 0;
			
			FontAtlas* FontAtlasFactory::GetFontAtlas(const string& filename, int charPixelSize, Language language)
			{
				if (ResourceManager::Exist(filename + to_string(charPixelSize)))
				{
					return (FontAtlas*)ResourceManager::GetResource(filename + to_string(charPixelSize));
				}
				else
				{
					LoadFont(filename);

					ResourceManager::Add(filename + to_string(charPixelSize), Create(face->family_name, charPixelSize, language));
					return (FontAtlas*)ResourceManager::GetResource(filename + to_string(charPixelSize));
				}
			}

			void FontAtlasFactory::LoadFont(const string& filename)
			{
				if (!freeTypeInitialized)
				{
					error = FT_Init_FreeType(&library);
					if (error != FT_Err_Ok)
						BFE_LOG_ERROR("Could not initialize FreeType !", "");
					else
						freeTypeInitialized = true;
				}

				error = FT_New_Face(library, filename.c_str(), 0, &face);
				if (error == FT_Err_Unknown_File_Format)
					BFE_LOG_ERROR("FreeType: Unknown file format !", "");
				else if (error)
					BFE_LOG_ERROR("FreeType: file not found !", "");

				//cout << "family_name: " << face->family_name << " style_name: " << face->style_name << endl;
				//cout << "face_index: " << face->face_index << " num_faces: " << face->num_faces << " num_glyphs: " << face->num_glyphs << endl;
			}

			FontAtlas* FontAtlasFactory::Create(const string& fontName, int charPixelSize, Language language)
			{
				vector<Character>* characters = new vector<Character>();

				error = FT_Set_Pixel_Sizes(face, 0, charPixelSize);
				if (error != FT_Err_Ok)
					BFE_LOG_ERROR("FreeType: could not set pixel size !", "");

				if (language == Language::English)
				{
					startUnicode = 0x00000020;
					endUnicode = 0x0000007E;
				}

				const unsigned int totalGlyphs = endUnicode - startUnicode;

				vector<Glyph> glyph(totalGlyphs);
				int totalGlyphsWidth = 0;

				int maxYBearing = 0;

				for (size_t i = 0; i < totalGlyphs; i++)
				{
					int unicode = startUnicode + i;
					PrepareGlyph(unicode);

					if (face->glyph->bitmap.width == 0)
						face->glyph->bitmap.width = face->glyph->advance.x >> 6;

					if (face->glyph->metrics.horiBearingY > maxYBearing)
						maxYBearing = face->glyph->metrics.horiBearingY >> 6;

					glyph[i] = Glyph(unicode,
						face->glyph->bitmap.width, face->glyph->bitmap.rows,
						Vector2i(face->glyph->bitmap_left, face->glyph->bitmap_top),
						Vector2i(face->glyph->advance.x >> 6, face->glyph->advance.y >> 6), face->glyph->bitmap.buffer);

					totalGlyphsWidth += (int)face->glyph->bitmap.width;
				}

				int altalWidth, atlasHeight;
				CalculateTextureAtelsSize(totalGlyphs, totalGlyphsWidth, charPixelSize, altalWidth, atlasHeight);

				TextureAtlas textureAtlas;
				textureAtlas.Create(altalWidth, atlasHeight, Texture::Format::R8);

				for (int x = 0, y = 0, index = 0; index < totalGlyphs; )
				{
					if (x + glyph[index].width >= altalWidth)
					{
						y++;
						x = 0;
					}
					else
					{
						Rectangle scissorRectangle = Rectangle(x, charPixelSize * y, glyph[index].width, glyph[index].height);
						textureAtlas.AddTexture(scissorRectangle, glyph[index].buffer);

						characters->push_back(Character(Vector2f(), scissorRectangle, glyph[index].bearing, glyph[index].advance));
						x += (int)glyph[index].width;
						index++;
					}
				}

				Texture2D* texture = new Texture2D();
				texture->Create(*textureAtlas.GetTextureData(), Texture2D::Format::R8);
				FT_Done_Face(face);
				//FT_Done_FreeType(library);
				return new FontAtlas(fontName, charPixelSize, maxYBearing, texture, characters);
			}

			void FontAtlasFactory::PrepareGlyph(int unicode)
			{
				FT_UInt glyph_index = FT_Get_Char_Index(face, unicode);

				error = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
				if (error != FT_Err_Ok)
					cout << "ERROR !!" << endl;

				error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

				if (error != FT_Err_Ok)
					cout << "ERROR !!" << endl;
			}

			void FontAtlasFactory::CalculateTextureAtelsSize(int totalGlyphs, int totalGlyphsWidth, int glyphHeight, int& width, int& height)
			{
				float square = (float)ceil(sqrt(totalGlyphs));
				float glyphWidth = ceil((float)totalGlyphsWidth / totalGlyphs);
				width = (int)pow(2, ceil(log(square * glyphWidth) / log(2)));
				float columns = floor(width / (float)glyphWidth);
				float rows = ceil(totalGlyphs / columns);
				height = (int)pow(2, ceil(log(rows * glyphHeight) / log(2)));

				int temp = Max(height, width);
				height = Min(height, width);
				width = temp;
			}
		}
	}
}