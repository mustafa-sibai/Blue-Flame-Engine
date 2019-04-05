#pragma once
#include <BF/BlueFlame.h>

namespace CameraViewCullingTest
{
	class CameraViewCullingTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Math::Rectangle orthographicRectangle;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::SpriteRendererComponents::Sprite* sprite;
		BF::Graphics::Renderers::SpriteRendererComponents::Sprite* sprite2;

		BF::Graphics::Renderers::SpriteRendererComponents::Sprite* pointX;
		BF::Graphics::Renderers::SpriteRendererComponents::Sprite* pointY;
		BF::Graphics::Renderers::SpriteRendererComponents::Sprite* pointW;
		BF::Graphics::Renderers::SpriteRendererComponents::Sprite* pointH;

	public:
		CameraViewCullingTest();
		~CameraViewCullingTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;
	};
}