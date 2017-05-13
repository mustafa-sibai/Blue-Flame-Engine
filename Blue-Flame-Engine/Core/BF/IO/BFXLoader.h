#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "BF/Graphics/Mesh.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API BFXLoader
		{
			public:
				static std::vector<Graphics::Mesh>* Load(const std::string& filename);
		};
	}
}