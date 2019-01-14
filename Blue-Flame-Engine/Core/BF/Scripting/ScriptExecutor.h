#pragma once
#include <vector>
#include "BF/Scripting/Script.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Scripting
	{
		class BF_API ScriptExecutor
		{
			friend class BF::ECS::GameObject;
			friend class BF::Application::Scene;

			private:
				std::vector<Script*> scripts;

			public:
				ScriptExecutor();
				~ScriptExecutor();

				void Start();
				void Update();
		};
	}
}