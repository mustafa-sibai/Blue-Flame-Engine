#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXShader.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
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
			enum class BFE_API ShaderType { SingleLight3D, _3D, _3DMipAF, Light, SpriteRenderer, TextureCube, Terrain, P, PUV, PUVN, PN, PUVNTB, PostProcessing };

			class BFE_API Shader
			{
				friend class VertexBuffer;
				friend class Texture2D;

				private:
#ifdef BFE_PLATFORM_WINDOWS
					Platform::API::DirectX::DXShader dxShader;
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
					Platform::API::OpenGL::GLShader glShader;
#endif
					static int globalID;
					int id;

				public:
					Shader();
					~Shader();

					void LoadStandardShader(ShaderType type);
					void LoadFromFile(const std::string& vertexShaderFilePath, const std::string& pixelShaderFilePath);
					void CleanUp();

					void Bind() const;
					void Unbind() const;

					inline int GetID() const { return id; }
			};
		}
	}
}