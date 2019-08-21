#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	//#include "BF/Platform/API/DirectX/DXFramebuffer.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLFramebuffer.h"
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class FramebufferFormat { Color, Depth, Stencil };

			class BFE_API Framebuffer
			{
			private:
#ifdef BFE_PLATFORM_WINDOWS
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				BF::Platform::API::OpenGL::GLFramebuffer glFramebuffer;
#endif

			public:
				FramebufferFormat format;

			public:
				Framebuffer();
				~Framebuffer();

				void Create(BF::Graphics::API::Texture2D& texture2D, BF::Graphics::API::FramebufferFormat format);

				void Bind() const;
				void Unbind() const;
			};
		}
	}
}