#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXTexture2D.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLTexture2D.h"
#endif

#include "Shader.h"
#include "Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API Texture2D : public Texture
			{
				friend class BF::Platform::API::OpenGL::GLFramebuffer;

				private:
					const Shader& shader;

#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXTexture2D dxTexture2D;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL) || defined (BF_PLATFORM_ANDROID)
					Platform::API::OpenGL::GLTexture2D glTexture2D;
#endif
				public:
					Texture2D(const Shader& shader);
					~Texture2D();

					void Load(const std::string& fileName);
					void Load(const std::string& fileName, TextureWrap textureWrap, TextureFilter textureFilter);
					void Create(const TextureData& textureData, Format format);
					void Create(const TextureData& textureData, Format format, TextureWrap textureWrap, TextureFilter textureFilter);

					void Bind() const;
					void Bind(const std::string& samplerName, unsigned int index) const;
					void Unbind() const;
					void Unbind(const std::string& samplerName, unsigned int index) const;
			};
		}
	}
}