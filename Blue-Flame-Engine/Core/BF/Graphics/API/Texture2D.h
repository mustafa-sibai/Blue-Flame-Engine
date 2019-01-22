#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXTexture2D.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLTexture2D.h"
#endif

#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/API/Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class GLFramebuffer;
			}
		}
	}

	namespace Graphics
	{
		namespace API
		{
			class BFE_API Texture2D : public Texture
			{
				friend class BF::Platform::API::OpenGL::GLFramebuffer;

				private:
#ifdef BFE_PLATFORM_WINDOWS
					Platform::API::DirectX::DXTexture2D dxTexture2D;
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
					Platform::API::OpenGL::GLTexture2D glTexture2D;
#endif
				public:
					Texture2D();
					~Texture2D();

					//void Load(const std::string& filename);
					//void Load(const std::string& filename, Wrap wrap, Filter filter);
					void Create(TextureData* textureData, Format format, Wrap wrap, Filter filter);
					void Create(TextureData* textureData, Format format);

					void Bind() const;
					void Bind(const Shader& shader, const std::string& samplerName, unsigned int index) const;
					void Unbind() const;
					void Unbind(const std::string& samplerName, unsigned int index) const;
			};
		}
	}
}