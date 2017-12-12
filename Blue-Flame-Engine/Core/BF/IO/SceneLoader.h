#pragma once
#include "BF/Application/Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API SceneLoader
		{
			public:
				SceneLoader();
				~SceneLoader();

				static BF::Application::Scene* SceneLoader::Load(const std::string& filename);
		};
	}
}