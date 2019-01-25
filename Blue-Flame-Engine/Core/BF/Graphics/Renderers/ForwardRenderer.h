#pragma once
#include <vector>
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/Renderers/Renderer.h"
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
			class BFE_API ForwardRenderer : public Renderer
			{
				friend class BF::Graphics::Renderers::RenderPipeline;

				private:
					BF::Graphics::CameraManager& cameraManager;
					std::vector<BF::Graphics::Mesh*> meshes;
					BF::Graphics::Materials::MaterialManager materialManager;

					/*BF::Graphics::Mesh* postProcessingQuad;
					BF::Graphics::Materials::MeshMaterial* screenPlaneMaterial;

					BF::Graphics::API::Framebuffer postProcessingFramebuffer;
					BF::Graphics::API::Texture2D postProcessingTexture;
					BF::Graphics::API::Shader postProcessingShader;*/

				public:
					ForwardRenderer(BF::Graphics::CameraManager& cameraManager);
					~ForwardRenderer();

					void Initialize() override;
					void PostLoad() override;
					void Render() override;
			};
		}
	}
}