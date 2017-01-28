#include "DXTexture2D.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Engine.h"
#include "DXError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				using namespace BF::Graphics::API;

				DXTexture2D::DXTexture2D() :
					textureID(nullptr), resourceView(nullptr), samplerState(nullptr)
				{
				}

				DXTexture2D::~DXTexture2D()
				{
				}

				void DXTexture2D::Create(const TextureData& textureData, Texture::Format format, Texture::TextureWrap textureWrap, Texture::TextureFilter textureFilter)
				{
					D3D11_TEXTURE2D_DESC texDesc;
					ZeroMemory(&texDesc, sizeof(texDesc));

					texDesc.Width = textureData.width;
					texDesc.Height = textureData.height;
					texDesc.MipLevels = texDesc.ArraySize = 1;
					texDesc.Format = GetDXTextureFormat(format);
					texDesc.SampleDesc.Count = 1;
					texDesc.Usage = D3D11_USAGE_DYNAMIC;
					texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
					texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
					texDesc.MiscFlags = 0;

					D3D11_SUBRESOURCE_DATA subData;
					ZeroMemory(&subData, sizeof(subData));

					unsigned int stride = 4;

					subData.pSysMem = textureData.buffer;
					subData.SysMemPitch = textureData.width * stride;
					subData.SysMemSlicePitch = textureData.width * textureData.height * stride;

					DXCall(Engine::GetContext().GetDXContext().GetDevice()->CreateTexture2D(&texDesc, &subData, &textureID));

					//TODO: Add a way to disable and enable mip map
					D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
					ZeroMemory(&srvDesc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

					srvDesc.Format = texDesc.Format;
					srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
					srvDesc.Texture2D.MipLevels = texDesc.MipLevels;

					//DXCall(Engine::GetContext().GetDXContext().GetDevice()->CreateShaderResourceView(textureID, &srvDesc, &resourceView));
					DXCall(Engine::GetContext().GetDXContext().GetDevice()->CreateShaderResourceView(textureID, 0, &resourceView));

					D3D11_SAMPLER_DESC samplerDesc;
					ZeroMemory(&samplerDesc, sizeof(D3D11_SAMPLER_DESC));

					samplerDesc.AddressU = GetDXTextureWrap(textureWrap);
					samplerDesc.AddressV = GetDXTextureWrap(textureWrap);
					samplerDesc.AddressW = GetDXTextureWrap(textureWrap);
					samplerDesc.MinLOD = 0;
					samplerDesc.MaxLOD = 11;
					samplerDesc.Filter = GetDXTextureFilter(textureFilter);
					samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
					samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

					DXCall(Engine::GetContext().GetDXContext().GetDevice()->CreateSamplerState(&samplerDesc, &samplerState));
				}

				void DXTexture2D::Bind(unsigned int index) const
				{
					Engine::GetContext().GetDXContext().GetContext()->PSSetShaderResources(index, 1, &resourceView);
					Engine::GetContext().GetDXContext().GetContext()->PSSetSamplers(index, 1, &samplerState);
				}

				DXGI_FORMAT DXTexture2D::GetDXTextureFormat(Texture::Format format) const
				{
					switch (format)
					{
						case Texture2D::Format::R8: return DXGI_FORMAT_R8_UNORM;
						case Texture2D::Format::R8G8: return DXGI_FORMAT_R8G8_UNORM;
						case Texture2D::Format::R8G8B8: return DXGI_FORMAT_B8G8R8X8_UNORM;
						case Texture2D::Format::R8G8B8A8: return DXGI_FORMAT_R8G8B8A8_UNORM;
						default: return DXGI_FORMAT_R8G8B8A8_UNORM;
					}
				}

				D3D11_TEXTURE_ADDRESS_MODE DXTexture2D::GetDXTextureWrap(Texture::TextureWrap textureWrap) const
				{
					switch (textureWrap)
					{
						case Texture2D::TextureWrap::Repeat: return D3D11_TEXTURE_ADDRESS_WRAP;
						case Texture2D::TextureWrap::MirroredReapeat: return D3D11_TEXTURE_ADDRESS_MIRROR;
						case Texture2D::TextureWrap::ClampToEdge: return D3D11_TEXTURE_ADDRESS_CLAMP;
						case Texture2D::TextureWrap::ClampToBorder: return D3D11_TEXTURE_ADDRESS_BORDER;
						default: return D3D11_TEXTURE_ADDRESS_WRAP;
					}
				}

				D3D11_FILTER DXTexture2D::GetDXTextureFilter(Texture::TextureFilter textureFilter) const
				{
					//TODO: Add more texture filter types to control both min and mag
					switch (textureFilter)
					{
						case Texture2D::TextureFilter::Neatest: return D3D11_FILTER_MIN_MAG_MIP_POINT;
						case Texture2D::TextureFilter::Linear: return D3D11_FILTER_MIN_MAG_MIP_LINEAR;
						default: return D3D11_FILTER_MIN_MAG_MIP_POINT;
					}
				}
			}
		}
	}
}