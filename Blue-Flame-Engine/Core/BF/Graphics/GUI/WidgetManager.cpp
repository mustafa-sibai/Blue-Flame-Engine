#include "WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			WidgetManager::WidgetManager() :
				spriteRenderer(shader), styleSheet(shader)
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
				shader.Load("D:/Projects/Personal-Projects/Blue-Flame-Engine/Blue-Flame-Engine/Sandbox/Assets/Shaders/GLSL/SpriteRenderer/VertexShader.glsl", 
							"D:/Projects/Personal-Projects/Blue-Flame-Engine/Blue-Flame-Engine/Sandbox/Assets/Shaders/GLSL/SpriteRenderer/PixelShader.glsl");
				shader.Bind();
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
				spriteRenderer.Begin(BF::Graphics::Renderers::SpriteRenderer::SubmitType::DynamicSubmit);
				for (size_t i = 0; i < widgets.size(); i++)
					widgets[i]->Render();
				spriteRenderer.End();
			}
		}
	}
}