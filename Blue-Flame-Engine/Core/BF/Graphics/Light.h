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

			float constant = 1.0f;
			float linear = 0.35f;
			float quadratic = 0.44f;
			float padding;
		};
	}
}