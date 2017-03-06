#include "RenderTarget.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			RenderTarget::RenderTarget(const Shader& shader) : 
				texture2D(shader)
			{
			}

			RenderTarget::~RenderTarget()
			{
			}

			void RenderTarget::Create(unsigned int width, unsigned int height, Graphics::API::Texture::Format format, Graphics::API::Texture::Wrap wrap, Graphics::API::Texture::Filter filter)
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