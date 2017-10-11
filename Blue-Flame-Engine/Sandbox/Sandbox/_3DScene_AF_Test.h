#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

namespace _3DScene_AF_Test
{
	class _3DScene_AF_Test : public BF::Application::Scene
	{
		private:
			BF::Graphics::API::Shader shader, lightShader;
			BF::Graphics::API::ConstantBuffer constantBuffer;
			BF::Graphics::API::ConstantBuffer materialConstantBuffer;
			BF::Graphics::Model lightModel;
			BF::Graphics::Model cubeModel;
			BF::Graphics::Model planeModel;
			BF::Graphics::FPSCamera fpsCamera;
			//BF::Graphics::Terrain terrain;

			BF::Graphics::LightBuffer light;
			BF::Graphics::Material material;

			BF::Graphics::Skybox skybox;
			float angle = 0;

		public:
			_3DScene_AF_Test();
			~_3DScene_AF_Test();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			//void FixedUpdate() override;
			void Render() override;
	};
}