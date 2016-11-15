#pragma once
#include "DXShader.h"

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
						DXContext* dxContext;
						DXShader* dxShader;

						ID3D11Buffer* buffer;
						HRESULT hr;

					public:
						DXConstentBuffer(DXContext* dxContext, DXShader* dxShader);
						~DXConstentBuffer();

						void Create(unsigned int size);
						void Update(void* data);
				};
			}
		}
	}
}