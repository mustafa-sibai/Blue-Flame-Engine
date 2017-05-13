#pragma once
#include "GLShader.h"
#include "BF/Graphics/API/Texture.h"
#include "BF/Platform/API/OpenGL/GLCommon.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLTexture2D
				{
					friend class GLFramebuffer;

					private:
						const GLShader& glShader;
						GLuint textureID;
						float AFLevel;

					public:
						GLTexture2D(const GLShader& glShader);
						~GLTexture2D();

						void Create(const Graphics::API::Texture::TextureData& textureData, Graphics::API::Texture::Format format, Graphics::API::Texture::Wrap wrap, Graphics::API::Texture::Filter filter);
						void Bind() const;
						void Bind(const std::string& samplerName, unsigned int index) const;
						void Unbind() const;
						void Unbind(const std::string& samplerName, unsigned int index) const;

					private:
						int GetGLTextureFormat(Graphics::API::Texture::Format format) const;
						int GetGLTextureInternalFormat(Graphics::API::Texture::Format format) const;
						int GetGLTextureWrap(Graphics::API::Texture::Wrap wrap) const;
				};
			}
		}
	}
}