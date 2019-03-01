#include "PostProcessing.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Materials;

			PostProcessing::PostProcessing() :
				Renderer(RendererType::PostProcessing)
			{
			}

			PostProcessing::~PostProcessing()
			{
			}
			void PostProcessing::Initialize()
			{
				//BF::Engine::GetContext().EnableDepthBuffer(true);
				postProcessingTexture.Create(new TextureData(Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, nullptr), Texture::Format::R8G8B8A8);
				postProcessingFramebuffer.Create(postProcessingTexture, FramebufferFormat::Color);
				postProcessingShader.LoadStandardShader(ShaderType::PostProcessing);

				postProcessingQuad = new Mesh(Mesh::PresetMeshes::Plane);
				screenPlaneMaterial = new MeshMaterial();

				screenPlaneMaterial->shader = &postProcessingShader;
				//postProcessingQuad->SetBuffers(screenPlaneMaterial);
			}

			void PostProcessing::PostLoad()
			{
			}

			void PostProcessing::Render()
			{
				BF::Engine::GetContext().Clear(BufferClearType::Color, Color(0, 0, 0, 1.0f));
				BF::Engine::GetContext().EnableDepthBuffer(false);

				postProcessingShader.Bind();
				postProcessingQuad->Bind();
				postProcessingTexture.Bind(postProcessingShader, "screenTexture", 0);
				Engine::GetContext().Draw((unsigned int)postProcessingQuad->meshData->indices->size());
				postProcessingTexture.Unbind();
				postProcessingQuad->Unbind();
				postProcessingShader.Unbind();
			}

			void PostProcessing::Bind()
			{
				postProcessingFramebuffer.Bind();
			}

			void PostProcessing::Unbind()
			{
				postProcessingFramebuffer.Unbind();
			}
		}
	}
}