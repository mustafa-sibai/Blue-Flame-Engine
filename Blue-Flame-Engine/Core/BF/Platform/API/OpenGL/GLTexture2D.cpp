#include "GLTexture2D.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Math/Math.h"
#include "BF/Platform/API/OpenGL/GLError.h"

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

				GLTexture2D::GLTexture2D() :
					textureID(0), AFLevel(0.0f)
				{
				}

				GLTexture2D::~GLTexture2D()
				{
				}

				void GLTexture2D::Create(const Texture::TextureData& textureData, Texture::Format format, Texture::Wrap wrap, Texture::Filter filter)
				{
					GLCall(glGenTextures(1, &textureID));
					GLCall(glBindTexture(GL_TEXTURE_2D, textureID));

					if (format == Texture::Format::R8)
						GLCall(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

					GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GetGLTextureInternalFormat(format), textureData.width, textureData.height, 0, GetGLTextureFormat(format), GL_UNSIGNED_BYTE, textureData.buffer));

					GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GetGLTextureWrap(wrap)));
					GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GetGLTextureWrap(wrap)));

					//TODO: We should not check for max AF vaule everytime we create a new texture. This should be set in some kind of static settings class that should be run once after context creation.
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
					if (filter == Texture::Filter::AnisotropicX2 || filter == Texture::Filter::AnisotropicX4 ||
						filter == Texture::Filter::AnisotropicX8 || filter == Texture::Filter::AnisotropicX16)
					{
						if (glewIsSupported("GL_EXT_texture_filter_anisotropic") || GLEW_EXT_texture_filter_anisotropic)
							glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &AFLevel);
						else
						{
							filter = Texture::Filter::Trilinear;
							BF_LOG_WARNING("Anisotropic filtering is not supported on this hardware. The engine will fall back to Trilinear filtering.");
						}
					}
#endif

					switch (filter)
					{
						case Texture::Filter::Point:
						{
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
							break;
						}
						case Texture::Filter::Bilinear:
						{
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
							break;
						}
						case Texture::Filter::Trilinear:
						{
							GLCall(glGenerateMipmap(GL_TEXTURE_2D));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
							break;
						}
						case Texture::Filter::AnisotropicX2:
						{
							GLCall(glGenerateMipmap(GL_TEXTURE_2D));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
							GLCall(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, Math::Min(2.0f, AFLevel)));
#endif
							break;
						}
						case Texture::Filter::AnisotropicX4:
						{
							GLCall(glGenerateMipmap(GL_TEXTURE_2D));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
							GLCall(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, Math::Min(4.0f, AFLevel)));
#endif
							break;
						}
						case Texture::Filter::AnisotropicX8:
						{
							GLCall(glGenerateMipmap(GL_TEXTURE_2D));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
							GLCall(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, Math::Min(8.0f, AFLevel)));
#endif
							break;
						}
						case Texture::Filter::AnisotropicX16:
						{
							GLCall(glGenerateMipmap(GL_TEXTURE_2D));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
							GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
							GLCall(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, Math::Min(16.0f, AFLevel)));
							//GLCall(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -10.4f));
#endif
							break;
						}
						default:
							break;
					}

					GLCall(glBindTexture(GL_TEXTURE_2D, 0));
				}

				void GLTexture2D::Bind() const
				{
					GLCall(glBindTexture(GL_TEXTURE_2D, textureID));
				}

				void GLTexture2D::Bind(const GLShader& glShader, const string& samplerName, unsigned int index) const
				{
					GLCall(glActiveTexture(GL_TEXTURE0 + index));
					GLCall(glBindTexture(GL_TEXTURE_2D, textureID));
					GLCall(glUniform1i(glGetUniformLocation(glShader.GetProgramID(), samplerName.c_str()), index));
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

				int GLTexture2D::GetGLTextureInternalFormat(Texture::Format format) const
				{
					switch (format)
					{
						case Texture::Format::R8: return GL_R8;
						case Texture::Format::R8G8: return GL_RG8;
						case Texture::Format::R8G8B8: return GL_RGB8;
						case Texture::Format::R8G8B8A8: return GL_RGBA8;
						default: return GL_RGBA8;
					}
				}

				int GLTexture2D::GetGLTextureWrap(Texture::Wrap wrap) const
				{
					switch (wrap)
					{
						case Texture::Wrap::Repeat: return GL_REPEAT;
						case Texture::Wrap::MirroredReapeat: return GL_MIRRORED_REPEAT;
						case Texture::Wrap::ClampToEdge: return GL_CLAMP_TO_EDGE;

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
					case Texture::Wrap::ClampToBorder: return GL_CLAMP_TO_BORDER;
#endif
						default: return GL_REPEAT;
					}
				}
			}
		}
	}
}