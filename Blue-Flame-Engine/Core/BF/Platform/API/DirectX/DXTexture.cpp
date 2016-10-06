#ifdef BF_PLATFORM_WINDOWS
#include "DXTexture.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXTexture::DXTexture(DXContext *dxContext) :
					dxContext(dxContext)
				{
				}

				DXTexture::~DXTexture()
				{
				}

				void DXTexture::Load()
				{
				}
			}
		}
	}
}
#endif