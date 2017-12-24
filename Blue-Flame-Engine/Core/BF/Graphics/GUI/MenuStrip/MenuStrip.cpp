#include "MenuStrip.h"
#include "BF/Input/Mouse.h"
#include "BF/System/Debug.h"

#define OFFSET 10.0f

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace MenuStrip
			{
				using namespace std;
				using namespace BF::Math;
				using namespace BF::Input;
				using namespace BF::Graphics::Renderers;

				MenuStrip::MenuStrip() :
					active(false), activeMenuItemOnMenuStrip(nullptr), activeSubMenuItem(nullptr)
				{
				}

				MenuStrip::~MenuStrip()
				{
				}

				MenuItem* MenuStrip::Instantiate(const string& name)
				{
					MenuItem* item = new MenuItem(this, nullptr);
					menuItems.emplace_back(item);

					item->Initialize(*spriteRenderer, GetZLayer());
					item->Load(*styleSheet, "MenuStrip/MenuItem1");
					item->GetText().SetText(name);

					if (menuItems.size() > 1)
					{
						Vector2f position = Vector2f(menuItems[menuItems.size() - 2]->GetPosition().x + (float)menuItems[menuItems.size() - 2]->GetRectangle().width + OFFSET, menuItems[menuItems.size() - 1]->GetPosition().y);
						item->SetPosition(position);
						item->GetText().SetPosition(position);
					}

					return item;
				}

				void MenuStrip::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
				}

				void MenuStrip::Load(const StyleSheet& styleSheet, const string& widgetName)
				{
					this->styleSheet = &styleSheet;
					Widget::Load(styleSheet, "MenuStrip");
				}

				void MenuStrip::Update()
				{
					Widget::Update();

					for (size_t i = 0; i < menuItems.size(); i++)
					{
						menuItems[i]->Update();

						if (menuItems[i] != activeMenuItemOnMenuStrip)
							menuItems[i]->activeSubMenu = false;
					}

					if (active && !activeSubMenuItem->hovered && Mouse::IsButtonPressed(Mouse::Button::Code::Left))
					{
						activeSubMenuItem->DeactivateMenuItemToRoot(activeSubMenuItem);
						active = false;
					}
				}

				void MenuStrip::Render()
				{
					Widget::Render();

					for (size_t i = 0; i < menuItems.size(); i++)
						menuItems[i]->Render();
				}
			}
		}
	}
}