#ifdef BF_PLATFORM_WINDOWS
#include "DXTexture2D.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXTexture2D::DXTexture2D(DXContext *dxContext) :
					dxContext(dxContext)
				{
				}

				DXTexture2D::~DXTexture2D()
				{
				}

				void DXTexture2D::Load(const char *fileName)
				{
				}
			}
		}
	}
}
#endif