#include "GLVertexBuffer.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLVertexBuffer::GLVertexBuffer() :
					buffer(0)
				{
				}

				GLVertexBuffer::~GLVertexBuffer()
				{
				}

				void GLVertexBuffer::Create(const void* data, unsigned int size)
				{
					glGenBuffers(1, &buffer);
					glBindBuffer(GL_ARRAY_BUFFER, buffer);
					glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}

				void* GLVertexBuffer::Map() const
				{
					Bind();
					return glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
				}

				void GLVertexBuffer::Unmap() const
				{
					glUnmapBuffer(GL_ARRAY_BUFFER);
					Unbind();
				}

				void GLVertexBuffer::Bind() const
				{
					glBindBuffer(GL_ARRAY_BUFFER, buffer);
				}

				void GLVertexBuffer::Unbind() const
				{
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}
			}
		}
	}
}