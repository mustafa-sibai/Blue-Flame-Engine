#pragma once
#include "BF/Graphics/Renderers/SpriteRendererComponents/Renderable.h"
#include "BF/Graphics/Fonts/Font.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				class BFE_API Text : public Renderable<Text>
				{
					friend class SpriteRenderer;

				public:
					const BF::Graphics::Fonts::Font* font;
					std::string text;

				private:
					std::vector<BF::Math::Vector2i> characterPositions;
					//BF::Math::Rectangle scissorRectangle;
					BF::Math::Vector2i textAlignmentOffset;

				public:
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, BF::Graphics::Renderers::RenderLayer* renderLayer);
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer);
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					~Text();
				};
			}
		}
	}
}