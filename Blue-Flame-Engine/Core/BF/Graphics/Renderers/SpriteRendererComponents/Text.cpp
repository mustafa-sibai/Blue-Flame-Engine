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

				Text::Text(const Font* font, const string& text, RenderLayer* renderLayer) :
					Renderable(Type::Text, Vector2i(), Vector2f(0.5f), 0, renderLayer, Color::Whites::White()),
					font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, const Vector2f& pivot, RenderLayer* renderLayer) :
					Renderable(Type::Text, Vector2i(), pivot, 0, renderLayer, Color::Whites::White()),
					font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::Text, Vector2i(), pivot, zSortingOrder, renderLayer, Color::Whites::White()),
					font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::Text, Vector2i(), pivot, zSortingOrder, renderLayer, color),
					font(font), text(text)
				{
				}

				Text::~Text()
				{
				}
			}
		}
	}
}