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
						const DXContext* dxContext;
						const DXShader* dxShader;

						ID3D11Buffer* buffer;
						HRESULT hr;

					public:
						DXConstentBuffer(const DXContext* dxContext, const DXShader* dxShader);
						~DXConstentBuffer();

						void Create(unsigned int size);
						void Update(void* data);
				};
			}
		}
	}
}