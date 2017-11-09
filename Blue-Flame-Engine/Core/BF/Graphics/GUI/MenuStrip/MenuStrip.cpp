#include "MenuStrip.h"
#include "BF/Graphics/GUI/WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace MenuStrip
			{
				MenuStrip::MenuStrip(Application::Scene& scene)
				{
					scene.GetWidgetManager().AddWidget(this);
				}

				MenuStrip::~MenuStrip()
				{
				}

				void MenuStrip::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
				}

				void MenuStrip::Load(const StyleSheet& StyleSheet, const std::string& widgetName)
				{
					Widget::Load(StyleSheet, "MenuStrip");
				}

				void MenuStrip::Update()
				{
					Widget::Update();
				}

				void MenuStrip::Render()
				{
					Widget::Render();
				}
			}
		}
	}
}