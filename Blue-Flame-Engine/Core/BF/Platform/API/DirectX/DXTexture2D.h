#pragma once
#include "DXContext.h"
#include "BF/IO/ImageReader.h"

namespace BF
{
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
						ID3D11Texture2D* texture2D;
						ID3D11ShaderResourceView* resourceView;
						ID3D11SamplerState* samplerState;
						HRESULT hr;

						uint8_t* data;
						unsigned int width, height;

					public:
						DXTexture2D(DXContext* dxContext);
						~DXTexture2D();

						void Load(const char* fileName);

						void Bind() const;
						void Unbind() const;

						inline unsigned int GetWidth() const { return width; }
						inline unsigned int GetHeight() const { return height; }
				};
			}
		}
	}
}