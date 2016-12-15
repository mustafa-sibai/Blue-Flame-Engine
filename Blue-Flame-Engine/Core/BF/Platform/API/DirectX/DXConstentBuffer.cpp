#include "DXConstentBuffer.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXConstentBuffer::DXConstentBuffer() :
					buffer(nullptr), hr(0)
				{
				}

				DXConstentBuffer::~DXConstentBuffer()
				{
				}

				void DXConstentBuffer::Create(unsigned int size)
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

					hr = Engine::GetContext().GetDXContext().GetDevice()->CreateBuffer(&bufferDesc, NULL, &buffer);

					if (FAILED(hr))
						std::cout << "Could not create a constent buffer." << std::endl;

					Engine::GetContext().GetDXContext().GetContext()->VSSetConstantBuffers(0, 1, &buffer);
				}

				void DXConstentBuffer::Update(void* data)
				{
					//TODO: Slow should use map instead.
					Engine::GetContext().GetDXContext().GetContext()->UpdateSubresource(buffer, 0, 0, data, 0, 0);
				}
			}
		}
	}
}