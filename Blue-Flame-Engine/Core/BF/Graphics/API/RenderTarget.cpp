#include "RenderTarget.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			RenderTarget::RenderTarget()
			{
			}

			RenderTarget::~RenderTarget()
			{
			}

			void RenderTarget::Create(unsigned int width, unsigned int height, Texture::Format format, Texture::Wrap wrap, Texture::Filter filter)
			{
				texture2D.Create(new TextureData(width, height, nullptr), format, wrap, filter);
				framebuffer.Create(texture2D, FramebufferFormat::Color);
			}

			void RenderTarget::Bind() const
			{
				framebuffer.Bind();
			}

			void RenderTarget::Unbind() const
			{
				framebuffer.Unbind();
			}
		}
	}
}