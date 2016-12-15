#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

namespace _3DScene
{
	struct InitBuffer
	{
		BF::Math::Matrix4 modelMatrix;
		BF::Math::Matrix4 viewMatrix;
		BF::Math::Matrix4 projectionMatrix;
	};

	class _3DScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::API::Shader shader;
			BF::Graphics::API::ConstentBuffer* constentBuffer;
			BF::Graphics::Model* model;
			BF::Graphics::FPSCamera* fpsCamera;

			InitBuffer initBuffer;
			float angle = 0;

		public:
			_3DScene();
			~_3DScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void FixedUpdate() override;
			void Render() override;
	};
}