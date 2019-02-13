#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Graphics/GUI/MenuStrip/MenuItem.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace MenuStrip
			{
				class BF_API MenuStrip : public Widget
				{
					friend class MenuItem;

					private:
						const StyleSheet* styleSheet;
						bool active;
						std::vector<MenuItem*> menuItems;
						MenuItem* activeMenuItemOnMenuStrip;
						MenuItem* activeSubMenuItem;
						MenuItem* previousActiveSubMenuItem;

					public:
						MenuStrip();
						~MenuStrip();

						MenuItem* Instantiate(const std::string& name);

					private:
						void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
						void Load(const StyleSheet& styleSheet, const std::string& widgetName) override;
						void Update() override;
						void Render() override;
				};
			}
		}
	}
}