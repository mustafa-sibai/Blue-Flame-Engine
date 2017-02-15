#include "GLTextureCube.h"
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

				GLTextureCube::GLTextureCube()
				{
				}

				GLTextureCube::~GLTextureCube()
				{
				}

				void GLTextureCube::Create(vector<Texture::TextureData>& textureData, Texture::Format format, Texture::TextureWrap textureWrap, Texture::TextureFilter textureFilter)
				{
					GLCall(glGenTextures(1, &textureID));
					GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, textureID));

					for (GLuint i = 0; i < textureData.size(); i++)
						GLCall(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GetGLTextureFormat(format), textureData[i].width, textureData[i].height, 0, GetGLTextureFormat(format), GL_UNSIGNED_BYTE, textureData[i].buffer));

					GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GetGLTextureFilter(textureFilter)));
					GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GetGLTextureFilter(textureFilter)));
					GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GetGLTextureWrap(textureWrap)));
					GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GetGLTextureWrap(textureWrap)));
					GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GetGLTextureWrap(textureWrap)));
				}

				void GLTextureCube::Bind() const
				{
					GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, textureID));
				}

				void GLTextureCube::Unbind() const
				{
					GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, 0));
				}

				int GLTextureCube::GetGLTextureFormat(Texture::Format format) const
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

				int GLTextureCube::GetGLTextureWrap(Texture::TextureWrap textureWrap) const
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

				int GLTextureCube::GetGLTextureFilter(Texture::TextureFilter textureFilter) const
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