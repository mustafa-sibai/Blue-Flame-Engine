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
				class BF_API DXIndexBuffer
				{
					private:
						const DXContext* dxContext;

						ID3D11Buffer* buffer;
						HRESULT hr;

						unsigned int count;

					public:
						DXIndexBuffer(const DXContext* dxContext);
						~DXIndexBuffer();

						void Create(const unsigned int* indices, unsigned int count);
						void Bind() const;

						inline unsigned int GetIndicesCount() const { return count; }
				};
			}
		}
	}
}