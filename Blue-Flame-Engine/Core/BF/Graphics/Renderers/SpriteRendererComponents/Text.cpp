#include "Text.h"
#include "BF/Graphics/Renderers/RenderLayer.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				using namespace std;
				using namespace BF::Math;
				using namespace BF::Graphics::API;
				using namespace BF::Graphics::Fonts;
				using namespace BF::Graphics::Renderers;

				Text::Text(const Font* font, const string& text, RenderLayer& renderLayer) :
					Renderable(Type::Text, Vector2i(scissorRectangle.width, scissorRectangle.height), Vector2f(), 0, renderLayer, Color::Whites::White()),
					alignment(alignment), scissorRectangle(scissorRectangle), font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, TextAlignment alignment, RenderLayer& renderLayer) :
					Renderable(Type::Text, Vector2i(scissorRectangle.width, scissorRectangle.height), Vector2f(), 0, renderLayer, Color::Whites::White()),
					alignment(alignment), scissorRectangle(scissorRectangle), font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, TextAlignment alignment, int zSortingOrder, RenderLayer& renderLayer) :
					Renderable(Type::Text, Vector2i(scissorRectangle.width, scissorRectangle.height), Vector2f(), zSortingOrder, renderLayer, Color::Whites::White()),
					alignment(alignment), scissorRectangle(scissorRectangle), font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, TextAlignment alignment, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					Renderable(Type::Text, Vector2i(scissorRectangle.width, scissorRectangle.height), Vector2f(), zSortingOrder, renderLayer, color),
					alignment(alignment), scissorRectangle(scissorRectangle), font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, const Rectangle& scissorRectangle, TextAlignment alignment, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					Renderable(Type::Text, Vector2i(scissorRectangle.width, scissorRectangle.height), Vector2f(), zSortingOrder, renderLayer, color),
					alignment(alignment), scissorRectangle(scissorRectangle), font(font), text(text)
				{
					//SetText(text);
				}

				Text::~Text()
				{
				}

				void Text::SetTextAlignment(TextAlignment textAlignment)
				{
					alignment = textAlignment;
					//SetPosition(position);
				}

				/*void Text::SetPosition(const Vector2f& position)
				{
					Renderable::SetPosition(position);
					scissorRectangle.x = (int)position.x;
					scissorRectangle.y = (int)position.y;
					textAlignmentOffset = GetTextAlignmentOffset(alignment);
					Vector2f pos = position + Vector2f((float)textAlignmentOffset.x, (float)textAlignmentOffset.y);

					rectangle.width = 0;
					rectangle.height = 0;

					for (size_t i = 0; i < text.length(); i++)
					{
						int unicode = text[i] - 32;
						pos.y = position.y + textAlignmentOffset.y + font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y;

						characters[i] = Character(pos, font->fontAtlas->characters[0][unicode].scissorRectangle, Vector2i(), Vector2i());
						pos.x += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;

						if (i < text.length() - 1)
							rectangle.width += (int)font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;
						else
							rectangle.width += font->fontAtlas->characters[0][unicode].scissorRectangle.width;

						if (font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y) > rectangle.height)
							rectangle.height = font->fontAtlas->characters[0][unicode].scissorRectangle.height + (int)(font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y);
					}
				}*/

				/*void Text::SetRectangle(const Rectangle& rectangle)
				{
					SetPosition(Vector2f((float)rectangle.x, (float)rectangle.y));
				}*/

				/*Math::Vector2i Text::GetTextAlignmentOffset(TextAlignment textAlignment)
				{
					switch (textAlignment)
					{
						case TextAlignment::TopLeft:
						{
							return Vector2i(0, 0);
							break;
						}
						case TextAlignment::TopCenter:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							Vector2i scissorRectangleSize = Vector2i(scissorRectangle.width, scissorRectangle.height);
							return Vector2i(scissorRectangleSize.Center().x - textSize.Center().x, scissorRectangle.y);
							break;
						}
						case TextAlignment::TopRight:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							return Vector2i(scissorRectangle.width - textSize.x, scissorRectangle.y);
							break;
						}
						case TextAlignment::MiddleLeft:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							Vector2i scissorRectangleSize = Vector2i(scissorRectangle.width, scissorRectangle.height);
							return Vector2i(0, scissorRectangleSize.Center().y - textSize.Center().y);
							break;
						}
						case TextAlignment::MiddleCenter:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							Vector2i scissorRectangleSize = Vector2i(scissorRectangle.width, scissorRectangle.height);
							return Vector2i(scissorRectangleSize.Center().x - textSize.Center().x, scissorRectangleSize.Center().y - textSize.Center().y);
							break;
						}
						case TextAlignment::MiddleRight:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							return Vector2i(scissorRectangle.width - textSize.x, scissorRectangle.Center().y - textSize.Center().y);
							break;
						}
						case TextAlignment::BottomLeft:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							return Vector2i(0, scissorRectangle.y + scissorRectangle.height - textSize.y);
							break;
						}
						case TextAlignment::BottomCenter:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							Vector2i scissorRectangleSize = Vector2i(scissorRectangle.width, scissorRectangle.height);
							return Vector2i(scissorRectangleSize.Center().x - textSize.Center().x, scissorRectangle.y + scissorRectangle.height - textSize.y);
							break;
						}
						case TextAlignment::BottomRight:
						{
							Vector2i textSize = Vector2i(rectangle.width, rectangle.height);
							return Vector2i(scissorRectangle.width - textSize.x, scissorRectangle.y + scissorRectangle.height - textSize.y);
							break;
						}
						default:
						{
							return Vector2i(0, 0);
							break;
						}
					}
				}*/

				void Text::SetFont(const Font* font)
				{
					this->font = font;
					//SetText(text);
				}

				/*void Text::SetText(const string& text)
				{
					BFE_IS_NULL(font);

					Text::text = text;
					Vector2f pos = position;
					rectangle.width = 0;
					rectangle.height = 0;

					characters.clear();
					characters.reserve(text.length());

					for (size_t i = 0; i < text.length(); i++)
					{
						int unicode = text[i] - 32;
						pos.y = position.y + font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y;

						characters.emplace_back(Character(pos, font->fontAtlas->characters[0][unicode].scissorRectangle, Vector2i(), Vector2i()));
						pos.x += font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;

						if (i < text.length() - 1)
							rectangle.width += (int)font->fontAtlas->characters[0][unicode].bearing.x + font->fontAtlas->characters[0][unicode].scissorRectangle.width;
						else
							rectangle.width += font->fontAtlas->characters[0][unicode].scissorRectangle.width;

						if (font->fontAtlas->characters[0][unicode].scissorRectangle.height + (font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y) > rectangle.height)
							rectangle.height = font->fontAtlas->characters[0][unicode].scissorRectangle.height + (int)(font->fontAtlas->fontMaxYBearing - font->fontAtlas->characters[0][unicode].bearing.y);
					}

					SetTextAlignment(alignment);
				}*/
			}
		}
	}
}