#include "MenuStrip.h"
#include "BF/Input/Mouse.h"

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
				using namespace BF::Graphics::Renderers;
				using namespace BF::Math;
				using namespace BF::Input;

				MenuStrip::MenuStrip() :
					active(false), resetCurrentSprite(false)
				{
				}

				MenuStrip::~MenuStrip()
				{
				}

				const MenuItem& MenuStrip::Instantiate(string name)
				{
					menuItems.emplace_back(new MenuItem());
					menuItems[menuItems.size() - 1]->Initialize(*spriteRenderer, GetZLayer());
					menuItems[menuItems.size() - 1]->Load(*styleSheet, "MenuStrip/MenuItem1");

					if (menuItems.size() > 1)
						menuItems[menuItems.size() - 1]->SetPosition(Vector2f(menuItems[menuItems.size() - 2]->GetPosition().x + (float)menuItems[menuItems.size() - 2]->GetRectangle().width + OFFSET, menuItems[menuItems.size() - 1]->GetPosition().y));

					return *menuItems[menuItems.size() - 1];
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

					if (active && Mouse::IsButtonPressed(Mouse::Button::Code::Left))
					{
						active = false;
						resetCurrentSprite = true;
					}

					for (size_t i = 0; i < menuItems.size(); i++)
					{
						menuItems[i]->Update();

						if (menuItems[i]->hovered && active && Mouse::IsButtonPressed(Mouse::Button::Code::Left) || resetCurrentSprite)
						{
							active = false;
							menuItems[i]->hovered = false;
							menuItems[i]->currentSprite = &menuItems[i]->widgetData.sprites[currentState + 0];
						}

						if (!menuItems[i]->hovered && !active || !menuItems[i]->hovered && active)
							menuItems[i]->currentSprite = &menuItems[i]->widgetData.sprites[currentState + 0];

						if (menuItems[i]->hovered && !active)
							menuItems[i]->currentSprite = &menuItems[i]->widgetData.sprites[currentState + 1];

						if (menuItems[i]->hovered && active)
							menuItems[i]->currentSprite = &menuItems[i]->widgetData.sprites[currentState + 2];

						if (menuItems[i]->hovered && Mouse::IsButtonPressed(Mouse::Button::Code::Left))
							active = true;
					}

					resetCurrentSprite = false;
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