#pragma once
#include <d3d11.h>
#include "BF/Common.h"

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
						ID3D11Buffer* buffer;

						unsigned int count;

					public:
						DXIndexBuffer();
						~DXIndexBuffer();

						void Create(const unsigned int* indices, unsigned int count);
						void Bind() const;

						inline unsigned int GetIndicesCount() const { return count; }
				};
			}
		}
	}
}