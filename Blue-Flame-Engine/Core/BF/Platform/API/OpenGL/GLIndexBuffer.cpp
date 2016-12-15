#include "GLIndexBuffer.h"

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
					glDeleteBuffers(1, &buffer);
				}

				void GLIndexBuffer::Create(const unsigned int* indices, unsigned int count)
				{
					this->count = count;

					glGenBuffers(1, &buffer);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
				}

				void GLIndexBuffer::Bind() const
				{
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
				}

				void GLIndexBuffer::Unbind() const
				{
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
				}
			}
		}
	}
}