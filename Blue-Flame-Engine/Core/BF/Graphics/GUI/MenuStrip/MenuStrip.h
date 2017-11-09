#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Application/Scene.h"
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
				public:
					MenuStrip(Application::Scene& scene);
					~MenuStrip();

				private:
					void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
					void Load(const StyleSheet& StyleSheet, const std::string& widgetName) override;
					void Update() override;
					void Render() override;
				};
			}
		}
	}
}