#pragma once
#include <vector>
#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "StyleSheet.h"
#include "Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API WidgetManager
			{
			private:
				Renderers::SpriteRenderer spriteRenderer;
				StyleSheet styleSheet;

			public:
				std::vector<Widget*> widgets;

			public:
				WidgetManager();
				~WidgetManager();

				void AddWidget(Widget* widget);
				void Initialize();
				void Load();
				void Update();
				void Render();
			};
		}
	}
}