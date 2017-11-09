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
				texture2D.Create(Texture::TextureData(width, height, nullptr), format, wrap, filter);

				glFramebuffer.Create(texture2D);
			}

			void RenderTarget::Bind()
			{
				glFramebuffer.Bind();
			}

			void RenderTarget::Unbind()
			{
				glFramebuffer.Unbind();
			}
		}
	}
}