#include "Widget.h"
#include "BF/Graphics/GUI/StyleSheet.h"
#include "BF/Input/Mouse.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Input;

			Widget::Widget()
			{
			}

			Widget::~Widget()
			{
			}

			void Widget::Initialize(Renderers::SpriteRenderer& spriteRenderer)
			{
				this->spriteRenderer = &spriteRenderer;
			}

			void Widget::Load(const StyleSheet& StyleSheet, const string& widgetName)
			{
				widgetData = StyleSheet.GetWidgetData(widgetName);
				rectangle = widgetData.pressedSprite.GetRectangle();
			}

			void Widget::Update()
			{
				hovered = IsMouseOnWidget();

				if (!hovered && Mouse::IsButtonPressed(Mouse::Button::Left))
					mouseNotPressedOnWidget = true;

				if (!mouseNotPressedOnWidget && hovered && Mouse::IsButtonPressed(Mouse::Button::Left))
					pressed = true;

				if (hovered && pressed && !Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					pressed = false;
					released = true;
				}

				if (!Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					mouseNotPressedOnWidget = false;
					pressed = false;
				}
			}

			void Widget::Render()
			{
				spriteRenderer->Render(widgetData.releasedSprite);
			}

			bool Widget::IsMouseOnWidget()
			{
				if (Mouse::IsInsideWindowClient())
					if (Mouse::GetPositionRelativeToWindow().x >= rectangle.x && Mouse::GetPositionRelativeToWindow().x <= rectangle.x + rectangle.width &&
						Mouse::GetPositionRelativeToWindow().y >= rectangle.y && Mouse::GetPositionRelativeToWindow().y <= rectangle.y + rectangle.height)
						return true;

				return false;
			}
		}
	}
}