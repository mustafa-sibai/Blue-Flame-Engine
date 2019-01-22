#include "ForwardRenderer.h"
#include "BF/Engine.h"
#include "BF/Math/Vector3.h"
#include "BF/Math/Matrix4.h"
#include "BF/ECS/GameObject.h"
#include "BF/Graphics/Transform.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Graphics::Materials;
			using namespace BF::Graphics::API;
			using namespace BF::Math;

			ForwardRenderer::ForwardRenderer(Camera* camera) :
				Renderer(RendererType::ForwardRenderer),
				camera(camera)
			{
			}

			ForwardRenderer::~ForwardRenderer()
			{
			}

			void ForwardRenderer::Initialize()
			{
				//camera.Initialize(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
				materialManager.Initialize();
			}

			void ForwardRenderer::PostLoad()
			{
				for (size_t i = 0; i < 2; i++)
				{
					materialManager.SetMaterial(*meshes[i]->material);
				}
			}

			void ForwardRenderer::Render()
			{
				for (size_t i = 0; i < meshes.size(); i++)
				{
					Transform* transform = (Transform*)meshes[i]->gameObject->GetComponents()[0];

					if(camera != nullptr)
						camera->SetModelMatrix(transform->GetWorldTransformation());

					meshes[i]->material->Bind();
					meshes[i]->Bind();
					Engine::GetContext().Draw((unsigned int)meshes[i]->meshData->indices->size());
					meshes[i]->Unbind();
					meshes[i]->material->Unbind();
				}
			}
		}
	}
}