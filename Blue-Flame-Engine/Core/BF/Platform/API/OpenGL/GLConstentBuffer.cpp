#include "GLConstentBuffer.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLConstentBuffer::GLConstentBuffer() :
					buffer(0)
				{
				}

				GLConstentBuffer::~GLConstentBuffer()
				{
					glDeleteBuffers(1, &buffer);
				}

				void GLConstentBuffer::Create(unsigned int size, unsigned int bindingIndex)
				{
					glCreateBuffers(1, &buffer);
					glBindBuffer(GL_UNIFORM_BUFFER, buffer);
					glBufferData(GL_UNIFORM_BUFFER, size, 0, GL_DYNAMIC_DRAW);

					glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, buffer, 0, size);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}

				void GLConstentBuffer::Update(const void* data, unsigned int size)
				{
					glBindBuffer(GL_UNIFORM_BUFFER, buffer);
					glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}
			}
		}
	}
}