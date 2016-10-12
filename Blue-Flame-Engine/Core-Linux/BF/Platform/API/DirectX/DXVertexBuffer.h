#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include <iostream>
#include "DXContext.h"
#include "DXShader.h"
#include "../../../Graphics/API/VertexBufferLayout.h"

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
						DXContext *dxContext;
						DXShader *dxShader;
						Graphics::API::VertexBufferLayout *vertexBufferLayout;
						
						ID3D11Buffer *buffer;
						ID3D11InputLayout *inputLayout;
						HRESULT hr;

					public:
						DXVertexBuffer(DXContext *dxContext, DXShader *dxShader);
						~DXVertexBuffer();

						void Create(void* data, const unsigned int size);
						void SetLayout(Graphics::API::VertexBufferLayout *vertexBufferLayout);
						void Bind();
						void Unbind();

					private:
						DXGI_FORMAT DXVertexBuffer::GetDXDataType(Graphics::API::DataType dataType);
				};
			}
		}
	}
}
#endif