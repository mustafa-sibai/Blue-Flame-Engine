#include "WidgetManager.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Renderers;

			WidgetManager::WidgetManager() :
				currentWidget(nullptr), previousWidget(nullptr)
			{
			}

			WidgetManager::~WidgetManager()
			{
			}

			void WidgetManager::AddWidget(Widget* widget)
			{
				widgets.emplace_back(widget);

				widgets[widgets.size() - 1]->Initialize(spriteRenderer, (int)(widgets.size() - 1));
				widgets[widgets.size() - 1]->Load(styleSheet, "");
			}

			void WidgetManager::Initialize()
			{
				spriteRenderer.Initialize();
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

				for (size_t i = 0; i < widgets.size(); i++)
				{
					widgets[i]->Update();
				}
			}

			void WidgetManager::Render()
			{
				spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);
				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Render();
				spriteRenderer.SetScissor(Math::Rectangle(0, 0, Engine::GetWindow().GetClientWidth(), Engine::GetWindow().GetClientHeight()));
				spriteRenderer.End();
			}
		}
	}
}