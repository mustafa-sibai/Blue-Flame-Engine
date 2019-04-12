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
					enum class TextAlignment
					{
						TopLeft, TopCenter, TopRight,
						MiddleLeft, MiddleCenter, MiddleRight,
						BottomLeft, BottomCenter, BottomRight
					};

				private:
					const BF::Graphics::Fonts::Font* font;
					std::vector<Fonts::Character> characters;
					std::string text;
					BF::Math::Rectangle scissorRectangle;
					BF::Math::Vector2i textAlignmentOffset;

					TextAlignment alignment;

				public:
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, BF::Graphics::Renderers::RenderLayer* renderLayer);
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, TextAlignment alignment, BF::Graphics::Renderers::RenderLayer* renderLayer);
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, TextAlignment alignment, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer);
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, TextAlignment alignment, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					Text(const BF::Graphics::Fonts::Font* font, const std::string& text, const BF::Math::Rectangle& scissorRectangle, TextAlignment alignment, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					~Text();

					void SetFont(const BF::Graphics::Fonts::Font* font);
					//void SetText(const std::string& text);
					void SetTextAlignment(TextAlignment textAlignment);

					//void SetPosition(const BF::Math::Vector2f& position) override;
					//void SetRectangle(const BF::Math::Rectangle& rectangle) override;

				//private:
					//BF::Math::Vector2i GetTextAlignmentOffset(TextAlignment textAlignment);
				};
			}
		}
	}
}