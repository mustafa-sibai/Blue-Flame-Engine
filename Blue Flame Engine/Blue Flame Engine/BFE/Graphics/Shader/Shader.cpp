#include "Shader.h"

namespace BFE
{
	namespace Graphics
	{
		Shader::Shader(Renderer &renderer) :
			renderer(renderer), dx11Shader(renderer.GetDx11Renderer()), glShader()
		{
		}

		Shader::~Shader()
		{
		}

		void Shader::Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath)
		{
			if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				dx11Shader.Load(vertexShaderFilePath, pixelShaderFilePath);
			else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				glShader.Load(vertexShaderFilePath, pixelShaderFilePath);
		}

		void Shader::Bind()
		{
			if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				dx11Shader.Bind();
			else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				glShader.Bind();
		}

		void Shader::CleanUp()
		{
			if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				dx11Shader.CleanUp();
		}
	}
}