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
					private:
						const StyleSheet* styleSheet;
						bool active;
						bool resetCurrentSprite;

					public:
						std::vector<MenuItem*> menuItems;

					public:
						MenuStrip();
						~MenuStrip();

						const MenuItem& Instantiate(std::string name);

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