#include "Shader.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Shader::Shader(const Context* context) :
				context(context)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader = new BF::Platform::API::DirectX::DXShader(context->GetDXContext());
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader = new BF::Platform::API::OpenGL::GLShader();
#endif
			}

			Shader::~Shader()
			{
			}

			void Shader::Load(const std::string& vertexShaderFilePath, const std::string& pixelShaderFilePath)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader->Load(vertexShaderFilePath, pixelShaderFilePath);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader->Load(vertexShaderFilePath, pixelShaderFilePath);
#endif
			}

			void Shader::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader->Bind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader->Bind();
#endif	
			}

			void Shader::CleanUp()
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader->CleanUp();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
				{
				}
#endif	
			}
		}
	}
}