#pragma once
#include "BF/Math/Vector4.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Material
		{
			public:
				std::string diffuseMapName;
				Math::Vector4 diffuseColor;

			public:
				Material(std::string diffuseMapName, Math::Vector4 diffuseColor);
				~Material();
		};
	}
}