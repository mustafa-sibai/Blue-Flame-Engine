#pragma once
#include <iostream>
#include "DXContext.h"
#include "DXShader.h"
#include "BF/Graphics/API/VertexBufferLayout.h"

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
						const DXContext* dxContext;
						const DXShader* dxShader;
						const Graphics::API::VertexBufferLayout* vertexBufferLayout;
						
						ID3D11Buffer* buffer;
						ID3D11InputLayout* inputLayout;
						HRESULT hr;

					public:
						DXVertexBuffer(const DXContext* dxContext, const DXShader* dxShader);
						~DXVertexBuffer();

						void Create(const void* data, unsigned int size);
						void SetLayout(const Graphics::API::VertexBufferLayout* vertexBufferLayout);
						void* Map() const;
						void Unmap() const;
						void Bind() const;

					private:
						DXGI_FORMAT DXVertexBuffer::GetDXDataType(Graphics::API::DataType dataType);
				};
			}
		}
	}
}