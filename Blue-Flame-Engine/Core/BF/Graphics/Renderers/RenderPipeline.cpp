#include "RenderPipeline.h"
#include "BF/ECS/Component.h"
#include "BF/Engine.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;
			using namespace BF::ECS;
			using namespace BF::Graphics::API;

			RenderPipeline::RenderPipeline() :
				camera(nullptr), spriteRenderer(nullptr), forwardRenderer(nullptr), postProcessing(nullptr)
			{
				//skyboxRenderer = new SkyboxRenderer();
				//forwardRenderer = new ForwardRenderer(camera);
				spriteRenderer = new SpriteRenderer();
				//spriteRenderer->SetSortingOrder(SpriteRenderer::SortingOrder::BackToFront);
				//postProcessing = new PostProcessing();
			}

			RenderPipeline::~RenderPipeline()
			{
			}

			void RenderPipeline::Initialize()
			{
				if (camera != nullptr)			camera->Initialize();
				if (spriteRenderer != nullptr)	spriteRenderer->Initialize();
				if (forwardRenderer != nullptr) forwardRenderer->Initialize();
				if (postProcessing != nullptr)	postProcessing->Initialize();
			}

			void RenderPipeline::Load()
			{
			}

			void RenderPipeline::PostLoad()
			{
				if (spriteRenderer != nullptr)	spriteRenderer->PostLoad();
				if (forwardRenderer != nullptr) forwardRenderer->PostLoad();
				if (postProcessing != nullptr)	postProcessing->PostLoad();
			}

			void RenderPipeline::Update()
			{
				if (camera != nullptr)			camera->Update();
				if (spriteRenderer != nullptr)	spriteRenderer->Update();
				if (forwardRenderer != nullptr) forwardRenderer->Update();
				if (postProcessing != nullptr)	postProcessing->Update();
			}

			void RenderPipeline::Render()
			{
				camera->Clear(BufferClearType::ColorAndDepth, Color(0.5, 0.0f, 0.0f, 1.0f));
				if (postProcessing != nullptr)	postProcessing->Bind();
				if (spriteRenderer != nullptr)	spriteRenderer->Render();
				if (forwardRenderer != nullptr) forwardRenderer->Render();
				if (postProcessing != nullptr)	postProcessing->Unbind();
				if (postProcessing != nullptr)	postProcessing->Render();
				camera->SwapBuffers();
			}

			void RenderPipeline::AddRenderable(Component* component)
			{
				switch (component->type)
				{
				case Component::Type::Camera:
				{
					if (camera == nullptr)
						camera = (Camera*)component;
					break;
				}
				case Component::Type::Renderable:
				{
					if (spriteRenderer != nullptr)
						spriteRenderer->renderables.emplace_back((Renderable*)component);
					break;
				}
				case Component::Type::Mesh:
				{
					if (forwardRenderer != nullptr)
						forwardRenderer->meshes.emplace_back((Mesh*)component);
					break;
				}
				default:
					break;
				}
			}

			void RenderPipeline::RemoveRenderable(BF::ECS::Component * component)
			{
			}
		}
	}
}