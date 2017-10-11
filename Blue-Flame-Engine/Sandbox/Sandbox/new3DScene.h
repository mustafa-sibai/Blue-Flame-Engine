#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

namespace new3DScene
{
	class new3DScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::API::Shader P, PUV, PN, PUVN, PUVNTB;//, shader, lightShader;
			BF::Graphics::API::ConstantBuffer constantBuffer;
			BF::Graphics::API::ConstantBuffer materialConstantBuffer;
			//BF::Graphics::Model lightModel;
			//BF::Graphics::Model cubeModel;
			BF::Graphics::Model crateModel;
			//BF::Graphics::Model planeModel;
			BF::Graphics::FPSCamera fpsCamera;
			//BF::Graphics::Terrain terrain;

			bool directionalLight;
			float lightAngle;
			int lightIndex = 0;

			BF::Graphics::LightBuffer lights;
			//BF::Graphics::Material floorMaterial;
			BF::Graphics::Material crateMaterial;

			BF::Graphics::Skybox skybox;
			float angle = 0;

		public:
			new3DScene();
			~new3DScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			//void FixedUpdate() override;
			void Render() override;
			void RenderAllModels();
	};
}