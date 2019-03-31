#pragma once
#include <vector>
#include "BF/Graphics/GUI3/Widget.h"
#include "BF/Graphics/GUI3/StyleSheet.h"
#include "BF/Graphics/Renderers/RenderPipeline.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class GUISystem
			{
			private:
				BF::Graphics::Renderers::RenderPipeline& renderPipeline;
				BF::Graphics::GUI::StyleSheet styleSheet;
				std::vector<BF::Graphics::GUI::IWidget*> widgets;

			public:
				GUISystem(BF::Graphics::Renderers::RenderPipeline& renderPipeline);
				~GUISystem();

				void Initialize();
				void Load();
				void PostLoad();
				void Update();

				void AddWidget(IWidget* iWidget);
				void RemoveWidget(IWidget* iWidget);
			};
		}
	}
}