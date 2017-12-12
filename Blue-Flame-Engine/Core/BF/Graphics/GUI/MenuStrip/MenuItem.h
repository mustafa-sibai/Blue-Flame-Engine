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
				class BF_API MenuItem : public Widget
				{
					friend class MenuStrip;

					private:
						const StyleSheet* styleSheet;

					public:
						std::vector<MenuItem> menuItems;

					public:
						MenuItem();
						~MenuItem();

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