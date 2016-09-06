#include "Buffer.h"

namespace BFE
{
	namespace Graphics
	{
		Buffer::Buffer(Renderer &renderer) :
			renderer(renderer), dx11Buffer(nullptr), glBuffer(0)
		{
		}

		Buffer::~Buffer()
		{
		}

		void Buffer::CreateVertexBuffer(void* data, const unsigned int size)
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
			}
		}

		void Buffer::CreateConstentBuffer(Shader &shader, void *data, unsigned int size, const unsigned int bindingIndex)
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

		void Buffer::UpdateConstentBuffer(void *data, const unsigned int size)
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