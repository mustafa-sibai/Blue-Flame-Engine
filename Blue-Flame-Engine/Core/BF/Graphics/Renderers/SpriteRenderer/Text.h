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

				private:
					const Fonts::Font* font;
					std::vector<Fonts::Character> characters;
					std::string text;

				public:
					Text();
					Text(const Fonts::Font* font, const std::string& text, const Math::Vector2& position, unsigned int zLayer, const Color& color);
					Text(const Fonts::Font* font, const std::string& text, const Math::Rectangle& rectangle, unsigned int zLayer, const Color& color);
					~Text();

					void SetFont(const Fonts::Font* font);
					void SetText(const std::string& text);
			};
		}
	}
}