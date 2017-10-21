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

			Text::Text(const Fonts::Font* font, const std::string& text, const Math::Rectangle& scissorRectangle, TextAlignment alignment, unsigned int zLayer, const Color& color) :
				Renderable(Vector2(scissorRectangle.x, scissorRectangle.y), Rectangle((int)scissorRectangle.x, (int)scissorRectangle.y, 0, 0), zLayer, color, Type::Text), alignment(alignment), scissorRectangle(scissorRectangle), font(font), text(text)
			{
				SetText(text);
			}

			Text::~Text()
			{
			}

			void Text::SetTextAlignment(TextAlignment textAlignment)
			{
				alignment = textAlignment;
				SetPosition(position);
			}

			void Text::SetPosition(const Vector2& position)
			{
				Renderable::SetPosition(position);
				scissorRectangle.x = position.x;
				scissorRectangle.y = position.y;
				textAlignmentOffset = GetTextAlignmentOffset(alignment);
				Vector2 pos = position + textAlignmentOffset;

				rectangle.width = 0;
				rectangle.height = 0;

				for (size_t i = 0; i < text.length(); i++)
				{
					unsigned int unicode = text[i] - 32;
					pos.y = position.y + textAlignmentOffset.y + font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y;

					characters[i] = Character(pos, font->fontAtlas->characters[0][unicode].scissorRectangle, Vector2(), Vector2());
					pos.x += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;

					if (i < text.length() - 1)
						rectangle.width += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;
					else
						rectangle.width += font->fontAtlas->characters[0][unicode].scissorRectangle.width;

					if (font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y) > rectangle.height)
						rectangle.height = font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y);
				}
			}

			void Text::SetRectangle(const Rectangle& rectangle)
			{
				SetPosition(Vector2(rectangle.x, rectangle.y));
			}

			Math::Vector2 Text::GetTextAlignmentOffset(TextAlignment textAlignment)
			{
				switch (textAlignment)
				{
					case TextAlignment::TopLeft:
					{
						return Vector2(0, 0);
						break;
					}
					case TextAlignment::TopCenter:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						Vector2 scissorRectangleSize = Vector2(scissorRectangle.width, scissorRectangle.height);
						return Vector2((int)(scissorRectangleSize.Center().x - textSize.Center().x), (int)scissorRectangle.y);
						break;
					}
					case TextAlignment::TopRight:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						return Vector2((int)(scissorRectangle.width - textSize.x), (int)scissorRectangle.y);
						break;
					}
					case TextAlignment::MiddleLeft:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						Vector2 scissorRectangleSize = Vector2(scissorRectangle.width, scissorRectangle.height);
						return Vector2(0, (int)(scissorRectangleSize.Center().y - textSize.Center().y));
						break;
					}
					case TextAlignment::MiddleCenter:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						Vector2 scissorRectangleSize = Vector2(scissorRectangle.width, scissorRectangle.height);
						return Vector2((int)(scissorRectangleSize.Center().x - textSize.Center().x), (int)(scissorRectangleSize.Center().y - textSize.Center().y));
						break;
					}
					case TextAlignment::MiddleRight:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						return Vector2((int)(scissorRectangle.width - textSize.x), (int)(scissorRectangle.Center().y - textSize.Center().y));
						break;
					}
					case TextAlignment::BottomLeft:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						return Vector2(0, (int)(scissorRectangle.y + scissorRectangle.height - textSize.y));
						break;
					}
					case TextAlignment::BottomCenter:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						Vector2 scissorRectangleSize = Vector2(scissorRectangle.width, scissorRectangle.height);
						return Vector2((int)(scissorRectangleSize.Center().x - textSize.Center().x), (int)(scissorRectangle.y + scissorRectangle.height - textSize.y));
						break;
					}
					case TextAlignment::BottomRight:
					{
						Vector2 textSize = Vector2(rectangle.width, rectangle.height);
						return Vector2((int)(scissorRectangle.width - textSize.x), (int)(scissorRectangle.y + scissorRectangle.height - textSize.y));
						break;
					}
					default:
					{
						return Vector2(0, 0);
						break;
					}
				}
			}

			void Text::SetFont(const Font* font)
			{
				this->font = font;
				SetText(text);
			}

			void Text::SetText(const string& text)
			{
				Text::text = text;
				Vector2 pos = position;
				rectangle.width = 0;
				rectangle.height = 0;

				characters.clear();
				characters.reserve(text.length());

				for (size_t i = 0; i < text.length(); i++)
				{
					unsigned int unicode = text[i] - 32;
					pos.y = position.y + font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y;

					characters.emplace_back(Character(pos, font->fontAtlas->characters[0][unicode].scissorRectangle, Vector2(), Vector2()));
					pos.x += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;

					if (i < text.length() - 1)
						rectangle.width += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;
					else
						rectangle.width += font->fontAtlas->characters[0][unicode].scissorRectangle.width;

					if (font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y) > rectangle.height)
						rectangle.height = font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y);
				}

				SetTextAlignment(alignment);
			}
		}
	}
}