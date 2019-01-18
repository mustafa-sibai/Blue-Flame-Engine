#pragma once
#include <BF/BlueFlame.h>

namespace Forward_Renderer_Test
{
	class Forward_Renderer_Test : public BF::Application::App
	{
		private:
			//BF::Graphics::API::Shader P, PUV, PN, PUVN, PUVNTB;//, shader, lightShader;
			//BF::Graphics::API::ConstantBuffer constantBuffer;
			//BF::Graphics::Model crateModel;
			BF::Application::Scene* scene;

			//bool directionalLight;
			//float lightAngle;
			//int lightIndex = 0;

			//BF::Graphics::API::Shader PUVNTB;
			BF::Graphics::API::Shader PN1;
			//BF::Graphics::API::Shader PN2;
			//BF::Graphics::API::Shader PN3;

			BF::Graphics::Transform* transform;

			//BF::Graphics::LightBuffer lights;

			/*BF::Graphics::API::Texture2D diffuseMap;
			BF::Graphics::API::Texture2D normalMap;
			BF::Graphics::API::Texture2D specularMap;*/

			/*BF::Graphics::Materials::MeshMaterial* crateMaterial1;
			BF::Graphics::Materials::MeshMaterial* crateMaterial2;
			BF::Graphics::Materials::MeshMaterial* crateMaterial3;
			BF::Graphics::Materials::MeshMaterial* crateMaterial4;
			BF::Graphics::Materials::MeshMaterial* crateMaterial5;*/
			BF::Graphics::Materials::MeshMaterial* planeMaterial;

			//BF::Math::Vector3f lightPosition;

			//float angle = 0;

		public:
			Forward_Renderer_Test();
			~Forward_Renderer_Test();

		public:
			void Initialize() override;
			void Load() override;
			void PostLoad() override;
			void Update() override;
			void Render() override;
	};
}