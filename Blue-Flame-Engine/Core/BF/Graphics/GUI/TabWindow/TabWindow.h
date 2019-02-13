#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Graphics/GUI/TabWindow/Tab.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace TabWindow
			{
				class BF_API TabWindow : public Widget
				{
					private:
						Tab tab;

					public:
						TabWindow();
						~TabWindow();

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