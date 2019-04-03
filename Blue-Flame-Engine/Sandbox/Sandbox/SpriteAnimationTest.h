#pragma once
#include <BF/BlueFlame.h>

namespace SpriteAnimationTest
{
	class SpriteAnimationTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Math::Rectangle orthographicRectangle;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;

	public:
		SpriteAnimationTest();
		~SpriteAnimationTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update() override;
		void Render() override;
	};
}