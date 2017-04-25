#include "GLIndexBuffer.h"
#include "BF/Platform/API/OpenGL/GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLIndexBuffer::GLIndexBuffer() :
					buffer(0), count(0)
				{
				}

				GLIndexBuffer::~GLIndexBuffer()
				{
					GLCall(glDeleteBuffers(1, &buffer));
				}

				void GLIndexBuffer::Create(const unsigned int* indices, unsigned int count)
				{
					this->count = count;

					GLCall(glGenBuffers(1, &buffer));
					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer));
					GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW));
					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
				}

				void GLIndexBuffer::Bind() const
				{
					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer));
				}

				void GLIndexBuffer::Unbind() const
				{
					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
				}
			}
		}
	}
}