#pragma once
#include <BF/BlueFlame.h>
#include <vector>
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

	class _3DScene
	{
		private:
			BF::Application::Window* window;
			BF::Graphics::API::Context* context;
			BF::Graphics::API::Shader* shader;
			InitBuffer initBuffer;
			BF::Graphics::API::ConstentBuffer* constentBuffer;

			BF::Graphics::Model* model;
			BF::Graphics::FPSCamera* fpsCamera;
			BF::System::Timer* timer;

			float angle = 0;
			int frames = 0;

		public:
			_3DScene(BF::Application::Window* window);
			~_3DScene();

			void Draw();
			void CleanUp();
	};
}