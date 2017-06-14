#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXShader.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLShader.h"
#endif

#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class BF_API ShaderType { SingleLight3D, _3D, _3DMipAF, Light, SpriteRenderer, TextureCube };

			class BF_API Shader
			{
				friend class VertexBuffer;
				friend class Texture2D;

				private:
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXShader dxShader;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
					Platform::API::OpenGL::GLShader glShader;
#endif
				public:
					Shader();
					~Shader();

					void LoadStandardShader(ShaderType type);
					void LoadFromFile(const std::string& vertexShaderFilePath, const std::string& pixelShaderFilePath);
					void CleanUp();

					void Bind() const;
					void Unbind() const;
			};
		}
	}
}