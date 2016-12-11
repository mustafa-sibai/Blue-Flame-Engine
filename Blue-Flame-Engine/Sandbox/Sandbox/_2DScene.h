#pragma once
#include <BF/BlueFlame.h>
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

	class _2DScene : public Scene
	{
		private:
			BF::Graphics::API::Shader* shader;

			BF::Graphics::API::ConstentBuffer* constentBuffer;
			BF::Graphics::Renderers::SpriteRenderer* spriteRenderer;
			BF::Graphics::API::Texture2D* t;
			BF::Graphics::API::Texture2D* t2;
			BF::Graphics::Font* font;
			InitBuffer initBuffer;
			//std::vector<BF::Graphics::Renderers::Sprite*>* sprites;

		public:
			_2DScene();
			~_2DScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void FixedUpdate() override;
			void Render() override;
	};
}