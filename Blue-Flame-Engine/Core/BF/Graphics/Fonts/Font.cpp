#include "Font.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			using namespace std;
			using namespace BF::Math;

			Font::Font(const std::string& fontName, unsigned int fontPixelSize, float fontMaxYBearing, API::Texture2D* texture, std::vector<Character>* characters) :
				fontName(fontName), fontPixelSize(fontPixelSize), fontMaxYBearing(fontMaxYBearing), texture(texture), characters(characters), Resource(BF::IO::Resource::Type::Font)
			{
			}

			Font::~Font()
			{
			}
		}
	}
}