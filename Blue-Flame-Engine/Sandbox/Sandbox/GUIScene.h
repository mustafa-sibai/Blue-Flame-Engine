#pragma once
#include <BF/BlueFlame.h>

namespace GUIScene
{
	class GUIScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::Camera camera;
			BF::Graphics::Renderers::SpriteRenderer spriteRenderer;

			BF::Graphics::GUI::Button button;
			//BF::Graphics::GUI::Label label;

			BF::Graphics::Fonts::Font font;
			BF::Graphics::Fonts::Font font2;
			BF::Graphics::Renderers::Text text;
			BF::Graphics::Renderers::Text text2;

			BF::Graphics::Renderers::RegularPolygon s;
			BF::Graphics::Renderers::Sprite ss;
			BF::Graphics::API::Texture2D t;

		public:
			GUIScene();
			~GUIScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void Render() override;
	};
}