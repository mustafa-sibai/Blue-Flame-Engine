#include "GLConstantBuffer.h"
#include "BF/Platform/API/OpenGL/GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				GLConstantBuffer::GLConstantBuffer() :
					buffer(0), bindingIndex(0)
				{
				}

				GLConstantBuffer::~GLConstantBuffer()
				{
					GLCall(glDeleteBuffers(1, &buffer));
				}

				void GLConstantBuffer::Create(unsigned int bindingIndex, unsigned int size, const void* data)
				{
					this->bindingIndex = bindingIndex;

					GLCall(glCreateBuffers(1, &buffer));
					GLCall(glBindBufferBase(GL_UNIFORM_BUFFER, bindingIndex, buffer));
					GLCall(glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_DYNAMIC_DRAW));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
				}

				void GLConstantBuffer::Update(unsigned int offset, unsigned int size, const void* data)
				{
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, buffer));
					GLCall(glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data));
					GLCall(glBindBuffer(GL_UNIFORM_BUFFER, 0));
				}
			}
		}
	}
}