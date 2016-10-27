#include "DXConstentBuffer.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXConstentBuffer::DXConstentBuffer(DXContext* dxContext, DXShader* dxShader) :
					dxContext(dxContext), dxShader(dxShader), buffer(nullptr), hr(0)
				{
				}

				DXConstentBuffer::~DXConstentBuffer()
				{
				}

				void DXConstentBuffer::Create(void* data, unsigned int size)
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

					hr = dxContext->GetDevice()->CreateBuffer(&bufferDesc, NULL, &buffer);

					if (FAILED(hr))
						std::cout << "Could not create a constent buffer." << std::endl;

					dxContext->GetContext()->VSSetConstantBuffers(0, 1, &buffer);
				}

				void DXConstentBuffer::Update(void* data)
				{
					//TODO: slow should use map instead
					dxContext->GetContext()->UpdateSubresource(buffer, 0, 0, data, 0, 0);
				}
			}
		}
	}
}