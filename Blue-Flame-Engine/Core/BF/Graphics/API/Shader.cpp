#include "Shader.h"
#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace std;

			Shader::Shader()
			{
			}

			Shader::~Shader()
			{
			}

			void Shader::Load(const string& vertexShaderFilePath, const string& pixelShaderFilePath)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader.Load(vertexShaderFilePath, pixelShaderFilePath);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader.Load(vertexShaderFilePath, pixelShaderFilePath);
#endif
			}

			void Shader::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader.Bind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glShader.Bind();
#endif	
			}

			void Shader::CleanUp()
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxShader.CleanUp();
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