#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BFE_API Checkbox : public Widget
			{
				private:
					bool checked;

				public:
					Checkbox();
					~Checkbox();

					inline bool IsChecked() const { return checked; }

				private:
					void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
					void Load(const StyleSheet& styleSheet, const std::string& widgetName) override;
					void Update() override;
					void Render() override;
			};
		}
	}
}