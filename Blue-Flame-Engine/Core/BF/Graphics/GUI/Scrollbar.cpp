#include "Scrollbar.h"
#include "Panel.h"
#include "BF/System/Log.h"

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

			void Scrollbar::Initialize(Renderers::SpriteRenderer& spriteRenderer)
			{
				Widget::Initialize(spriteRenderer);
				slider.Initialize(spriteRenderer);
			}

			void Scrollbar::Load(const StyleSheet& StyleSheet, const std::string& widgetName)
			{
				Widget::Load(StyleSheet, "Scrollbar");
				slider.Load(StyleSheet, "");
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