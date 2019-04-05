#pragma once
#include <vector>
#include "BF/ECS/ISystem.h"
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
			class GUISystem : public BF::ECS::ISystem
			{
			private:
				BF::Graphics::Renderers::RenderPipeline& renderPipeline;
				BF::Graphics::GUI::StyleSheet styleSheet;
				std::vector<BF::Graphics::GUI::IWidget*> widgets;

			public:
				GUISystem(BF::Graphics::Renderers::RenderPipeline& renderPipeline);
				~GUISystem();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void AddWidget(IWidget* iWidget);
				void RemoveWidget(IWidget* iWidget);
			};
		}
	}
}