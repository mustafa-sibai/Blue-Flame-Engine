#ifdef BF_PLATFORM_WINDOWS
#include "DXTexture2D.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXTexture2D::DXTexture2D(DXContext *dxContext) :
					dxContext(dxContext), texture2D(nullptr), resourceView(nullptr), samplerState(nullptr), hr(0), data(nullptr), width(0), height(0)
				{
				}

				DXTexture2D::~DXTexture2D()
				{
				}

				void DXTexture2D::Load(const char *fileName)
				{
					data = BF::IO::ImageReader::ReadImage(fileName, &width, &height);

					D3D11_TEXTURE2D_DESC texDesc;
					ZeroMemory(&texDesc, sizeof(texDesc));

					texDesc.Width = width;
					texDesc.Height = height;
					texDesc.MipLevels = texDesc.ArraySize = 1;
					texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
					texDesc.SampleDesc.Count = 1;
					texDesc.Usage = D3D11_USAGE_DYNAMIC;
					texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
					texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
					texDesc.MiscFlags = 0;

					D3D11_SUBRESOURCE_DATA subData;
					ZeroMemory(&subData, sizeof(subData));

					subData.pSysMem = data;
					subData.SysMemPitch = width * 4;
					subData.SysMemSlicePitch = 0;

					hr = dxContext->GetDevice()->CreateTexture2D(&texDesc, &subData, &texture2D);
					if (FAILED(hr))
					{
						//print error
					}

					D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
					ZeroMemory(&srvDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

					srvDesc.Format = texDesc.Format;
					srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
					srvDesc.Texture2D.MipLevels = texDesc.MipLevels;

					hr = dxContext->GetDevice()->CreateShaderResourceView(texture2D, &srvDesc, &resourceView);
					if (FAILED(hr))
					{
						//print error
					}

					D3D11_SAMPLER_DESC samplerDesc;
					ZeroMemory(&samplerDesc, sizeof(D3D11_SAMPLER_DESC));

					samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
					samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
					samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
					samplerDesc.MinLOD = 0;
					samplerDesc.MaxLOD = 11;
					samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
					samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
					samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

					hr = dxContext->GetDevice()->CreateSamplerState(&samplerDesc, &samplerState);
					if (FAILED(hr))
					{
						//print error
					}
				}

				const void DXTexture2D::Bind() const
				{
					dxContext->GetContext()->PSSetShaderResources(0, 1, &resourceView);
					dxContext->GetContext()->PSSetSamplers(0, 1, &samplerState);
				}

				const void DXTexture2D::Unbind() const
				{
				}
			}
		}
	}
}
#endif