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

				HRESULT hr = renderer.GetDx11Renderer().GetDevice().CreateBuffer(&bufferDesc, 0, &dx11Buffer);

				if (FAILED(hr))
					std::cout << hr << std::endl;

				//Map buffer
				D3D11_MAPPED_SUBRESOURCE mappedSubResource;
				renderer.GetDx11Renderer().GetContext().Map(dx11Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedSubResource);
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

		void Buffer::CreateConstentBuffer(Shader &shader, void *data, const unsigned int size, const char* bufferNameInShader, const unsigned int bindingIndex)
		{
			if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
			{
				D3D11_BUFFER_DESC bufferDesc;
				ZeroMemory(&bufferDesc, sizeof(bufferDesc));
				bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
				bufferDesc.ByteWidth = size;
				bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
				bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

				// Fill in the subresource data.
				D3D11_SUBRESOURCE_DATA bufferData;
				bufferData.pSysMem = data;
				bufferData.SysMemPitch = 0;
				bufferData.SysMemSlicePitch = 0;
				
				HRESULT hr = renderer.GetDx11Renderer().GetDevice().CreateBuffer(&bufferDesc, &bufferData, &dx11Buffer);

				if (FAILED(hr))
					std::cout << hr << std::endl;

				renderer.GetDx11Renderer().GetContext().VSSetConstantBuffers(bindingIndex, 1, &dx11Buffer);		
			}
			else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
			{
				glCreateBuffers(1, &glBuffer);
				glBindBuffer(GL_UNIFORM_BUFFER, glBuffer);
				glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

				GLvoid *bufferData = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
				memcpy(bufferData, data, size);
				glUnmapBuffer(GL_UNIFORM_BUFFER);

				unsigned int block_index = glGetUniformBlockIndex(shader.GetGLShader().GetProgramID(), bufferNameInShader);
				glBindBufferBase(GL_UNIFORM_BUFFER, bindingIndex, glBuffer);
				glUniformBlockBinding(shader.GetGLShader().GetProgramID(), block_index, bindingIndex);

				glBindBuffer(GL_UNIFORM_BUFFER, 0);
			}
		}

		void Buffer::UpdateConstentBuffer(void * data)
		{
			if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
			{
				renderer.GetDx11Renderer().GetContext().UpdateSubresource(dx11Buffer, 0, 0, data, 0, 0);
			}
		}
	}
}