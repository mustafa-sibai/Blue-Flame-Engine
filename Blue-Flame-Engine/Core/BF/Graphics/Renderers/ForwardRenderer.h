#pragma once
#include <vector>
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/Renderers/IRenderer.h"
#include "BF/Graphics/API/Framebuffer.h"
#include "BF/Graphics/Materials/MaterialManager.h"
#include "BF/Graphics/Model.h"
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
			class BFE_API ForwardRenderer : public BF::Graphics::Renderers::IRenderer
			{
				friend class BF::Graphics::Renderers::RenderPipeline;

			private:
				BF::Graphics::ConstantBufferManager& constantBufferManager;
				BF::Graphics::CameraManager& cameraManager;
				std::vector<BF::Graphics::Model*> models;
				BF::Graphics::Materials::MaterialManager materialManager;

				/*BF::Graphics::Mesh* postProcessingQuad;
				BF::Graphics::Materials::MeshMaterial* screenPlaneMaterial;

				BF::Graphics::API::Framebuffer postProcessingFramebuffer;
				BF::Graphics::API::Texture2D postProcessingTexture;
				BF::Graphics::API::Shader postProcessingShader;*/

			public:
				ForwardRenderer(BF::Graphics::ConstantBufferManager& constantBufferManager, BF::Graphics::CameraManager& cameraManager);
				~ForwardRenderer();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;
			};
		}
	}
}