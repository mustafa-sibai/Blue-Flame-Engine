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
			class BF_API Button : public Widget
			{
			public:
				Button(Application::Scene& scene);
				~Button();

			private:
				void Initialize(Renderers::SpriteRenderer& spriteRenderer) override;
				void Load(const StyleSheet& StyleSheet, const std::string& widgetName) override;
				void Update() override;
				void Render() override;
			};
		}
	}
}