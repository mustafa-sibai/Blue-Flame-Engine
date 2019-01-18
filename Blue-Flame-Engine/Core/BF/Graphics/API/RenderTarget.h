#pragma once
#include "BF/Graphics/API/Framebuffer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BFE_API RenderTarget
			{
				private:
					Framebuffer framebuffer;
					Texture2D texture2D;

				public:
					RenderTarget();
					~RenderTarget();

					void Create(unsigned int width, unsigned int height, Texture::Format format, Texture::Wrap wrap, Texture::Filter filter);

					void Bind() const;
					void Unbind() const;

					inline const Texture2D& GetTexture2D() const { return texture2D; }
			};
		}
	}
}