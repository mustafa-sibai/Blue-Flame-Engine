#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

namespace _2DScene
{
	class _2DScene : public BF::Application::Scene
	{
		private:

		public:
			_2DScene();
			~_2DScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void FixedUpdate() override;
			void Render() override;
	};
}