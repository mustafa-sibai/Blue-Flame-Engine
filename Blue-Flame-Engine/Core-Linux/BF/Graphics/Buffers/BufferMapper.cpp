#if 0
#include "BufferMapper.h"

namespace BFE
{
	namespace Graphics
	{
		namespace Buffers
		{
			BufferMapper::BufferMapper(Renderer &renderer) :
				renderer(renderer)
			{
			}

			BufferMapper::~BufferMapper()
			{
			}

			void BufferMapper::Create(Shader *shader, ShaderLayout *shaderLayout, const unsigned short count)
			{
				this->shader = shader;
				this->shaderLayout = shaderLayout;
				this->count = count;

				if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				{
					D3D11_INPUT_ELEMENT_DESC* inputElementDesc = new D3D11_INPUT_ELEMENT_DESC[count];

					for (unsigned short i = 0; i < count; i++)
					{
						inputElementDesc[i].SemanticName = shaderLayout[i].name;
						inputElementDesc[i].SemanticIndex = 0;
						inputElementDesc[i].Format = GetDX11DataType(shaderLayout[i].dataType, shaderLayout[i].componentCount);
						inputElementDesc[i].InputSlot = 0;
						inputElementDesc[i].AlignedByteOffset = shaderLayout[i].offset;
						inputElementDesc[i].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
						inputElementDesc[i].InstanceDataStepRate = 0;
					}

					renderer.GetDx11Renderer().GetDevice().CreateInputLayout(inputElementDesc,
						count,
						shader->GetDX11Shader().GetVSData(),
						shader->GetDX11Shader().GetVSsize(),
						&inputLayout);

					delete[] inputElementDesc;
				}
			}

			void BufferMapper::Map(VertexBuffer *vertexBuffer)
			{
				if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
				{
					renderer.GetDx11Renderer().GetContext().IASetInputLayout(inputLayout);
					renderer.GetDx11Renderer().GetContext().IASetVertexBuffers(0,
						1,
						vertexBuffer->GetConstDX11Buffer(),
						&shaderLayout[0].stride,
						&shaderLayout[0].offset);
				}
				else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
				{
					for (unsigned short i = 0; i < count; i++)
					{
						glEnableVertexAttribArray(shaderLayout[i].index);
						glVertexAttribPointer(shaderLayout[i].index,
							shaderLayout[i].componentCount,
							GetGLDataType(shaderLayout[i].dataType),
							GL_FALSE,
							shaderLayout[i].stride,
							(char*)shaderLayout[i].offset);
					}
				}
			}

			GLenum BufferMapper::GetGLDataType(DataType dataType)
			{
				switch (dataType)
				{
				case DataType::BYTE:
				{
					return GL_BYTE;
					break;
				}
				case DataType::SHORT:
				{
					return GL_SHORT;
					break;
				}
				case DataType::INT:
				{
					return GL_INT;
					break;
				}
				case DataType::FLOAT:
				{
					return GL_FLOAT;
					break;
				}
				case DataType::DOUBLE:
				{
					return GL_DOUBLE;
					break;
				}
				default:
					return -1;
					break;
				}
			}

			DXGI_FORMAT BufferMapper::GetDX11DataType(DataType dataType, unsigned int componentCount)
			{
				switch (dataType)
				{
				case DataType::BYTE:
				{
					break;
				}
				case DataType::SHORT:
				{
					break;
				}
				case DataType::INT:
				{
					break;
				}
				case DataType::FLOAT:
				{
					if (componentCount == 1)
						return DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;
					else if (componentCount == 2)
						return DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;
					else if (componentCount == 3)
						return DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT;
					else if (componentCount == 4)
						return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;
					break;
				}
				case DataType::DOUBLE:
				{
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
#endif