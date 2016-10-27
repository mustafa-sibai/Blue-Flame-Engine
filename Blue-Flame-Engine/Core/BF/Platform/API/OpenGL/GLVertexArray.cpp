#include "GLVertexArray.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace BF::Graphics::API;

				GLVertexArray::GLVertexArray() :
					VAO(0)
				{
					glVertexBuffers = new std::vector<GLVertexBuffer*>();
				}

				GLVertexArray::~GLVertexArray()
				{
				}

				void GLVertexArray::Create()
				{
					glGenVertexArrays(1, &VAO);
					glBindVertexArray(0);
				}

				void GLVertexArray::Push(GLVertexBuffer* glVertexBuffer)
				{
					glVertexBuffers->push_back(glVertexBuffer);
				}

				void GLVertexArray::SetVertexBufferLayout(VertexBufferLayout* vertexBufferLayout)
				{
					glBindVertexArray(VAO);

					for (size_t i = 0; i < glVertexBuffers->size(); i++)
						glVertexBuffers[0][i]->Bind();

					for (size_t i = 0; i < vertexBufferLayout->GetBufferElement().size(); i++)
					{
						glEnableVertexAttribArray(vertexBufferLayout->GetBufferElement()[i].index);
						glVertexAttribPointer(vertexBufferLayout->GetBufferElement()[i].index, GetComponentCount(vertexBufferLayout->GetBufferElement()[i].dataType),
							GetGLDataType(vertexBufferLayout->GetBufferElement()[i].dataType), GL_FALSE, vertexBufferLayout->GetBufferElement()[i].stride, (GLvoid*)vertexBufferLayout->GetBufferElement()[i].offset);
					}

					for (size_t i = 0; i < glVertexBuffers->size(); i++)
						glVertexBuffers[0][i]->Unbind();

					glBindVertexArray(0);
				}

				void GLVertexArray::Bind() const
				{
					glBindVertexArray(VAO);
				}

				void GLVertexArray::Unbind() const
				{
					glBindVertexArray(0);
				}

				GLenum GLVertexArray::GetGLDataType(DataType dataType)
				{
					switch (dataType)
					{
					case DataType::Byte:
					{
						return GL_BYTE;
						break;
					}
					case DataType::Short:
					{
						return GL_SHORT;
						break;
					}
					case DataType::Int:
					{
						return GL_INT;
						break;
					}
					case DataType::Float:
					{
						return GL_FLOAT;
						break;
					}
					case DataType::Float2:
					{
						return GL_FLOAT;
						break;
					}
					case DataType::Float3:
					{
						return GL_FLOAT;
						break;
					}
					case DataType::Float4:
					{
						return GL_FLOAT;
						break;
					}
					case DataType::Double:
					{
						return GL_FLOAT;
						break;
					}
					default:
						return -1;
						break;
					}
				}

				unsigned int GLVertexArray::GetComponentCount(DataType dataType)
				{
					switch (dataType)
					{
					case DataType::Byte:
					{
						return 1;
						break;
					}
					case DataType::Short:
					{
						return 1;
						break;
					}
					case DataType::Int:
					{
						return 1;
						break;
					}
					case DataType::Float:
					{
						return 1;
						break;
					}
					case DataType::Float2:
					{
						return 2;
						break;
					}
					case DataType::Float3:
					{
						return 3;
						break;
					}
					case DataType::Float4:
					{
						return 4;
						break;
					}
					case DataType::Double:
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