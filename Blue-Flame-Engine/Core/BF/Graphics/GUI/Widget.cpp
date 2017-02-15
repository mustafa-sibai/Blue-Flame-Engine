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
				widgetData = StyleSheet.GetWidget(widgetName);
				currentSprite = &widgetData.normalSprite;
			}

			void Widget::AddOnClickListener(void(*OnClickCallBack)())
			{
				this->OnClickCallBack = OnClickCallBack;
			}

			void Widget::SetPosition(const Math::Vector2& position)
			{
				widgetData.normalSprite.SetPosition(position);
				widgetData.hoveredSprite.SetPosition(position);
				widgetData.pressedSprite.SetPosition(position);
			}

			void Widget::SetRectangle(const Math::Rectangle& rectangle)
			{
				widgetData.normalSprite.SetRectangle(rectangle);
				widgetData.hoveredSprite.SetRectangle(rectangle);
				widgetData.pressedSprite.SetRectangle(rectangle);
			}

			bool Widget::IsMouseOnWidget()
			{
				if (Mouse::IsInsideWindowClient())
					if (Mouse::GetPosition().x >= currentSprite->GetRectangle().x && Mouse::GetPosition().x <= currentSprite->GetRectangle().x + currentSprite->GetRectangle().width &&
						Mouse::GetPosition().y >= currentSprite->GetRectangle().y && Mouse::GetPosition().y <= currentSprite->GetRectangle().y + currentSprite->GetRectangle().height)
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