#pragma once
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
#include "BF/Graphics/Fonts/Font.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API Text : public Renderable
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
					const Fonts::Font* font;
					std::vector<Fonts::Character> characters;
					std::string text;
					Math::Rectangle scissorRectangle;
					Math::Vector2i textAlignmentOffset;

					TextAlignment alignment;

				public:
					Text();
					Text(const Fonts::Font* font, const std::string& text, const Math::Rectangle& scissorRectangle, TextAlignment alignment, unsigned int zLayer, const Color& color);
					~Text();

					void SetFont(const Fonts::Font* font);
					void SetText(const std::string& text);
					void SetTextAlignment(TextAlignment textAlignment);

					void SetPosition(const Math::Vector2f& position) override;
					void SetRectangle(const Math::Rectangle& rectangle) override;

				private:
					Math::Vector2i GetTextAlignmentOffset(TextAlignment textAlignment);
			};
		}
	}
}