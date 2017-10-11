#include "Panel.h"
#include "BF/Graphics/GUI/WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Panel::Panel(Application::Scene& scene) :
				horizontalScrollbar(*this, ScrollbarSlider::Orientation::Horizontal), verticalScrollbar(*this, ScrollbarSlider::Orientation::Vertical)
			{
				scene.GetWidgetManager().AddWidget(this);
			}

			Panel::~Panel()
			{
			}

			void Panel::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
				horizontalScrollbar.Initialize(spriteRenderer, zLayer);
				verticalScrollbar.Initialize(spriteRenderer, zLayer);
			}

			void Panel::Load(const StyleSheet& StyleSheet, const std::string& widgetName)
			{
				Widget::Load(StyleSheet, "Panel");
				horizontalScrollbar.Load(StyleSheet, "");
				verticalScrollbar.Load(StyleSheet, "");
			}

			void Panel::SetPosition(const Math::Vector2& position)
			{
				Widget::SetPosition(position);
				SetContentPosition(position);
				scissorRectangle = GetRectangle();
				scissorRectangle.x = (int)position.x;
				scissorRectangle.y = (int)position.y;
			}

			void Panel::SetContentPosition(const Math::Vector2& contentPosition)
			{
				this->contentPosition = contentPosition;
				contentRectangle.x = (int)contentPosition.x + contentLocalRectangle.x;
				contentRectangle.y = (int)contentPosition.y + contentLocalRectangle.y;
			}

			void Panel::SetContentLocalPosition(const Math::Vector2& contentLocalPosition)
			{
				this->contentLocalPosition = contentLocalPosition;
				this->contentPosition = GetPosition() + contentLocalPosition;
				contentLocalRectangle.x = (int)contentLocalPosition.x;
				contentLocalRectangle.y = (int)contentLocalPosition.y;

				contentRectangle.x = (int)contentPosition.x;
				contentRectangle.y = (int)contentPosition.y;
			}

			void Panel::SetRectangle(const Math::Rectangle& rectangle)
			{
				Widget::SetRectangle(rectangle);
				SetPosition(Math::Vector2((float)rectangle.x, (float)rectangle.y));
			}

			void Panel::SetContentRectangle(const Math::Rectangle& contentRectangle)
			{
				this->contentRectangle = contentRectangle;
				SetContentPosition(Math::Vector2((float)contentRectangle.x, (float)contentRectangle.y));
			}

			void Panel::SetContentLocalRectangle(const Math::Rectangle& contentLocalRectangle)
			{
				this->contentLocalRectangle = contentLocalRectangle;
				SetContentLocalPosition(Math::Vector2((float)contentLocalPosition.x, (float)contentLocalPosition.y));
			}

			void Panel::SetScissorRectangle(Math::Rectangle scissorRectangle)
			{
				this->scissorRectangle = scissorRectangle;
			}

			void Panel::Update()
			{
				Widget::Update();
				horizontalScrollbar.Update();
				verticalScrollbar.Update();
			}

			void Panel::Render()
			{
				spriteRenderer->SetScissor(Math::Rectangle(0, 0, Engine::GetWindow().GetClientWidth(), Engine::GetWindow().GetClientHeight()));
				Widget::Render();
				horizontalScrollbar.Render();
				verticalScrollbar.Render();
				spriteRenderer->SetScissor(scissorRectangle);
			}
		}
	}
}