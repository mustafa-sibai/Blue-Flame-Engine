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
					buffer(0), VAO(0)
				{
				}

				GLVertexBuffer::~GLVertexBuffer()
				{
				}

				void GLVertexBuffer::Create(const void* data, const unsigned int size)
				{
					glGenVertexArrays(1, &VAO);

					glGenBuffers(1, &buffer);
					glBindBuffer(GL_ARRAY_BUFFER, buffer);
					glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}

				void GLVertexBuffer::SetLayout(Graphics::API::VertexBufferLayout *vertexBufferLayout)
				{
					glBindVertexArray(VAO);
					glBindBuffer(GL_ARRAY_BUFFER, buffer);
					for (size_t i = 0; i < vertexBufferLayout->GetBufferElement().size(); i++)
					{
						glEnableVertexAttribArray(vertexBufferLayout->GetBufferElement()[i].index);
						glVertexAttribPointer(vertexBufferLayout->GetBufferElement()[i].index, GetComponentCount(vertexBufferLayout->GetBufferElement()[i].dataType),
							GetGLDataType(vertexBufferLayout->GetBufferElement()[i].dataType), GL_FALSE, vertexBufferLayout->GetBufferElement()[i].stride, (char*)vertexBufferLayout->GetBufferElement()[i].offset);
					}
					glBindBuffer(GL_ARRAY_BUFFER, 0);
					glBindVertexArray(0);
				}

				const void GLVertexBuffer::Bind() const
				{
					glBindVertexArray(VAO);
				}

				const void GLVertexBuffer::Unbind() const
				{
					glBindVertexArray(0);
				}

				GLenum GLVertexBuffer::GetGLDataType(Graphics::API::DataType dataType)
				{
					switch (dataType)
					{
						case Graphics::API::DataType::Byte:
						{
							return GL_BYTE;
							break;
						}
						case Graphics::API::DataType::Short:
						{
							return GL_SHORT;
							break;
						}
						case Graphics::API::DataType::Int:
						{
							return GL_INT;
							break;
						}
						case Graphics::API::DataType::Float:
						{
							return GL_FLOAT;
							break;
						}
						case Graphics::API::DataType::Float2:
						{
							return GL_FLOAT;
							break;
						}
						case Graphics::API::DataType::Float3:
						{
							return GL_FLOAT;
							break;
						}
						case Graphics::API::DataType::Float4:
						{
							return GL_FLOAT;
							break;
						}
						case Graphics::API::DataType::Double:
						{
							return GL_FLOAT;
							break;
						}
						default:
							return -1;
							break;
					}
				}

				unsigned int GLVertexBuffer::GetComponentCount(Graphics::API::DataType dataType)
				{
					switch (dataType)
					{
						case Graphics::API::DataType::Byte:
						{
							return 1;
							break;
						}
						case Graphics::API::DataType::Short:
						{
							return 1;
							break;
						}
						case Graphics::API::DataType::Int:
						{
							return 1;
							break;
						}
						case Graphics::API::DataType::Float:
						{
							return 1;
							break;
						}
						case Graphics::API::DataType::Float2:
						{
							return 2;
							break;
						}
						case Graphics::API::DataType::Float3:
						{
							return 3;
							break;
						}
						case Graphics::API::DataType::Float4:
						{
							return 4;
							break;
						}
						case Graphics::API::DataType::Double:
						{
							return 1;
							break;
						}
						default:
							return -1;
							break;
					}
				}
			}
		}
	}
}