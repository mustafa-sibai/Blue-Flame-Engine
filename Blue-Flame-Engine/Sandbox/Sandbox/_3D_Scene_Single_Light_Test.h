#pragma once
#include <BF/BlueFlame.h>

namespace _3D_Scene_Single_Light_Test
{
	class _3D_Scene_Single_Light_Test : public BF::Application::Scene
	{
		private:
			BF::Graphics::FPSCamera fpsCamera;
			BF::Graphics::API::Shader shader;

			BF::Graphics::API::ConstantBuffer constantBuffer;
			BF::Graphics::API::ConstantBuffer materialConstantBuffer;

			BF::Graphics::Model cubeModel;
			BF::Graphics::Material cubeMaterial;

			BF::Graphics::LightBuffer light;

		public:
			_3D_Scene_Single_Light_Test();
			~_3D_Scene_Single_Light_Test();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void Render() override;
	};
}