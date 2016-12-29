#pragma once
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BF_API TileData
		{
			int textureID;
			Math::Rectangle rectangle;
			Math::Rectangle scissorRectangle;
		};
	}
}