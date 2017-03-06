#pragma once
#include <d3d11.h>
#include "BF/Graphics/API/Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXTexture2D : public Graphics::API::Texture
				{
					private:
						ID3D11Texture2D* textureID;
						ID3D11ShaderResourceView* resourceView;
						ID3D11SamplerState* samplerState;

					public:
						DXTexture2D();
						~DXTexture2D();

						void Create(const TextureData& textureData, Graphics::API::Texture::Format format, Graphics::API::Texture::Wrap wrap, Graphics::API::Texture::Filter filter);
						void Bind(unsigned int index) const;

					private:
						DXGI_FORMAT GetDXTextureFormat(Graphics::API::Texture::Format format) const;
						D3D11_TEXTURE_ADDRESS_MODE GetDXTextureWrap(Graphics::API::Texture::Wrap wrap) const;
						D3D11_FILTER GetDXTextureFilter(Graphics::API::Texture::Filter filter) const;
				};
			}
		}
	}
}