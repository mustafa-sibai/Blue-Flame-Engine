#include "SkyboxRenderer.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;
			using namespace BF::Graphics::API;

			SkyboxRenderer::SkyboxRenderer() :
				Renderer(Renderer::RendererType::SkyboxRenderer),
				textureCube(shader)
			{
			}

			SkyboxRenderer::~SkyboxRenderer()
			{
			}

			void SkyboxRenderer::Initialize()
			{
				vertcies =
				{
					-1.0f,  1.0f, -1.0f,
					-1.0f, -1.0f, -1.0f,
					 1.0f, -1.0f, -1.0f,
					 1.0f,  1.0f, -1.0f,
					-1.0f, -1.0f,  1.0f,
					-1.0f,  1.0f,  1.0f,
					 1.0f, -1.0f,  1.0f,
					 1.0f,  1.0f,  1.0f,
				};

				indices = { 0, 1, 2, 2, 3, 0, 4, 1, 0, 0, 5, 4, 2, 6, 7, 7, 3, 2, 4, 5, 7, 7, 6, 4, 0, 3, 7, 7, 5, 0, 1, 4, 2, 2, 4, 6 };
			}

			void SkyboxRenderer::Load(const vector<string>& filenames)
			{
				vertexBuffer.Create((unsigned int)vertcies.size() * sizeof(float), &vertcies[0]);
				indexBuffer.Create(&indices[0], (unsigned int)indices.size() * sizeof(unsigned int));

				vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, sizeof(float) * 3, 0);
				vertexBuffer.SetLayout(shader, &vertexBufferLayout);

				shader.LoadStandardShader(ShaderType::TextureCube);
				textureCube.Load(filenames, Texture::Wrap::ClampToEdge, Texture::Filter::Bilinear);
			}

			void SkyboxRenderer::Render()
			{
				Engine::GetContext().EnableDepthMask(false);
				shader.Bind();
				textureCube.Bind();
				vertexBuffer.Bind();
				indexBuffer.Bind();
				Engine::GetContext().Draw((unsigned int)indices.size());
				indexBuffer.Unbind();
				vertexBuffer.Unbind();
				textureCube.Unbind();
				shader.Unbind();
				Engine::GetContext().EnableDepthMask(true);
			}

			void SkyboxRenderer::Bind()
			{
				textureCube.Bind();
			}

			void SkyboxRenderer::Unbind()
			{
				textureCube.Unbind();
			}
		}
	}
}