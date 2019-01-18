#pragma once
#include <BF/BlueFlame.h>

namespace ECS_Script_Test
{
	class ECS_Script_Test : public BF::Application::App
	{
		private:
			BF::Application::Scene* scene;

		public:
			ECS_Script_Test();
			~ECS_Script_Test();

			void Initialize() override;
			void Load() override;
			void PostLoad() override;
			void Update() override;
			void Render() override;
	};
}