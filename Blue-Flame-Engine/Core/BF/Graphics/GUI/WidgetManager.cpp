#include "WidgetManager.h"
#include "BF/Engine.h"
//#include "BF/Application/Layers/LayerManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Renderers;

			WidgetManager::WidgetManager(/*BF::Application::Layers::LayerManager& layerManager*/) :
				/*layerManager(layerManager),*/ currentWidget(nullptr), previousWidget(nullptr)
			{
			}

			WidgetManager::~WidgetManager()
			{
			}

			/*void WidgetManager::AddWidget(Widget* widget)
			{
				int index = 0;

				if (nullIndices.size() <= 0)
				{
					widgets.emplace_back(widget);

					index = widgets.size() - 1;
					widgets[index]->index = index;
					//widgets[index]->Initialize(spriteRenderer, index);
					widgets[index]->Load(styleSheet, "");
				}
				else
				{
					index = nullIndices[0];
					widgets[index] = widget;
					widgets[index]->index = index;
					//widgets[index]->Initialize(spriteRenderer, index);
					widgets[index]->Load(styleSheet, "");
				}
			}

			void WidgetManager::RemoveWidget(Widget* widget)
			{
				nullIndices.emplace_back(widget->index);
				widgets[widget->index] = nullptr;
			}*/

			void WidgetManager::Initialize()
			{
				//spriteRenderer.Initialize();
			}

			void WidgetManager::Load()
			{
				styleSheet.Load("../Sandbox/Assets/GUI/StyleSheet.xml");
			}

			void WidgetManager::Update()
			{
				/*for (size_t i = 0; i < widgets.size(); i++)
				{
					if (widgets[i]->IsMouseOnWidget())
					{
						if (currentWidget == nullptr || currentWidget->GetZLayer() < widgets[i]->GetZLayer())
							currentWidget = widgets[i];
					}
				}

				if (previousWidget != nullptr)
					if (currentWidget != previousWidget || previousWidget->IsMouseOnWidget())
						previousWidget->SetCurrentSpriteToNormal();

				if (currentWidget != nullptr)
				{
					currentWidget->Update();
					previousWidget = currentWidget;
					currentWidget = nullptr;
				}*/

				/*for (size_t i = 0; i < layerManager.GetLayer(1).GetSize(); i++)
				{
					Widget& widget = (Widget&)layerManager.GetLayer(1).GetGameNode(i);
					widget.Update();
				}*/
			}

			void WidgetManager::Render()
			{
				/*spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);
				for (size_t i = 0; i < widgets.size(); i++)
				{
					if (widgets[i] != nullptr)
						widgets[i]->Render();
				}
				spriteRenderer.SetScissor(Math::Rectangle(0, 0, Engine::GetWindow().GetClientWidth(), Engine::GetWindow().GetClientHeight()));
				spriteRenderer.End();*/
			}
		}
	}
}