#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

namespace _3DScene
{
	class _3DScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::API::Shader shader, lightShader;
			BF::Graphics::API::ConstantBuffer constantBuffer;
			BF::Graphics::API::ConstantBuffer materialConstantBuffer;
			BF::Graphics::Model lightModel;
			BF::Graphics::Model cubeModel;
			BF::Graphics::Model planeModel;
			BF::Graphics::Model wallModel;
			BF::Graphics::FPSCamera fpsCamera;
			//BF::Graphics::Terrain terrain;

			bool directionalLight;
			float lightAngle;

			BF::Graphics::LightBuffer light;
			BF::Graphics::Material floorMaterial;
			BF::Graphics::Material wallMaterial;

			BF::Graphics::Skybox skybox;
			float angle = 0;

		public:
			_3DScene();
			~_3DScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			//void FixedUpdate() override;
			void Render() override;
	};
}