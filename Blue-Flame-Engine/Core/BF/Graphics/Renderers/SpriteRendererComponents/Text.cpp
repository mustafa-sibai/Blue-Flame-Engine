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
					Renderable(Type::Text, 0, renderLayer, Color::Whites::White()),
					font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::Text, zSortingOrder, renderLayer, Color::Whites::White()),
					font(font), text(text)
				{
				}

				Text::Text(const Font* font, const string& text, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::Text, zSortingOrder, renderLayer, color),
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