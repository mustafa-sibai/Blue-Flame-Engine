#include "GUISystem.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/GUI3/Button.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::ECS;

			GUISystem::GUISystem(BF::Graphics::Renderers::RenderPipeline& renderPipeline) :
				renderPipeline(renderPipeline), styleSheet(*renderPipeline.spriteRenderer->renderLayerManager.GetGUIRenderLayer())
			{
			}

			GUISystem::~GUISystem()
			{
			}

			void GUISystem::Initialize()
			{
			}

			void GUISystem::Load()
			{
				styleSheet.Load("../Sandbox/Assets/GUI/StyleSheet.xml");
			}

			void GUISystem::PostLoad()
			{
			}

			void GUISystem::Update(double deltaTime)
			{
				for (size_t i = 0; i < widgets.size(); i++)
				{
					if (widgets[i]->IsSameType<Button>())
					{
						//widgets[i] is a button. cast it to a button pointer ((Button*)widgets[i]) and now you can
						//access the button class and do whatever
						//check if button is clicked or hovered or released
						//You can get mouse stuff by doing
						//BF::Input::Mouse:: etc......
					}
				}
			}

			void GUISystem::Render()
			{
			}

			void GUISystem::AddWidget(IWidget* iWidget)
			{
				if (iWidget->IsSameType<Button>())
				{
					*iWidget = styleSheet.GetWidget("Button");
				}

				renderPipeline.AddRenderable((IComponent*)iWidget->currentSprite);
				widgets.emplace_back(iWidget);
			}

			void GUISystem::RemoveWidget(IWidget* iWidget)
			{
			}
		}
	}
}