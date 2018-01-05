#pragma once
#include <vector>
#include "BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h"
#include "BF/Graphics/GUI/StyleSheet.h"
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Graphics
	{
		namespace GUI
		{
			class BF_API WidgetManager
			{
				friend class BF::Application::Scene;

				private:
					//Renderers::SpriteRenderer spriteRenderer;
					StyleSheet styleSheet;

					std::vector<Widget*> widgets;
					std::vector<int> nullIndices;
					Widget* currentWidget;
					Widget* previousWidget;

				public:
					WidgetManager();
					~WidgetManager();

					void AddWidget(Widget* widget);
					void RemoveWidget(Widget* widget);

				private:
					void Initialize();
					void Load();
					void Update();
					void Render();
			};
		}
	}
}