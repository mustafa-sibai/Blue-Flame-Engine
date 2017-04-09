#pragma once
#ifdef BF_PLATFORM_WINDOWS
	//#include "BF/Platform/API/DirectX/DXFramebuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLFramebuffer.h"
#endif

#include "Texture2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API RenderTarget
			{
			private:
#ifdef BF_PLATFORM_WINDOWS
				//Platform::API::DirectX::DXFramebuffer dxFramebuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
				Platform::API::OpenGL::GLFramebuffer glFramebuffer;
#endif
				Texture2D texture2D;

			public:
				RenderTarget(const Shader& shader);
				~RenderTarget();

				void Create(unsigned int width, unsigned int height, Graphics::API::Texture::Format format, Graphics::API::Texture::Wrap wrap, Graphics::API::Texture::Filter filter);

				void Bind();
				void Unbind();

				inline const Texture2D& GetTexture2D() const { return texture2D; }
			};
		}
	}
}