#include "Font.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			using namespace std;
			using namespace BF::Math;

			Font::Font()
			{
			}

			Font::~Font()
			{
			}

			void Font::Load(const string& filename, unsigned int charPixelSize, FontAtlasFactory::Language language)
			{
				fontAtlas = FontAtlasFactory::GetFontAtlas(filename, charPixelSize, language);
			}
		}
	}
}