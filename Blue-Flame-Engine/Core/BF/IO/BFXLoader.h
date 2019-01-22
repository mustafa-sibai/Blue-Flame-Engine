#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "BF/Graphics/MeshData.h"
#include "BF/IO/FileFormats/BFXFormat.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API BFXLoader
		{
		public:
			static BF::Graphics::MeshData* Load(const std::string& filename);
		};
	}
}