#include "MenuItem.h"
#include "BF/Graphics/GUI/MenuStrip/MenuStrip.h"
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
				using namespace BF::Math;
				using namespace BF::Input;
				using namespace BF::Graphics::Renderers;

				MenuItem::MenuItem(MenuStrip* menuStrip, MenuItem* parent) :
					menuStrip(menuStrip), parent(parent), activeSubMenu(false), parentCount(0)
				{
				}

				MenuItem::~MenuItem()
				{
				}

				MenuItem* MenuItem::Instantiate(const std::string& name)
				{
					MenuItem* item = new MenuItem(menuStrip, this);
					menuItems.emplace_back(item);

					item->Initialize(*spriteRenderer, GetZLayer());

					if (item->parent == nullptr)
						item->Load(*styleSheet, "MenuStrip/MenuItem1");
					else
					{
						item->Load(*styleSheet, "MenuStrip/MenuItem2");
						item->parentCount = parentCount + 1;
					}

					item->GetText().SetText(name);

					Vector2f position;

					if (item->parentCount < 2)
					{
						if (menuItems.size() == 1)
							position = Vector2f(GetPosition().x, GetPosition().y + (float)GetRectangle().height);
						else
							position = Vector2f(GetPosition().x, menuItems[menuItems.size() - 2]->GetPosition().y + (float)GetRectangle().height);
					}
					else
					{
						if (menuItems.size() == 1)
							position = Vector2f(GetPosition().x + (float)GetRectangle().width, GetPosition().y);
						else
							position = Vector2f(GetPosition().x + (float)GetRectangle().width, menuItems[menuItems.size() - 2]->GetPosition().y + (float)GetRectangle().height);
					}

					item->SetPosition(position);
					item->GetText().SetPosition(position);

					return item;
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

					if (parent == nullptr)
					{
						if (!hovered && !menuStrip->active || !activeSubMenu)
							currentSprite = &widgetData.sprites[currentState + 0];

						if (hovered && !menuStrip->active)
							currentSprite = &widgetData.sprites[currentState + 1];

						if (hovered && menuStrip->active)
						{
							currentSprite = &widgetData.sprites[currentState + 2];
							menuStrip->activeMenuItemOnMenuStrip = this;
							DeactivateMenuItemToThis(menuStrip->previousActiveSubMenuItem);
							menuStrip->previousActiveSubMenuItem = menuStrip->activeSubMenuItem;
							menuStrip->activeSubMenuItem = this;
							activeSubMenu = true;
						}

						if (hovered && menuStrip->active && Mouse::IsButtonPressed(Mouse::Button::Code::Left))
						{
							menuStrip->active = false;
							activeSubMenu = false;
							hovered = false;
						}

						if (hovered && Mouse::IsButtonPressed(Mouse::Button::Code::Left))
						{
							currentSprite = &widgetData.sprites[currentState + 2];
							menuStrip->activeMenuItemOnMenuStrip = this;
							menuStrip->activeSubMenuItem = this;
							menuStrip->previousActiveSubMenuItem = this;
							menuStrip->active = true;
							activeSubMenu = true;
						}
					}
					else
					{
						if (!hovered && menuStrip->active)
						{
							if (menuItems.size() <= 0)
								currentSprite = &widgetData.sprites[currentState + 0];
						}

						if (hovered && menuStrip->active)
						{
							currentSprite = &widgetData.sprites[currentState + 1];
							menuStrip->previousActiveSubMenuItem = menuStrip->activeSubMenuItem;
							menuStrip->activeSubMenuItem = this;
							menuStrip->activeSubMenuItem->activeSubMenu = true;

							if (menuStrip->previousActiveSubMenuItem->parent != nullptr && menuStrip->previousActiveSubMenuItem != this && menuStrip->activeSubMenuItem->parent != menuStrip->previousActiveSubMenuItem)
								DeactivateMenuItemToThis(menuStrip->previousActiveSubMenuItem);
						}

						if (hovered && menuStrip->active && Mouse::IsButtonUp(Mouse::Button::Code::Left))
						{
							pressed = true;
							DeactivateMenuItemToRoot(this);
							menuStrip->active = false;
						}
					}

					if (activeSubMenu)
					{
						for (size_t i = 0; i < menuItems.size(); i++)
							menuItems[i]->Update();
					}
				}

				void MenuItem::Render()
				{
					Widget::Render();

					if (activeSubMenu)
					{
						for (size_t i = 0; i < menuItems.size(); i++)
							menuItems[i]->Render();
					}
				}

				void MenuItem::DeactivateMenuItemToRoot(MenuItem* menuItem)
				{
					if (menuItem != nullptr)
						menuItem->activeSubMenu = false;

					if (menuItem->parent != nullptr)
						DeactivateMenuItemToRoot(menuItem->parent);
				}

				void MenuItem::DeactivateMenuItemToThis(MenuItem* menuItem)
				{
					if (menuItem != nullptr && menuItem != this)
					{
						menuItem->activeSubMenu = false;
						menuItem->currentSprite = &menuItem->widgetData.sprites[menuItem->currentState + 0];
					}

					if (menuItem->parent != this->parent)
						DeactivateMenuItemToThis(menuItem->parent);
				}
			}
		}
	}
}