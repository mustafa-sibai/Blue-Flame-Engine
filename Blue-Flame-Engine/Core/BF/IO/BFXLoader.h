#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "BF/Graphics/Mesh.h"
#include "BF/IO/FileFormats/BFXFormat.h"
#include "BF/Application/Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API BFXLoader
		{
			public:
				static void Load(const std::string& filename, BF::Application::Scene& scene);
		};
	}
}