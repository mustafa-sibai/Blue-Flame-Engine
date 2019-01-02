#pragma once
#include <vector>
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/API/Framebuffer.h"
#include "BF/Graphics/Materials/MaterialManager.h"
#include "BF/Graphics/Mesh.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API ForwardRenderer
			{
				friend class BF::Application::Scene;

				private:
					BF::Graphics::Camera& camera;
					std::vector<BF::Graphics::Mesh*> meshes;
					BF::Graphics::Materials::MaterialManager materialManager;

					/*BF::Graphics::Mesh* postProcessingQuad;
					BF::Graphics::Materials::MeshMaterial* screenPlaneMaterial;

					BF::Graphics::API::Framebuffer postProcessingFramebuffer;
					BF::Graphics::API::Texture2D postProcessingTexture;
					BF::Graphics::API::Shader postProcessingShader;*/

				public:
					ForwardRenderer(BF::Graphics::Camera& camera);
					~ForwardRenderer();

					void Initialize();
					void PostLoad();
					void Render();
			};
		}
	}
}