#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace MenuStrip
			{
				class MenuStrip;

				class BF_API MenuItem : public Widget
				{
					friend class MenuStrip;

					private:
						const StyleSheet* styleSheet;
						std::vector<MenuItem*> menuItems;
						MenuStrip* menuStrip;
						MenuItem* parent;
						int parentCount;

					public:
						bool activeSubMenu;

					public:
						MenuItem(MenuStrip* menuStrip, MenuItem* parent);
						~MenuItem();

						MenuItem* Instantiate(const std::string& name);

						inline const MenuItem* GetParent() { return parent; }

					private:
						void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
						void Load(const StyleSheet& styleSheet, const std::string& widgetName) override;
						void Update() override;
						void Render() override;

						void DeactivateMenuItemToRoot(MenuItem* menuItem);
						void DeactivateMenuItemToThis(MenuItem* menuItem);
				};
			}
		}
	}
}