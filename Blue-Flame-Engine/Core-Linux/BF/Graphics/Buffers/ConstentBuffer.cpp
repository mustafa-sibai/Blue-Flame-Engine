#if 0
#include "ConstentBuffer.h"

namespace BFE
{
	namespace Graphics
	{
		namespace Buffers
		{
			ConstentBuffer::ConstentBuffer(Renderer &renderer) :
				renderer(renderer), dx11Buffer(nullptr), glBuffer(0)
			{
			}

			ConstentBuffer::~ConstentBuffer()
			{
			}

			void ConstentBuffer::Create(Shader &shader, void *data, unsigned int size, const unsigned int bindingIndex)
			{
				if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				{
					//Align the buffer to be a multiple of 16
					int remainder = size % 16;
					if (remainder != 0)
						size += 16 - remainder;

					D3D11_BUFFER_DESC bufferDesc;
					ZeroMemory(&bufferDesc, sizeof(bufferDesc));

					bufferDesc.Usage = D3D11_USAGE_DEFAULT;
					bufferDesc.ByteWidth = size;
					bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

					hr = renderer.GetDx11Renderer().GetDevice().CreateBuffer(&bufferDesc, NULL, &dx11Buffer);
					if (FAILED(hr))
						std::cout << "Could not create a constent buffer." << std::endl;

					renderer.GetDx11Renderer().GetContext().VSSetConstantBuffers(0, 1, &dx11Buffer);
				}
				else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				{
					glCreateBuffers(1, &glBuffer);
					glBindBuffer(GL_UNIFORM_BUFFER, glBuffer);
					glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

					GLvoid *bufferData = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
					memcpy(bufferData, data, size);
					glUnmapBuffer(GL_UNIFORM_BUFFER);

					glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, glBuffer, 0, size);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}
			}

			void ConstentBuffer::Update(void *data, const unsigned int size)
			{
				if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				{
					renderer.GetDx11Renderer().GetContext().UpdateSubresource(dx11Buffer, 0, 0, data, 0, 0);
				}
				else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				{
					glBindBuffer(GL_UNIFORM_BUFFER, glBuffer);
					glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
					glBindBuffer(GL_UNIFORM_BUFFER, 0);
				}
			}
		}
	}
}
#endif