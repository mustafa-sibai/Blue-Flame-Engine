#pragma once
#include "DXContext.h"

namespace BF
{
	namespace Graphics { namespace API { class Texture2D; } }

	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXTexture2D
				{
					private:
						DXContext* dxContext;
						Graphics::API::Texture2D* texture2D;

						ID3D11Texture2D* textureID;
						ID3D11ShaderResourceView* resourceView;
						ID3D11SamplerState* samplerState;
						HRESULT hr;

					public:
						DXTexture2D(DXContext* dxContext, Graphics::API::Texture2D* texture2D);
						~DXTexture2D();

						void Create();
						void Bind() const;
						void Unbind() const;
				};
			}
		}
	}
}