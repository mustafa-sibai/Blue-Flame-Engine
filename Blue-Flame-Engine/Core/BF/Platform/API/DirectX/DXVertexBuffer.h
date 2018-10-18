#pragma once
#include <d3d11.h>
#include "DXShader.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXVertexBuffer
				{
					private:
						ID3D11Buffer* buffer;
						ID3D11InputLayout* inputLayout;

						unsigned int offset, stride;

					public:
						DXVertexBuffer();
						~DXVertexBuffer();

						void Create(const void* data, unsigned int size);
						void SetLayout(const DXShader& dxShader, const Graphics::API::VertexBufferLayout& vertexBufferLayout);
						void* Map() const;
						void Unmap() const;
						void Bind() const;

					private:
						DXGI_FORMAT DXVertexBuffer::GetDXDataType(Graphics::API::VertexBufferLayout::DataType dataType);
				};
			}
		}
	}
}