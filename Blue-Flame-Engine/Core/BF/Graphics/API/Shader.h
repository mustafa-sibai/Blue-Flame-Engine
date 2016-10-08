#pragma once
#include "../../Platform/API/DirectX/DXShader.h"
#include "../../Platform/API/OpenGL/GLShader.h"
#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API Shader
			{
				private:
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXShader *dxShader;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					Platform::API::OpenGL::GLShader *glShader;
#endif
					Context *context;

				public:
					Shader(Context *context);
					~Shader();

					void Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath);
					void Bind();
					void CleanUp();

#ifdef BF_PLATFORM_WINDOWS
					inline Platform::API::DirectX::DXShader *GetDXShader() const { return dxShader; }
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					inline const Platform::API::OpenGL::GLShader *GetGLShader() const { return glShader; }
#endif
			};
		}
	}
}