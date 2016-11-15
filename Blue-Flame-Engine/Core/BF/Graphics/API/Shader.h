#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXShader.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
	#include "BF/Platform/API/OpenGL/GLShader.h"
#endif

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
					Platform::API::DirectX::DXShader* dxShader;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
					Platform::API::OpenGL::GLShader* glShader;
#endif
					Context* context;

				public:
					Shader(Context* context);
					~Shader();

					void Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath);
					void CleanUp();

					void Bind() const;

#ifdef BF_PLATFORM_WINDOWS
					inline Platform::API::DirectX::DXShader* GetDXShader() const { return dxShader; }
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
					inline Platform::API::OpenGL::GLShader* GetGLShader() const { return glShader; }
#endif
			};
		}
	}
}