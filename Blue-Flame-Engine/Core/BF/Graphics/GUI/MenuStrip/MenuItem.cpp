#include "MenuItem.h"
#include "BF/Input/Mouse.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace MenuStrip
			{
				using namespace std;
				using namespace BF::Input;
				using namespace BF::Graphics::Renderers;

				MenuItem::MenuItem()
				{
				}

				MenuItem::~MenuItem()
				{
				}

				const MenuItem& MenuItem::Instantiate(string name)
				{
					menuItems.emplace_back(MenuItem());
					menuItems[menuItems.size() - 1].Initialize(*spriteRenderer, GetZLayer());
					menuItems[menuItems.size() - 1].Load(*styleSheet, "MenuStrip/MenuItem1");
					return menuItems[menuItems.size() - 1];
				}

				void MenuItem::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
				}

				void MenuItem::Load(const StyleSheet& styleSheet, const string& widgetName)
				{
					this->styleSheet = &styleSheet;
					Widget::Load(styleSheet, widgetName);
				}

				void MenuItem::Update()
				{
					hovered = IsMouseOnWidget();
				}

				void MenuItem::Render()
				{
					Widget::Render();
				}
			}
		}
	}
}