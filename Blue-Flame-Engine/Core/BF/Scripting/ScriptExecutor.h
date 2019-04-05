#pragma once
#include <vector>
#include "BF/ECS/ISystem.h"
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
		class BFE_API ScriptExecutor : public BF::ECS::ISystem
		{
			friend class BF::ECS::GameObject;
			friend class BF::Application::Scene;

		private:
			std::vector<IScript*> scripts;

		public:
			ScriptExecutor();
			~ScriptExecutor();

			void Initialize()			  override;
			void Load()					  override;
			void PostLoad()				  override;
			void Update(double deltaTime) override;
			void Render()				  override;
		};
	}
}