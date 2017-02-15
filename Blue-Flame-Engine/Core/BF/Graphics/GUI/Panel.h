#pragma once
#include "Widget.h"
#include "BF/Application/Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API Panel : public Widget
			{
			public:
				Panel(Application::Scene& scene);
				~Panel();

			private:
				void Initialize(Renderers::SpriteRenderer& spriteRenderer) override;
				void Load(const StyleSheet& StyleSheet, const std::string& widgetName) override;
				void Update() override;
				void Render() override;
			};
		}
	}
}