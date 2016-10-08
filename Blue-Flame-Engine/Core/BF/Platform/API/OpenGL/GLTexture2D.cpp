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
					width(0), height(0), data(nullptr), textureID(0), internal_format(GL_RGBA), image_format(GL_RGBA), level(0), border(0)
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
						glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height, border, image_format, GL_UNSIGNED_BYTE, data);

						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
						glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

						//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
						//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
					}
				}

				void GLTexture2D::Bind()
				{
				}

				void GLTexture2D::Unbind()
				{
				}
			}
		}
	}
}