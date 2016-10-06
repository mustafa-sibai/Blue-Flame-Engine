#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include "DXShader.h"
#include "../../../Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXConstentBuffer
				{
					private:
						ID3D11Buffer *buffer;
						HRESULT hr;
						DXContext *dxContext;
						DXShader *dxShader;

					public:
						DXConstentBuffer(DXContext *dxContext, DXShader *dxShader);
						~DXConstentBuffer();

						void Create(void *data, unsigned int size);
						void Update(void *data);
				};
			}
		}
	}
}
#endif