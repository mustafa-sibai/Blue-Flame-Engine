#include "Font.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Math;

			struct Glyph
			{
				unsigned int unicode;
				unsigned int width, height;
				unsigned int bufferSize;
				uint8_t* buffer;

				Vector2 bearing;
				Vector2 advance;

				Glyph() = default;
				Glyph(unsigned int unicode, unsigned int width, unsigned int height, Vector2 bearing, Vector2 advance, uint8_t* data) :
					unicode(unicode), width(width), height(height), bearing(bearing), advance(advance)
				{
					bufferSize = width * height;
					buffer = new uint8_t[bufferSize];
					memcpy(buffer, data, sizeof(uint8_t) * bufferSize);
				}
			};

			Font::Font(const Shader& shader) :
				startUnicode(0), endUnicode(0)
			{
				texture = new Texture2D(shader);
			}

			Font::~Font()
			{
			}

			FontAtlas* Font::Load(const string& filename, Language language)
			{
				vector<Character>* characters = new vector<Character>();

				error = FT_Init_FreeType(&library);
				if (error != FT_Err_Ok)
					cout << "ERROR !!" << endl;

				error = FT_New_Face(library, "Assets/Fonts/arial.ttf", 0, &face);

				if (error == FT_Err_Unknown_File_Format)
					cout << "ERROR: Unknown File Format !!" << endl;
				else if (error)
					cout << "ERROR: file not found !!" << endl;

				cout << "family_name: " << face->family_name << " style_name: " << face->style_name << endl;
				cout << "face_index: " << face->face_index << " num_faces: " << face->num_faces << " num_glyphs: " << face->num_glyphs << endl;

				error = FT_Set_Pixel_Sizes(face, 0, charPixelSize);
				if (error != FT_Err_Ok)
					cout << "ERROR !!" << endl;


				if (language == Language::English)
				{
					startUnicode = 0x00000020;
					endUnicode = 0x0000007E;
				}

				const unsigned int totalGlyphs = endUnicode - startUnicode;

				vector<Glyph> glyph(totalGlyphs);
				unsigned int totalGlyphsWidth = 0;

				for (unsigned int i = 0; i < totalGlyphs; i++)
				{
					unsigned int unicode = startUnicode + i;
					PrepareGlyph(unicode);

					if (face->glyph->bitmap.width == 0)
						face->glyph->bitmap.width = face->glyph->advance.x >> 6;

					glyph[i] = Glyph(unicode, face->glyph->bitmap.width, face->glyph->bitmap.rows,
						Vector2((float)face->glyph->bitmap_left, (float)(face->glyph->bitmap_top)),
						Vector2((float)(face->glyph->advance.x >> 6), (float)(face->glyph->advance.y >> 6)), face->glyph->bitmap.buffer);

					totalGlyphsWidth += (unsigned int)face->glyph->bitmap.width;
				}

				unsigned int altalWidth, atlasHeight;
				CalculateTextureAtelsSize(totalGlyphs, totalGlyphsWidth, charPixelSize, altalWidth, atlasHeight);
				textureAtlas.Create(altalWidth, atlasHeight, Texture::Format::R8);

				for (unsigned int x = 0, y = 0, index = 0; index < totalGlyphs; )
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
						characters->push_back(Character(Vector3(), charPixelSize, scissorRectangle, glyph[index].bearing, glyph[index].advance));
						x += (unsigned int)glyph[index].width;
						index++;
					}
				}

				texture->Create(textureAtlas.GetTextureData(), Texture2D::Format::R8);

				FT_Done_Face(face);
				FT_Done_FreeType(library);

				return new FontAtlas("", charPixelSize, texture, characters);
			}

			void Font::CreateTextureAtlas(int startUnicode, int endUnicode)
			{
			}

			void Font::PrepareGlyph(unsigned int unicode)
			{
				FT_UInt glyph_index = FT_Get_Char_Index(face, unicode);

				error = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
				if (error != FT_Err_Ok)
					cout << "ERROR !!" << endl;

				error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

				if (error != FT_Err_Ok)
					cout << "ERROR !!" << endl;
			}

			void Font::CalculateTextureAtelsSize(unsigned int totalGlyphs, unsigned int totalGlyphsWidth, unsigned int glyphHeight, unsigned int& width, unsigned int& height)
			{
				float square = (float)ceil(sqrt(totalGlyphs));
				float glyphWidth = ceil((float)totalGlyphsWidth / totalGlyphs);
				width = (unsigned int)pow(2, ceil(log(square * glyphWidth) / log(2)));
				float columns = floor(width / (float)glyphWidth);
				float rows = ceil(totalGlyphs / columns);
				height = (unsigned int)pow(2, ceil(log(rows * glyphHeight) / log(2)));

				unsigned int temp = max(height, width);
				height = min(height, width);
				width = temp;
			}
		}
	}
}