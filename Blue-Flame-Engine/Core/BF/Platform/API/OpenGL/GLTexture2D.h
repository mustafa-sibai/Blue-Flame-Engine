#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEB || defined (BF_PLATFORM_ANDROID)
	#include <GLES3/gl3.h>
	#include <GLES3/gl2ext.h>
#endif

#include "GLShader.h"
#include "BF/Graphics/API/Texture.h"
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
						int GetGLTextureWrap(Graphics::API::Texture::Wrap wrap) const;
				};
			}
		}
	}
}