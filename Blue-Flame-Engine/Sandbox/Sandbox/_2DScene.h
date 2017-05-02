#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>
//#include "TestPanel.h"

namespace _2DScene
{
	class _2DScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
			
			//BF::Graphics::API::RenderTarget renderTarget;

			BF::Graphics::API::Texture2D* t;
			BF::Graphics::API::Texture2D* t2;
			BF::Graphics::API::Texture2D* t3;
			BF::Graphics::API::Texture2D* t4;

			BF::Graphics::Renderers::LineShape line;
			BF::Graphics::Renderers::LineShape line2;
			
			BF::Graphics::Renderers::RegularPolygon rp;
			BF::Graphics::Renderers::RegularPolygon rp2;

			BF::Graphics::Renderers::Sprite sprite1;
			BF::Graphics::Renderers::Sprite sprite2;
			BF::Graphics::Renderers::Sprite sprite3;
			BF::Graphics::Renderers::Sprite sprite4;
			BF::Graphics::Renderers::Sprite sprite5;

			BF::Graphics::Renderers::Sprite sprite6;
			BF::Graphics::Renderers::Sprite sprite7;
			BF::Graphics::Renderers::Sprite sprite8;

			BF::Graphics::Renderers::Sprite fontSprite;
			BF::Graphics::Fonts::Font font;
			BF::Graphics::Fonts::FontAtlas* fontAtlas;
			
			BF::Graphics::TileMap tileMap;
			
			BF::Graphics::GUI::Button button;
			BF::Graphics::GUI::Checkbox checkbox;

			//TestPanel panel;
			BF::Graphics::Camera camera;

			BF::AI::Waypoint waypoint;
			std::vector<BF::AI::Waypoint::Node> waypoints;

			BF::System::Timer timer;
			BF::AI::Waypoint::Node node;
			BF::AI::Waypoint::Node node2;

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
			//void FixedUpdate() override;
			void Render() override;

			static bool TimeFunction(void* this_pointer);
	};
}