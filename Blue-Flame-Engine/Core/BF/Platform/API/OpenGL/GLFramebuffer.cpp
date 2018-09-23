#include "GLFramebuffer.h"
#include "BF/Engine.h"
#include "BF/Platform/API/OpenGL/GLError.h"
#include "BF/Graphics/API/Framebuffer.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace BF::Graphics::API;

				GLFramebuffer::GLFramebuffer()
				{
				}

				GLFramebuffer::~GLFramebuffer()
				{
					GLCall(glDeleteFramebuffers(1, &buffer));
				}

				void GLFramebuffer::Create(Texture2D& texture2D, FramebufferFormat format)
				{
					this->texture2D = &texture2D;

					GLCall(glGenFramebuffers(1, &buffer));
					GLCall(glBindFramebuffer(GL_FRAMEBUFFER, buffer));

					GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GetBufferFormat(format), GL_TEXTURE_2D, texture2D.glTexture2D.textureID, 0));
				
					if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
					{
						BF_LOG_ERROR("ERRRRRRROOOOOORRRRR !!!!", "");
					}

					if (format != FramebufferFormat::Color)
					{
						GLCall(glDrawBuffer(GL_NONE));
						GLCall(glReadBuffer(GL_NONE));
					}
					GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
				}

				void GLFramebuffer::Bind() const
				{
					GLCall(glBindFramebuffer(GL_FRAMEBUFFER, buffer));
					glViewport(0, 0, texture2D->textureData->width, texture2D->textureData->height);
				}

				void GLFramebuffer::Unbind() const
				{
					GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
					glViewport(0, 0, Engine::GetWindow().GetClientWidth(), Engine::GetWindow().GetClientHeight());
				}

				int GLFramebuffer::GetBufferFormat(FramebufferFormat format)
				{
					switch (format)
					{
						case FramebufferFormat::Color: return GL_COLOR_ATTACHMENT0;
						case FramebufferFormat::Depth: return GL_DEPTH_ATTACHMENT;
						case FramebufferFormat::Stencil: return GL_STENCIL_ATTACHMENT;
						default: return GL_COLOR_ATTACHMENT0;
					}
				}
			}
		}
	}
}