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
			BF::Math::Vector4f posDir;

			Color ambientColor;
			Color diffuseColor;
			Color specularColor;

			float constant = 1.0f;
			float linear = 0.0014f;
			float quadratic = 0.000007f;
			float padding;
		};
	}
}