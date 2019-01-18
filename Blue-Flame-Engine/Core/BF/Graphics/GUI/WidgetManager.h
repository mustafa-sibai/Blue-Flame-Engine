#pragma once
#include "BF/Graphics/GUI/StyleSheet.h"
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class LayerManager;
		}
	}

	namespace Graphics
	{
		namespace GUI
		{
			class BFE_API WidgetManager
			{
				//friend class BF::Application::Scene;

				private:
					StyleSheet styleSheet;

					//BF::Application::Layers::LayerManager& layerManager;

					/*std::vector<Widget*> widgets;
					std::vector<int> nullIndices;*/
					Widget* currentWidget;
					Widget* previousWidget;

				public:
					WidgetManager(/*BF::Application::Layers::LayerManager& layerManager*/);
					~WidgetManager();

					/*void AddWidget(Widget* widget);
					void RemoveWidget(Widget* widget);*/

				private:
					void Initialize();
					void Load();
					void Update();
					void Render();
			};
		}
	}
}