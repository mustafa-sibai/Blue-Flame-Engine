#pragma once
#include <BF/BlueFlame.h>

namespace GUIScene
{
	class GUIScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::Camera camera;
			//BF::Graphics::Renderers::SpriteRenderer spriteRenderer;

			BF::Graphics::GUI::Button button;
			BF::Graphics::GUI::Label label;

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