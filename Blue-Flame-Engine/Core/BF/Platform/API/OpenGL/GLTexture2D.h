#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
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
					private:
						const GLShader& glshader;
						GLuint textureID;

					public:
						GLTexture2D(const GLShader& glshader);
						~GLTexture2D();

						void Create(unsigned int width, unsigned int height, Graphics::API::Texture::Format format, const uint8_t* data, Graphics::API::Texture::TextureWrap textureWrap, Graphics::API::Texture::TextureFilter textureFilter);
						void Bind() const;
						void Bind(const std::string& samplerName, unsigned int index) const;
						void Unbind() const;
						void Unbind(const std::string& samplerName, unsigned int index) const;

					private:
						int GetGLTextureFormat(Graphics::API::Texture::Format format) const;
						int GetGLTextureWrap(Graphics::API::Texture::TextureWrap textureWrap) const;
						int GetGLTextureFilter(Graphics::API::Texture::TextureFilter textureFilter) const;
				};
			}
		}
	}
}