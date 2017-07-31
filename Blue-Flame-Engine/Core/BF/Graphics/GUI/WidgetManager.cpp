#include "WidgetManager.h"
#include "BF/Engine.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Renderers;

			WidgetManager::WidgetManager() :
				styleSheet(spriteRenderer.GetShader())
			{
			}

			WidgetManager::~WidgetManager()
			{
			}

			void WidgetManager::AddWidget(Widget* widget)
			{
				widgets.push_back(widget);
			}

			void WidgetManager::Initialize()
			{
				spriteRenderer.Initialize();

				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Initialize(spriteRenderer, i);
			}

			void WidgetManager::Load()
			{
				styleSheet.Load("../Sandbox/Assets/GUI/StyleSheet.xml");

				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Load(styleSheet, "");
			}

			void WidgetManager::Update()
			{
				for (size_t i = 0; i < widgets.size(); i++)
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
				}
			}

			Widget* currentWidget;
			Widget* previousWidget;

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