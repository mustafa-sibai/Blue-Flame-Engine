#include "WidgetState.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			WidgetState::WidgetState(const Sprite& normal, const Sprite& hovered, const Sprite& pressed, const Sprite& disabled) :
				normal(normal), hovered(hovered), pressed(pressed), disabled(disabled)
			{
			}

			WidgetState::WidgetState(const WidgetState& widgetState) :
				WidgetState(widgetState.normal, widgetState.hovered, widgetState.pressed, widgetState.disabled)
			{
			}

			WidgetState::~WidgetState()
			{
			}
		}
	}
}