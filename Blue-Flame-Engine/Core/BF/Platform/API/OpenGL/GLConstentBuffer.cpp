#include "GLConstentBuffer.h"
#include "GLError.h"

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
					GLCall(glDeleteBuffers(1, &buffer));
				}

				void GLConstentBuffer::Create(unsigned int size, unsigned int bindingIndex)
				{
					GLCall(glGenBuffers(1, &buffer));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, buffer));
					GLCall(glBufferData(GL_UNIFORM_BUFFER, size, 0, GL_DYNAMIC_DRAW));

					GLCall(glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, buffer, 0, size));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
				}

				void GLConstentBuffer::Update(const void* data, unsigned int size)
				{
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, buffer));
					GLCall(glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
				}
			}
		}
	}
}