#include "ForwardRenderer.h"
#include "BF/Engine.h"
#include "BF/Math/Vector3.h"
#include "BF/Math/Matrix4.h"
#include "BF/ECS/GameObject.h"
#include "BF/Graphics/CameraManager.h"
#include "BF/Graphics/Transform.h"
#include "BF/Graphics/ConstantBufferManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Graphics::Materials;
			using namespace BF::Graphics::API;
			using namespace BF::Math;

			ForwardRenderer::ForwardRenderer(BF::Graphics::ConstantBufferManager& constantBufferManager, CameraManager& cameraManager) :
				IRenderer(RendererType::ForwardRenderer),
				materialManager(constantBufferManager), constantBufferManager(constantBufferManager), cameraManager(cameraManager)
			{
			}

			ForwardRenderer::~ForwardRenderer()
			{
			}

			void ForwardRenderer::Initialize()
			{
				materialManager.Initialize();
			}

			void ForwardRenderer::Load()
			{
			}

			void ForwardRenderer::PostLoad()
			{
				/*for (size_t i = 0; i < meshes.size(); i++)
				{
					materialManager.AddMaterial(*meshes[i]->material);
				}*/
			}

			void ForwardRenderer::Update(double deltaTime)
			{
			}

			void ForwardRenderer::Render()
			{
				for (size_t i = 0; i < models.size(); i++)
				{
					Transform* transform = (Transform*)models[i]->gameObject->GetComponents()[0];

					cameraManager.GetMainCamera().SetModelMatrix(transform->GetWorldTransformation());

					for (size_t j = 0; j < models[i]->meshes.size(); j++)
					{
						models[i]->meshes[j].material.Bind(constantBufferManager);
						models[i]->meshes[j].Bind();
						Engine::GetContext().Draw((unsigned int)models[i]->meshes[j].meshData->indices->size());
						models[i]->meshes[j].material.Unbind();
						models[i]->meshes[j].Unbind();
					}
				}
			}
		}
	}
}