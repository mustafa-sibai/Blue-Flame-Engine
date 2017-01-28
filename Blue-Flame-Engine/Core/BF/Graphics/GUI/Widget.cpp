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

			Widget::Widget() :
				currentSprite(nullptr)
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
				currentSprite = &widgetData.normalSprite;
			}

			void Widget::AddOnClickListener(void(*OnClickCallBack)())
			{
				this->OnClickCallBack = OnClickCallBack;
			}

			bool Widget::IsMouseOnWidget()
			{
				if (Mouse::IsInsideWindowClient())
					if (Mouse::GetPosition().x >= rectangle.x && Mouse::GetPosition().x <= rectangle.x + rectangle.width &&
						Mouse::GetPosition().y >= rectangle.y && Mouse::GetPosition().y <= rectangle.y + rectangle.height)
						return true;

				return false;
			}

			void Widget::Update()
			{
				hovered = IsMouseOnWidget();

				if (hovered)
					currentSprite = &widgetData.hoveredSprite;
				else
					currentSprite = &widgetData.normalSprite;

				if (!hovered && Mouse::IsButtonPressed(Mouse::Button::Left))
					mouseNotPressedOnWidget = true;

				if (!mouseNotPressedOnWidget && hovered && Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					currentSprite = &widgetData.pressedSprite;
					pressed = true;
				}

				if (hovered && pressed && !Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					pressed = false;
					currentSprite = &widgetData.normalSprite;
					OnClickCallBack();
				}

				if (!Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					mouseNotPressedOnWidget = false;
					pressed = false;
				}
			}

			void Widget::Render()
			{
				spriteRenderer->Render(*currentSprite);
			}
		}
	}
}