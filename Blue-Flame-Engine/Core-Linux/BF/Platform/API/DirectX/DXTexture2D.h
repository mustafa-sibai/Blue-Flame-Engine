#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include "DXContext.h"
#include "../../../IO/ImageReader.h"

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
						DXContext *dxContext;
						ID3D11Texture2D *texture2D;
						ID3D11ShaderResourceView* resourceView;
						ID3D11SamplerState* samplerState;
						HRESULT hr;

						BYTE *data;
						unsigned int width, height;

					public:
						DXTexture2D(DXContext *dxContext);
						~DXTexture2D();

						void Load(const char *fileName);

						const void Bind() const;
						const void Unbind() const;

						inline const unsigned int GetWidth() const { return width; }
						inline const unsigned int GetHeight() const { return height; }
				};
			}
		}
	}
}
#endif