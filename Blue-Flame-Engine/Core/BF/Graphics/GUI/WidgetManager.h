#pragma once
#include <vector>
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "StyleSheet.h"
#include "Widget.h"
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
					Renderers::SpriteRenderer spriteRenderer;
					StyleSheet styleSheet;

				public:
					std::vector<Widget*> widgets;

				public:
					WidgetManager();
					~WidgetManager();

					void AddWidget(Widget* widget);

				private:
					void Initialize();
					void Load();
					void Update();
					void Render();
			};
		}
	}
}