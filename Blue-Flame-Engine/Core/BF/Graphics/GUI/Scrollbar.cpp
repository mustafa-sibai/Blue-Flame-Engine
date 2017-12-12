#include "Scrollbar.h"
#include "BF/Graphics/GUI/Panel.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Scrollbar::Scrollbar(Panel& panel, ScrollbarSlider::Orientation orientation) :
				panel(panel), orientation(orientation), slider(*this, orientation)
			{
			}

			Scrollbar::~Scrollbar()
			{
			}

			void Scrollbar::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
				slider.Initialize(spriteRenderer, zLayer);
			}

			void Scrollbar::Load(const StyleSheet& styleSheet, const std::string& widgetName)
			{
				Widget::Load(styleSheet, "Scrollbar");
				slider.Load(styleSheet, "");
			}

			void Scrollbar::Update()
			{
				Widget::Update();
				SetPositionAndSize();
				slider.Update();
			}

			void Scrollbar::Render()
			{
				Widget::Render();
				slider.Render();
			}

			void Scrollbar::SetPositionAndSize()
			{
				switch (orientation)
				{
					case ScrollbarSlider::Orientation::Horizontal:
					{
						SetRectangle(Math::Rectangle(panel.GetRectangle().x, panel.GetRectangle().y + panel.GetRectangle().height, panel.GetRectangle().width, GetRectangle().height));
						break;
					}
					case ScrollbarSlider::Orientation::Vertical:
					{
						SetRectangle(Math::Rectangle(panel.GetRectangle().x + panel.GetRectangle().width, panel.GetRectangle().y, GetRectangle().width, panel.GetRectangle().height));
						break;
					}
					default:
						break;
				}
			}
		}
	}
}