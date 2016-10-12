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
				}

				void GLConstentBuffer::Create(const void *data, const unsigned int size, const unsigned int bindingIndex)
				{
					glCreateBuffers(1, &buffer);
					glBindBuffer(GL_UNIFORM_BUFFER, buffer);
					glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

					GLvoid *bufferData = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
					memcpy(bufferData, data, size);
					glUnmapBuffer(GL_UNIFORM_BUFFER);

					glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, buffer, 0, size);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}

				void GLConstentBuffer::Update(const void *data, const unsigned int size)
				{
					glBindBuffer(GL_UNIFORM_BUFFER, buffer);
					glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}
			}
		}
	}
}