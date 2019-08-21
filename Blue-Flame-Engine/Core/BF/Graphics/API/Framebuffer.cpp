#include "Framebuffer.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Framebuffer::Framebuffer() :
				format(FramebufferFormat::Color)
			{
			}

			Framebuffer::~Framebuffer()
			{
			}

			void Framebuffer::Create(Texture2D& texture2D, FramebufferFormat format)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
				}
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glFramebuffer.Create(texture2D, format);
#endif
			}

			void Framebuffer::Bind() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
				}
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glFramebuffer.Bind();
#endif
			}

			void Framebuffer::Unbind() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
				}
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glFramebuffer.Unbind();
#endif
			}
		}
	}
}