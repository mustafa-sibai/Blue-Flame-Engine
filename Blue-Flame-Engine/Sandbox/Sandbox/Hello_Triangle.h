#pragma once
#include <BF/BlueFlame.h>

namespace Hello_Triangle
{
	class Hello_Triangle : public BF::Application::App
	{
		private:
			BF::Application::Scene* scene;
			BF::Graphics::Camera camera;

			BF::Math::Vector3f vertices[3];
			unsigned int indices[3];

			BF::Math::Vector3f position;
			BF::Graphics::API::Shader shader;

			BF::Graphics::API::VertexBuffer vb;
			BF::Graphics::API::VertexBufferLayout vbl;
			BF::Graphics::API::IndexBuffer ib;

		public:
			Hello_Triangle();
			~Hello_Triangle();

			void Initialize() override;
			void Load() override;
			void PostLoad() override;
			void Update() override;
			void Render() override;
	};
}