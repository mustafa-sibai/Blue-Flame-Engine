#include "Panel.h"
#include "WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Panel::Panel(Application::Scene& scene)
			{
				scene.GetWidgetManager().AddWidget(this);
			}

			Panel::~Panel()
			{
			}

			void Panel::Initialize(Renderers::SpriteRenderer& spriteRenderer)
			{
				Widget::Initialize(spriteRenderer);
			}

			void Panel::Load(const StyleSheet& StyleSheet, const std::string& widgetName)
			{
				Widget::Load(StyleSheet, "Panel");
			}

			void Panel::Update()
			{
				Widget::Update();
			}

			void Panel::Render()
			{
				Widget::Render();
				spriteRenderer->SetScissor(Math::Rectangle(GetRectangle().x, GetRectangle().y, 50, 50));
			}
		}
	}
}