#include "GLConstentBuffer.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLConstentBuffer::GLConstentBuffer(GLShader* glShader) :
					glShader(glShader), buffer(0)
				{
				}

				GLConstentBuffer::~GLConstentBuffer()
				{
				}

				void GLConstentBuffer::Create(unsigned int size, unsigned int bindingIndex)
				{
					//GLuint shader_data = glGetUniformBlockIndex(glShader->GetProgramID(), "shader_data");
					//glUniformBlockBinding(glShader->GetProgramID(), shader_data, 0);

					glCreateBuffers(1, &buffer);
					glBindBuffer(GL_UNIFORM_BUFFER, buffer);
					glBufferData(GL_UNIFORM_BUFFER, size, 0, GL_DYNAMIC_DRAW);

					glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, buffer, 0, size);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}

				void GLConstentBuffer::Update(const void* data, const unsigned int size)
				{
					glBindBuffer(GL_UNIFORM_BUFFER, buffer);
					glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}
			}
		}
	}
}