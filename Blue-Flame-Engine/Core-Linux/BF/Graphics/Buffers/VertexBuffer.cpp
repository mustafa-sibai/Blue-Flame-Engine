#if 0
#include "VertexBuffer.h"

namespace BFE
{
	namespace Graphics
	{
		namespace Buffers
		{
			VertexBuffer::VertexBuffer(Renderer &renderer) :
				renderer(renderer), dx11Buffer(nullptr), glBuffer(0)
			{
			}

			VertexBuffer::~VertexBuffer()
			{
			}

			void VertexBuffer::Create(void* data, const unsigned int size)
			{
				//Create buffer
				if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				{
					D3D11_BUFFER_DESC bufferDesc;
					ZeroMemory(&bufferDesc, sizeof(bufferDesc));
					bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
					bufferDesc.ByteWidth = size;
					bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
					bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

					hr = renderer.GetDx11Renderer().GetDevice().CreateBuffer(&bufferDesc, 0, &dx11Buffer);
					if (FAILED(hr))
						std::cout << "Could not create a vertex buffer." << std::endl;

					//Map buffer
					D3D11_MAPPED_SUBRESOURCE mappedSubResource;
					hr = renderer.GetDx11Renderer().GetContext().Map(dx11Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedSubResource);
					if (FAILED(hr))
						std::cout << "Could not map vertex buffer." << std::endl;
					memcpy(mappedSubResource.pData, data, size);
					renderer.GetDx11Renderer().GetContext().Unmap(dx11Buffer, 0);
				}
				else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				{
					glCreateBuffers(1, &glBuffer);
					glBindBuffer(GL_ARRAY_BUFFER, glBuffer);
					glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}
			}

			void VertexBuffer::Bind()
			{
				if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				{
					glBindBuffer(GL_ARRAY_BUFFER, glBuffer);
				}
			}

			void VertexBuffer::Unbind()
			{
				if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				{
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}
			}
		}
	}
}
#endif