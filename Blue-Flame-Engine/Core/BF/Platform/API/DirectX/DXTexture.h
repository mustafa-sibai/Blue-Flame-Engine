#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include "DXContext.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXTexture
				{
					private:
						ID3D11ShaderResourceView *texture;
						ID3D11Texture2D *texture2D;
						DXContext *dxContext;
					public:
						DXTexture(DXContext *dxContext);
						~DXTexture();

						void Load();
				};
			}
		}
	}
}
#endif