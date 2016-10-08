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
				class BF_API DXTexture2D
				{
				private:
					ID3D11ShaderResourceView *texture;
					ID3D11Texture2D *texture2D;
					DXContext *dxContext;
				public:
					DXTexture2D(DXContext *dxContext);
					~DXTexture2D();

					void Load(const char *fileName);
				};
			}
		}
	}
}
#endif