#include "GLVertexBuffer.h"
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

				GLVertexBuffer::GLVertexBuffer() :
					vbo(0), vao(0), vertexBufferLayout(nullptr)
				{
				}

				GLVertexBuffer::~GLVertexBuffer()
				{
					GLCall(glDeleteBuffers(1, &vbo));
					GLCall(glDeleteVertexArrays(1, &vao));
				}

				void GLVertexBuffer::Create(unsigned int size, const void* data)
				{
					this->size = size;

					GLCall(glGenVertexArrays(1, &vao));

					GLCall(glGenBuffers(1, &vbo));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
					GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
				}

				void GLVertexBuffer::SetLayout(const VertexBufferLayout* vertexBufferLayout)
				{
					this->vertexBufferLayout = vertexBufferLayout;

					GLCall(glBindVertexArray(vao));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));

					for (size_t i = 0; i < vertexBufferLayout->GetBufferElement().size(); i++)
					{
						GLCall(glVertexAttribPointer(vertexBufferLayout->GetBufferElement()[i].index, GetComponentCount(vertexBufferLayout->GetBufferElement()[i].dataType),
							GetGLDataType(vertexBufferLayout->GetBufferElement()[i].dataType), GL_FALSE, vertexBufferLayout->GetBufferElement()[i].stride, (GLvoid*)vertexBufferLayout->GetBufferElement()[i].offset));
					}

					GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
					GLCall(glBindVertexArray(0));
				}

				void* GLVertexBuffer::Map() const
				{
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
					GLCall(return glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
					GLCall(return glMapBufferRange(GL_ARRAY_BUFFER, 0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT));
#endif
				}

				void GLVertexBuffer::Unmap() const
				{
					GLCall(glUnmapBuffer(GL_ARRAY_BUFFER));
					GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
				}

				void GLVertexBuffer::Bind() const
				{
					GLCall(glBindVertexArray(vao));
					for (size_t i = 0; i < vertexBufferLayout->GetBufferElement().size(); i++)
						GLCall(glEnableVertexAttribArray(vertexBufferLayout->GetBufferElement()[i].index));
				}

				void GLVertexBuffer::Unbind() const
				{
					for (size_t i = 0; i < vertexBufferLayout->GetBufferElement().size(); i++)
						GLCall(glDisableVertexAttribArray(vertexBufferLayout->GetBufferElement()[i].index));
					GLCall(glBindVertexArray(0));
				}

				GLenum GLVertexBuffer::GetGLDataType(VertexBufferLayout::DataType dataType)
				{
					if (dataType == VertexBufferLayout::DataType::Float ||
						dataType == VertexBufferLayout::DataType::Float2 ||
						dataType == VertexBufferLayout::DataType::Float3 ||
						dataType == VertexBufferLayout::DataType::Float4)
						return GL_FLOAT;
					else if (dataType == VertexBufferLayout::DataType::Int)
						return GL_INT;
				}

				unsigned int GLVertexBuffer::GetComponentCount(VertexBufferLayout::DataType dataType)
				{
					switch (dataType)
					{
					case VertexBufferLayout::DataType::Int:
					{
						return 1;
						break;
					}
					case VertexBufferLayout::DataType::Float:
					{
						return 1;
						break;
					}
					case VertexBufferLayout::DataType::Float2:
					{
						return 2;
						break;
					}
					case VertexBufferLayout::DataType::Float3:
					{
						return 3;
						break;
					}
					case VertexBufferLayout::DataType::Float4:
					{
						return 4;
						break;
					}
					default:
						break;
					}
				}
			}
		}
	}
}