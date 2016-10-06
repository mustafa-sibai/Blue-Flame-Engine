#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include <iostream>
#include "DXContext.h"
#include "../../../Graphics/API/BufferLayout.h"
#include "DXShader.h"

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
						HRESULT hr;
						ID3D11Buffer *buffer;
						ID3D11InputLayout *inputLayout;
						DXContext *dxContext;
						DXShader *dxShader;
						Graphics::API::BufferLayout *bufferLayout;

					public:
						DXVertexBuffer(DXContext *dxContext, DXShader *dxShader);
						~DXVertexBuffer();

						void Create(void* data, const unsigned int size);
						void SetLayout(Graphics::API::BufferLayout *bufferLayout);
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