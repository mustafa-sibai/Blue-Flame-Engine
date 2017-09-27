#include "Text.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Fonts;
			using namespace BF::Math;

			Text::Text() :
				font(nullptr)
			{
			}

			Text::Text(const Font* font, const string& text, const Vector2& position, unsigned int zLayer, const Color& color) :
				Renderable(position, Math::Rectangle((int)position.x, (int)position.y, 0, 0), zLayer, color, Type::Text), font(font), text(text)
			{
				SetText(text);
			}

			Text::Text(const Font* font, const string& text, const Rectangle& rectangle, unsigned int zLayer, const Color& color) :
				Renderable(Vector2((float)rectangle.x, (float)rectangle.y), rectangle, zLayer, color, Type::Text), font(font), text(text)
			{
				SetText(text);
			}

			Text::~Text()
			{
			}

			void Text::SetFont(const Fonts::Font* font)
			{
				this->font = font;
			}

			void Text::SetText(const string& text)
			{
				Vector2 position = Text::position;

				for (size_t i = 0; i < text.length(); i++)
				{
					unsigned int unicode = text[i] - 32;
					position.y = Text::position.y + font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y;

					characters.push_back(Character(position, font->fontAtlas->characters[0][unicode].scissorRectangle, Vector2(), Vector2()));
					position.x += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;

					if (i < text.length() - 1)
						rectangle.width += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;
					else
						rectangle.width += font->fontAtlas->characters[0][unicode].scissorRectangle.width;

					if (font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y) > rectangle.height)
						rectangle.height = font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y);
				}
			}
		}
	}
}