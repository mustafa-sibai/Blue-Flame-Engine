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
						DXContext *dxContext;

						ID3D11Buffer *buffer;
						HRESULT hr;

						unsigned int count;

					public:
						DXIndexBuffer(DXContext *dxContext);
						~DXIndexBuffer();

						void Create(const unsigned int* const indices, const unsigned int count);

						const void Bind() const;
						const void Unbind() const;

						inline const unsigned int GetIndicesCount() const { return count; }
				};
			}
		}
	}
}