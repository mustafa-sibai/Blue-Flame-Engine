#include "Button.h"
#include "BF/Graphics/GUI/WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Button::Button(Application::Scene& scene)
			{
				scene.GetWidgetManager().AddWidget(this);
			}

			Button::~Button()
			{
			}

			void Button::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
			}

			void Button::Load(const StyleSheet& StyleSheet, const std::string& widgetName)
			{
				Widget::Load(StyleSheet, "Button");
			}

			void Button::Update()
			{
				Widget::Update();
			}

			void Button::Render()
			{
				Widget::Render();
			}
		}
	}
}