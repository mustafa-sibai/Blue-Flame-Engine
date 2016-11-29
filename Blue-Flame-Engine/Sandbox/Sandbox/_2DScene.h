#pragma once
#include <BF/BlueFlame.h>
#include <BF/Graphics/Font.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <vector>

namespace _2DScene
{
	struct InitBuffer
	{
		BF::Math::Matrix4 modelMatrix;
		BF::Math::Matrix4 viewMatrix;
		BF::Math::Matrix4 projectionMatrix;
	};

	class _2DScene
	{
		private:
			BF::Application::Window* window;
			BF::Graphics::API::Context* context;
			BF::Graphics::API::Shader* shader;
			InitBuffer initBuffer;
			BF::Graphics::API::ConstentBuffer* constentBuffer;

			BF::Graphics::Renderers::SpriteRenderer* spriteRenderer;
			//std::vector<BF::Graphics::Renderers::Sprite*>* sprites;
			BF::System::Timer* timer;

			BF::Graphics::API::Texture2D* t;
			BF::Graphics::API::Texture2D* t2;
			int frames = 0;

			BF::Graphics::Font* font;

		public:
			_2DScene(BF::Application::Window* window);
			~_2DScene();

			void Draw();
			void CleanUp();
	};
}