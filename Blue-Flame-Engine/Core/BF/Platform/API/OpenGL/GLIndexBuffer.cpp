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
				using namespace BF::Graphics::API;

				GLIndexBuffer::GLIndexBuffer() :
					buffer(0), count(0)
				{
				}

				GLIndexBuffer::~GLIndexBuffer()
				{
					GLCall(glDeleteBuffers(1, &buffer));
				}

				void GLIndexBuffer::Create()
				{
					GLCall(glGenBuffers(1, &buffer));
				}

				void GLIndexBuffer::SetBuffer(const unsigned int* indices, unsigned int count, BufferMode mode)
				{
					this->count = count;

					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer));
					GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GetGLBufferMode(mode)));
					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
				}

				void* GLIndexBuffer::Map() const
				{
					GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer));

#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX)
					GLCall(return glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY));
#elif defined(BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
					GLCall(return glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT));
#endif
				}

				void GLIndexBuffer::Unmap() const
				{
					GLCall(glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER));
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

				GLenum GLIndexBuffer::GetGLBufferMode(BufferMode mode)
				{
					switch (mode)
					{
					case BufferMode::StaticDraw:
					{
						return GL_STATIC_DRAW;
						break;
					}
					case BufferMode::DynamicDraw:
					{
						return GL_DYNAMIC_DRAW;
						break;
					}
					default:
					{
						return GL_STATIC_DRAW;
						break;
					}
					}
				}
			}
		}
	}
}