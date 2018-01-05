#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace Slidebar
			{
				class BF_API Slidebar : public Widget
				{
					public:
						Slidebar();
						~Slidebar();

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