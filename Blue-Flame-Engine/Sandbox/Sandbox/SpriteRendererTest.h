#pragma once
#include <BF/BlueFlame.h>
#include <BF/Debug/Debug.h>

namespace SpriteRendererTest
{
	class SpriteRendererTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::RenderLayer* guiRenderLayer;
		BF::Math::Rectangle orthographicRectangle;

	public:
		SpriteRendererTest();
		~SpriteRendererTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;
	};
}