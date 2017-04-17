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
			class BF_API Checkbox : public Widget
			{
				private:
					bool checked;

				public:
					Checkbox(Application::Scene& scene);
					~Checkbox();

					inline bool IsChecked() const { return checked; }

				private:
					void Initialize(Renderers::SpriteRenderer& spriteRenderer) override;
					void Load(const StyleSheet& StyleSheet, const std::string& widgetName) override;
					void Update() override;
					void Render() override;
			};
		}
	}
}