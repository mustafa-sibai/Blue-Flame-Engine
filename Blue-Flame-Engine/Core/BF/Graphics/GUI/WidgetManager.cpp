#include "WidgetManager.h"

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
					widgets[i]->Initialize(spriteRenderer);
			}

			void WidgetManager::Load()
			{
				styleSheet.Load("D:/Projects/Personal-Projects/Blue-Flame-Engine/Blue-Flame-Engine/Sandbox/Assets/GUI/StyleSheet.xml");

				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Load(styleSheet, "");
			}

			void WidgetManager::Update()
			{
				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Update();
			}

			void WidgetManager::Render()
			{
				spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::None);
				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Render();
				spriteRenderer.End();
			}
		}
	}
}