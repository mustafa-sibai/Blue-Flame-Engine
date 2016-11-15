#include "GLTexture2D.h"
#include "BF/Graphics/API/Texture2D.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLTexture2D::GLTexture2D(GLShader* glshader, Graphics::API::Texture2D* texture2D) :
					glshader(glshader), texture2D(texture2D), textureID(0)
				{
				}

				GLTexture2D::~GLTexture2D()
				{
				}

				void GLTexture2D::Create()
				{
					glGenTextures(1, &textureID);
					glBindTexture(GL_TEXTURE_2D, textureID);
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture2D->GetWidth(), texture2D->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture2D->GetData());

					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
					glBindTexture(GL_TEXTURE_2D, 0);
				}

				void GLTexture2D::Bind() const
				{
					glBindTexture(GL_TEXTURE_2D, textureID);
				}

				void GLTexture2D::Bind(const char* samplerName, unsigned int index) const
				{
					glActiveTexture(GL_TEXTURE0 + index);
					glBindTexture(GL_TEXTURE_2D, textureID);
					glUniform1i(glGetUniformLocation(glshader->GetProgramID(), samplerName), index);
				}

				void GLTexture2D::Unbind() const
				{
					glBindTexture(GL_TEXTURE_2D, 0);
				}
			}
		}
	}
}