#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

namespace _2DScene
{
	class _2DScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
			
			BF::Graphics::API::Texture2D* t;
			BF::Graphics::API::Texture2D* t2;

			BF::Graphics::Renderers::Sprite sprite1;
			BF::Graphics::Renderers::Sprite sprite2;
			BF::Graphics::Renderers::Sprite sprite3;
			BF::Graphics::Renderers::Sprite sprite4;
			BF::Graphics::Renderers::Sprite sprite5;

			BF::Graphics::Renderers::Sprite fontSprite;
			BF::Graphics::Fonts::Font font;
			BF::Graphics::Fonts::FontAtlas* fontAtlas;
			
			BF::Graphics::TileMap tileMap;
			
			BF::Graphics::GUI::Button button;

			//BF::Graphics::Animation::SpriteAnimation spriteAnimation;
			//InitBuffer initBuffer;

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