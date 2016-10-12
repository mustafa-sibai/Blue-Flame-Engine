#include "Shader.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Shader::Shader(Context *context) :
				context(context)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader = new Platform::API::DirectX::DXShader(context->GetDXContext());
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader = new Platform::API::OpenGL::GLShader();
#endif
			}

			Shader::~Shader()
			{
			}

			void Shader::Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader->Load(vertexShaderFilePath, pixelShaderFilePath);
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader->Load(vertexShaderFilePath, pixelShaderFilePath);
#endif
			}

			const void Shader::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader->Bind();
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
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
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
				{
				}
#endif	
			}
		}
	}
}