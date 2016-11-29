#pragma once
#include "DXContext.h"
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
						const DXContext* dxContext;

						ID3D11Texture2D* textureID;
						ID3D11ShaderResourceView* resourceView;
						ID3D11SamplerState* samplerState;
						HRESULT hr;

					public:
						DXTexture2D(const DXContext* dxContext);
						~DXTexture2D();

						void Create(unsigned int width, unsigned int height, Graphics::API::Texture::Format format, const uint8_t* data, Graphics::API::Texture::TextureWrap textureWrap, Graphics::API::Texture::TextureFilter textureFilter);
						void Bind(unsigned int index) const;

					private:
						DXGI_FORMAT GetDXTextureFormat(Graphics::API::Texture::Format format) const;
						D3D11_TEXTURE_ADDRESS_MODE GetDXTextureWrap(Graphics::API::Texture::TextureWrap textureWrap) const;
						D3D11_FILTER GetDXTextureFilter(Graphics::API::Texture::TextureFilter textureFilter) const;
				};
			}
		}
	}
}