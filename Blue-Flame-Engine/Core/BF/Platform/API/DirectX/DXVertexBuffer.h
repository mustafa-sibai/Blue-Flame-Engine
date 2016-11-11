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
						DXContext* dxContext;
						DXShader* dxShader;
						Graphics::API::VertexBufferLayout* vertexBufferLayout;
						
						ID3D11Buffer* buffer;
						ID3D11InputLayout* inputLayout;
						HRESULT hr;

					public:
						DXVertexBuffer(DXContext* dxContext, DXShader* dxShader);
						~DXVertexBuffer();

						void Create(const void* data, unsigned int size);
						void SetLayout(Graphics::API::VertexBufferLayout* vertexBufferLayout);
						void* Map() const;
						void Unmap() const;
						void Bind() const;
						void Unbind() const;

					private:
						DXGI_FORMAT DXVertexBuffer::GetDXDataType(Graphics::API::DataType dataType);
				};
			}
		}
	}
}