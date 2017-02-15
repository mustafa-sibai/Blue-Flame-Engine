#include "GLTexture2D.h"
#include "BF/Graphics/API/Texture2D.h"
#include "GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace std;
				using namespace BF::Graphics::API;

				GLTexture2D::GLTexture2D(const GLShader& glshader) :
					glshader(glshader), textureID(0)
				{
				}

				GLTexture2D::~GLTexture2D()
				{
				}

				void GLTexture2D::Create(const Texture::TextureData& textureData, Texture::Format format, Texture::TextureWrap textureWrap, Texture::TextureFilter textureFilter)
				{
					GLCall(glGenTextures(1, &textureID));
					GLCall(glBindTexture(GL_TEXTURE_2D, textureID));

					if (format == Texture::Format::R8)
						GLCall(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

					GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GetGLTextureFormat(format), textureData.width, textureData.height, 0, GetGLTextureFormat(format), GL_UNSIGNED_BYTE, textureData.buffer));

					GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GetGLTextureWrap(textureWrap)));
					GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GetGLTextureWrap(textureWrap)));

					//TODO: Control both min and mag filter like d3d11
					GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GetGLTextureFilter(textureFilter)));
					GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GetGLTextureFilter(textureFilter)));

					//TODO: Add mip maps.
					//TODO: Add a way to disable and enable mip maps

					GLCall(glBindTexture(GL_TEXTURE_2D, 0));
				}

				void GLTexture2D::Bind() const
				{
					GLCall(glBindTexture(GL_TEXTURE_2D, textureID));
				}

				void GLTexture2D::Bind(const string& samplerName, unsigned int index) const
				{
					GLCall(glActiveTexture(GL_TEXTURE0 + index));
					GLCall(glBindTexture(GL_TEXTURE_2D, textureID));
					GLCall(glUniform1i(glGetUniformLocation(glshader.GetProgramID(), samplerName.c_str()), index));
				}

				void GLTexture2D::Unbind() const
				{
					GLCall(glBindTexture(GL_TEXTURE_2D, 0));
				}

				void GLTexture2D::Unbind(const string& samplerName, unsigned int index) const
				{
					GLCall(glActiveTexture(GL_TEXTURE0 + index));
					GLCall(glBindTexture(GL_TEXTURE_2D, 0));
				}

				int GLTexture2D::GetGLTextureFormat(Texture::Format format) const
				{
					switch (format)
					{
						case Texture::Format::R8: return GL_RED;
						case Texture::Format::R8G8: return GL_RG;
						case Texture::Format::R8G8B8: return GL_RGB;
						case Texture::Format::R8G8B8A8: return GL_RGBA;
						default: return GL_RGBA;
					}
				}

				int GLTexture2D::GetGLTextureWrap(Texture::TextureWrap textureWrap) const
				{
					switch (textureWrap)
					{
						case Texture::TextureWrap::Repeat: return GL_REPEAT;
						case Texture::TextureWrap::MirroredReapeat: return GL_MIRRORED_REPEAT;
						case Texture::TextureWrap::ClampToEdge: return GL_CLAMP_TO_EDGE;

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
						case Texture::TextureWrap::ClampToBorder: return GL_CLAMP_TO_BORDER;
#endif
						default: return GL_REPEAT;
					}
				}

				int GLTexture2D::GetGLTextureFilter(Texture::TextureFilter textureFilter) const
				{
					switch (textureFilter)
					{
						case Texture::TextureFilter::Neatest: return GL_NEAREST;
						case Texture::TextureFilter::Linear: return GL_LINEAR;
						default: return GL_NEAREST;
					}
				}
			}
		}
	}
}