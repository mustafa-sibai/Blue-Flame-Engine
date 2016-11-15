#include "DXTexture2D.h"
#include "BF/Graphics/API/Texture2D.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXTexture2D::DXTexture2D(DXContext* dxContext, Graphics::API::Texture2D* texture2D) :
					dxContext(dxContext), texture2D(texture2D), textureID(nullptr), resourceView(nullptr), samplerState(nullptr), hr(0)
				{
				}

				DXTexture2D::~DXTexture2D()
				{
				}

				void DXTexture2D::Create()
				{
					D3D11_TEXTURE2D_DESC texDesc;
					ZeroMemory(&texDesc, sizeof(texDesc));

					texDesc.Width = texture2D->GetWidth();
					texDesc.Height = texture2D->GetHeight();
					texDesc.MipLevels = texDesc.ArraySize = 1;
					texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
					texDesc.SampleDesc.Count = 1;
					texDesc.Usage = D3D11_USAGE_DYNAMIC;
					texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
					texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
					texDesc.MiscFlags = 0;

					D3D11_SUBRESOURCE_DATA subData;
					ZeroMemory(&subData, sizeof(subData));

					subData.pSysMem = texture2D->GetData();
					subData.SysMemPitch = texture2D->GetWidth() * 4;
					subData.SysMemSlicePitch = 0;

					hr = dxContext->GetDevice()->CreateTexture2D(&texDesc, &subData, &textureID);
					if (FAILED(hr))
						std::cout << "Failed to create D3D11 Texture2D for D3D11 texture" << std::endl;

					D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
					ZeroMemory(&srvDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

					srvDesc.Format = texDesc.Format;
					srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
					srvDesc.Texture2D.MipLevels = texDesc.MipLevels;

					hr = dxContext->GetDevice()->CreateShaderResourceView(textureID, &srvDesc, &resourceView);
					if (FAILED(hr))
						std::cout << "Failed to create ShaderResourceView for D3D11 texture" << std::endl;

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
						std::cout << "Failed to create D3D11 SamplerState texture" << std::endl;
				}

				void DXTexture2D::Bind() const
				{
					dxContext->GetContext()->PSSetShaderResources(0, 1, &resourceView);
					dxContext->GetContext()->PSSetSamplers(0, 1, &samplerState);
				}

				void DXTexture2D::Unbind() const
				{
				}
			}
		}
	}
}