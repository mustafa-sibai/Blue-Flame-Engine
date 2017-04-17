#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Graphics/GUI/ScrollbarSlider.h"
#include "BF/Application/Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class Panel;

			class BF_API Scrollbar : public Widget
			{
				friend class Panel;
				friend class ScrollbarSlider;

			public:
				Panel& panel;
				ScrollbarSlider slider;

				ScrollbarSlider::Orientation orientation;

			public:
				Scrollbar(Panel& panel, ScrollbarSlider::Orientation orientation);
				~Scrollbar();

			protected:
				void Initialize(Renderers::SpriteRenderer& spriteRenderer) override;
				void Load(const StyleSheet& StyleSheet, const std::string& widgetName) override;
				void Update() override;
				void Render() override;

			private:
				inline void SetPositionAndSize();
			};
		}
	}
}