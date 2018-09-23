#pragma once
#ifdef BF_PLATFORM_WINDOWS
	//#include "BF/Platform/API/DirectX/DXFramebuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
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

			class BF_API Framebuffer
			{
				private:
#ifdef BF_PLATFORM_WINDOWS
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
					Platform::API::OpenGL::GLFramebuffer glFramebuffer;
#endif

				public:
					FramebufferFormat format;

				public:
					Framebuffer();
					~Framebuffer();

					void Create(Graphics::API::Texture2D& texture2D, BF::Graphics::API::FramebufferFormat format);

					void Bind() const;
					void Unbind() const;
			};
		}
	}
}