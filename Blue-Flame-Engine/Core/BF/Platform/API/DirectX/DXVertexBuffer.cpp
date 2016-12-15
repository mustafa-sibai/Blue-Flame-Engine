#include "DXVertexBuffer.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				using namespace BF::Graphics::API;

				DXVertexBuffer::DXVertexBuffer(const DXShader& dxShader) :
					dxShader(dxShader), buffer(nullptr), inputLayout(nullptr), hr(0), offset(0), stride(0)
				{
				}

				DXVertexBuffer::~DXVertexBuffer()
				{
				}

				void DXVertexBuffer::Create(const void* data, unsigned int size)
				{
					D3D11_BUFFER_DESC bufferDesc;
					ZeroMemory(&bufferDesc, sizeof(bufferDesc));

					bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
					bufferDesc.ByteWidth = size;
					bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
					bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

					hr = Engine::GetContext().GetDXContext().GetDevice()->CreateBuffer(&bufferDesc, 0, &buffer);

					if (FAILED(hr))
						std::cout << "Could not create a vertex buffer." << std::endl;

					if (data != nullptr)
					{
						memcpy(Map(), data, size);
						Unmap();
					}
				}

				void DXVertexBuffer::SetLayout(const VertexBufferLayout& vertexBufferLayout)
				{
					D3D11_INPUT_ELEMENT_DESC* inputElementDesc = new D3D11_INPUT_ELEMENT_DESC[vertexBufferLayout.GetBufferElement().size()];

					for (size_t i = 0; i < vertexBufferLayout.GetBufferElement().size(); i++)
					{
						inputElementDesc[i].SemanticName = vertexBufferLayout.GetBufferElement()[i].name.c_str();
						inputElementDesc[i].SemanticIndex = 0;
						inputElementDesc[i].Format = GetDXDataType(vertexBufferLayout.GetBufferElement()[i].dataType);
						inputElementDesc[i].InputSlot = 0;
						inputElementDesc[i].AlignedByteOffset = vertexBufferLayout.GetBufferElement()[i].offset;
						inputElementDesc[i].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
						inputElementDesc[i].InstanceDataStepRate = 0;
					}

					hr = Engine::GetContext().GetDXContext().GetDevice()->CreateInputLayout(inputElementDesc, (unsigned int)vertexBufferLayout.GetBufferElement().size(), dxShader.GetVSData(), dxShader.GetVSsize(), &inputLayout);
					if (FAILED(hr))
						std::cout << "Could not create vertex buffer input layout." << std::endl;
					
					offset = vertexBufferLayout.GetBufferElement()[0].offset;
					stride = vertexBufferLayout.GetBufferElement()[0].stride;

					delete[] inputElementDesc;
				}

				void* DXVertexBuffer::Map() const
				{
					D3D11_MAPPED_SUBRESOURCE mappedSubResource;
					ZeroMemory(&mappedSubResource, sizeof(mappedSubResource));

					if (FAILED(Engine::GetContext().GetDXContext().GetContext()->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedSubResource)))
						std::cout << "Could not map vertex buffer." << std::endl;

					return mappedSubResource.pData;
				}

				void DXVertexBuffer::Unmap() const
				{
					Engine::GetContext().GetDXContext().GetContext()->Unmap(buffer, 0);
				}

				void DXVertexBuffer::Bind() const
				{
					Engine::GetContext().GetDXContext().GetContext()->IASetInputLayout(inputLayout);
					Engine::GetContext().GetDXContext().GetContext()->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
				}

				DXGI_FORMAT DXVertexBuffer::GetDXDataType(VertexBufferLayout::DataType dataType)
				{
					switch (dataType)
					{
						case VertexBufferLayout::DataType::Float:
						{
							return DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;
							break;
						}
						case VertexBufferLayout::DataType::Float2:
						{
							return DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;
							break;
						}
						case VertexBufferLayout::DataType::Float3:
						{
							return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT;
							break;
						}
						case VertexBufferLayout::DataType::Float4:
						{
							return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;
							break;
						}
						default:
							break;
					}

					return DXGI_FORMAT();
				}
			}
		}
	}
}