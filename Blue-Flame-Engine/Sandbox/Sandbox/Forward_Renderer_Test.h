#pragma once
#include <BF/BlueFlame.h>

namespace Forward_Renderer_Test
{
	class Forward_Renderer_Test : public BF::Application::App
	{
		private:
			//BF::Graphics::API::Shader P, PUV, PN, PUVN, PUVNTB;//, shader, lightShader;
			BF::Graphics::API::ConstantBuffer constantBuffer;
			//BF::Graphics::API::ConstantBuffer materialConstantBuffer;
			//BF::Graphics::Model crateModel;
			BF::Application::Scene* scene;
			BF::Graphics::FPSCamera fpsCamera;

			bool directionalLight;
			float lightAngle;
			int lightIndex = 0;

			BF::Graphics::API::Shader PUVNTB;
			BF::Graphics::API::Shader PN;

			BF::Graphics::Transform* transform;

			BF::Graphics::LightBuffer lights;

			BF::Graphics::Materials::MeshMaterial* crateMaterial;
			BF::Graphics::Materials::MeshMaterial* planeMaterial;

			float angle = 0;

		public:
			Forward_Renderer_Test();
			~Forward_Renderer_Test();

		public:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void Render() override;
	};
}