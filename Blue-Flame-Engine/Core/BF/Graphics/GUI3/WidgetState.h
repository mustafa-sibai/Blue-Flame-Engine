#pragma once
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class GUISystem;
			class IWidget;

			class BFE_API WidgetState
			{
				friend class BF::Graphics::GUI::GUISystem;
				friend class BF::Graphics::GUI::IWidget;

			private:
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite normal;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite hovered;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite pressed;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite disabled;

			public:
				WidgetState(const BF::Graphics::Renderers::SpriteRendererComponents::Sprite& normal,
					const BF::Graphics::Renderers::SpriteRendererComponents::Sprite& hovered,
					const BF::Graphics::Renderers::SpriteRendererComponents::Sprite& pressed,
					const BF::Graphics::Renderers::SpriteRendererComponents::Sprite& disabled);

				WidgetState(const WidgetState& widgetState);
				~WidgetState();
			};
		}
	}
}