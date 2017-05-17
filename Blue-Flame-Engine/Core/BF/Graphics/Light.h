#pragma once
#include "Color.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct LightBuffer
		{
			Math::Vector4 posDir;

			Color ambientColor;
			Color diffuseColor;
			Color specularColor;
		};
	}
}