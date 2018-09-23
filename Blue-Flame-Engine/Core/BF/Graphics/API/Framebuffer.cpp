#include "Framebuffer.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Framebuffer::Framebuffer()
			{
			}

			Framebuffer::~Framebuffer()
			{
			}

			void Framebuffer::Create(Texture2D& texture2D, FramebufferFormat format)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
				}
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glFramebuffer.Create(texture2D, format);
#endif
			}

			void Framebuffer::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
				}
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glFramebuffer.Bind();
#endif
			}

			void Framebuffer::Unbind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
				}
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glFramebuffer.Unbind();
#endif
			}
		}
	}
}