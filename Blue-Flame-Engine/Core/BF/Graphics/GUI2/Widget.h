#pragma once
#include <string>
#include "BF/Graphics/Renderers/SpriteRenderer/Sprite.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class StyleSheet;

			struct State
			{
				BF::Graphics::Renderers::Sprite normal;
				BF::Graphics::Renderers::Sprite hovered;
				BF::Graphics::Renderers::Sprite pressed;
				BF::Graphics::Renderers::Sprite disabled;
			};

			class BF_API Widget : public BF::Application::Component
			{
				public:
					std::vector<State> states;
					int minWidth = 0, minHeight = 0;

				public:
					Widget();
					~Widget();
			};
		}
	}
}