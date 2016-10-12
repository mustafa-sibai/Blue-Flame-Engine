#include "GLTexture2D.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLTexture2D::GLTexture2D() :
					textureID(0), width(0), height(0), data(nullptr)
				{
				}

				GLTexture2D::~GLTexture2D()
				{
				}

				void GLTexture2D::Load(const char *fileName)
				{
					data = BF::IO::ImageReader::ReadImage(fileName, &width, &height);
					
					if (data != nullptr)
					{
						glGenTextures(1, &textureID);
						glBindTexture(GL_TEXTURE_2D, textureID);
						glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
						glBindTexture(GL_TEXTURE_2D, 0);
					}
				}

				const void GLTexture2D::Bind() const
				{
					glBindTexture(GL_TEXTURE_2D, textureID);
				}

				const void GLTexture2D::Unbind() const
				{
					glBindTexture(GL_TEXTURE_2D, 0);
				}
			}
		}
	}
}