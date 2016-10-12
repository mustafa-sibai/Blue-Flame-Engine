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
				}

				void GLIndexBuffer::Create(const unsigned int* const indices, const unsigned int count)
				{
					this->count = count;

					glGenBuffers(1, &buffer);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
				}

				const void GLIndexBuffer::Bind() const
				{
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
				}

				const void GLIndexBuffer::Unbind() const
				{
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
				}
			}
		}
	}
}