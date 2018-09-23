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
			using namespace BF::Math;

			ForwardRenderer::ForwardRenderer(Camera& camera) : 
				camera(camera)
			{
			}

			ForwardRenderer::~ForwardRenderer()
			{
			}

			void ForwardRenderer::Initialize()
			{
				materialConstantBuffer.Create(sizeof(MeshMaterial::ColorBuffer), 2);
			}

			void ForwardRenderer::Render()
			{
				for (size_t i = 0; i < meshes.size(); i++)
				{
					Transform* transform = (Transform*)meshes[i]->gameObject->GetComponents()[0];
					camera.SetModelMatrix(Matrix4::Translate(transform->position) * Matrix4::Rotate(transform->angle, transform->rotation) * Matrix4::Scale(transform->scale));

					materialConstantBuffer.Update(&meshes[i]->material->colorBuffer, sizeof(MeshMaterial::ColorBuffer));

					meshes[i]->Bind();
					Engine::GetContext().Draw((unsigned int)meshes[i]->GetIndices().size());
					meshes[i]->Unbind();
				}
			}
		}
	}
}