#include "ScrollbarSlider.h"
#include "BF/Graphics/GUI/Scrollbar.h"
#include "BF/Graphics/GUI/Panel.h"
#include "BF/Input/Mouse.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;
			using namespace BF::Input;
			using namespace BF::Math;
			using namespace BF::Graphics::Renderers;

			Math::Vector2f localPosition;
			Math::Vector2i speed;

			ScrollbarSlider::ScrollbarSlider(Scrollbar& scrollbar, Orientation orientation) :
				scrollbar(scrollbar), orientation(orientation), length(0)
			{
			}

			ScrollbarSlider::~ScrollbarSlider()
			{
			}

			void ScrollbarSlider::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
			}

			void ScrollbarSlider::Load(const StyleSheet& StyleSheet, const string& widgetName)
			{
				Widget::Load(StyleSheet, "ScrollbarSlider");
			}

			void ScrollbarSlider::Update()
			{
				Widget::Update();

				length = 25;

				if (!doonce)
				{
					SetPositionAndSize();
					doonce = true;
				}

				Move();
			}

			void ScrollbarSlider::Render()
			{
				Widget::Render();
			}

			void ScrollbarSlider::SetPositionAndSize()
			{
				switch (orientation)
				{
					case Orientation::Horizontal:
					{
						SetRectangle(Math::Rectangle(scrollbar.GetRectangle().x, scrollbar.GetRectangle().y + (scrollbar.GetRectangle().height / 2) - (GetRectangle().height / 2), length, GetRectangle().height));
						break;
					}
					case Orientation::Vertical:
					{
						SetRectangle(Math::Rectangle(scrollbar.GetRectangle().x + (scrollbar.GetRectangle().width / 2) - (GetRectangle().width / 2), scrollbar.GetRectangle().y, GetRectangle().width, length));
						break;
					}
					default:
						break;
				}
			}

			void ScrollbarSlider::Move()
			{
				if (IsHovered() && !IsPressed())
					delta = Vector2f(Mouse::GetPosition().x - GetPosition().x, Mouse::GetPosition().y - GetPosition().y);

				if (IsPressed())
				{
					switch (orientation)
					{
						case Orientation::Horizontal:
						{
							float value = Mouse::GetPosition().x - delta.x;
							float min = scrollbar.GetPosition().x;
							float max = scrollbar.GetPosition().x + (float)(scrollbar.GetRectangle().width - length);

							SetPosition(Math::Vector2f(Clamp(value, min, max), GetPosition().y));
							delta.x = Mouse::GetPosition().x - GetPosition().x;

							speed.x = (scrollbar.panel.GetContentRectangle().width - scrollbar.panel.GetRectangle().width + length) / scrollbar.panel.GetRectangle().width;
							localPosition.x = GetPosition().x - scrollbar.panel.GetPosition().x;
							break;
						}
						case Orientation::Vertical:
						{
							float value = Mouse::GetPosition().y - delta.y;
							float min = scrollbar.GetPosition().y;
							float max = scrollbar.GetPosition().y + (float)(scrollbar.GetRectangle().height - length);

							SetPosition(Math::Vector2f(GetPosition().x, Clamp(value, min, max)));
							delta.y = Mouse::GetPosition().y - GetPosition().y;

							speed.y = (scrollbar.panel.GetContentRectangle().height - scrollbar.panel.GetRectangle().height + length) / scrollbar.panel.GetRectangle().height;
							localPosition.y = GetPosition().y - scrollbar.panel.GetPosition().y;
							break;
						}
						default:
							break;
					}

					scrollbar.panel.SetContentLocalPosition(Math::Vector2f(-(localPosition.x * (float)speed.x), -(localPosition.y * (float)speed.y)));
				}
			}
		}
	}
}