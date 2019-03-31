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

			void GUISystem::Update()
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