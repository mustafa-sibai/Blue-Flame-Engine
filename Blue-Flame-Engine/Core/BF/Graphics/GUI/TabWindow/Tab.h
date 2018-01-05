#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace TabWindow
			{
				class TabWindow;

				class BF_API Tab : public Widget
				{
					friend class TabWindow;

					public:
						Tab();
						~Tab();

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