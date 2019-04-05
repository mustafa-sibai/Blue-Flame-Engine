#pragma once
#include <vector>
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/Renderers/IRenderer.h"
#include "BF/Graphics/API/Framebuffer.h"
#include "BF/Graphics/Materials/MaterialManager.h"
#include "BF/Graphics/Mesh.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API PostProcessing : public BF::Graphics::Renderers::IRenderer
			{

			private:
				BF::Graphics::Mesh* postProcessingQuad;
				BF::Graphics::Materials::MeshMaterial* screenPlaneMaterial;

				BF::Graphics::API::Framebuffer postProcessingFramebuffer;
				BF::Graphics::API::Texture2D postProcessingTexture;
				BF::Graphics::API::Shader postProcessingShader;

			public:
				PostProcessing();
				~PostProcessing();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void Bind();
				void Unbind();
			};
		}
	}
}