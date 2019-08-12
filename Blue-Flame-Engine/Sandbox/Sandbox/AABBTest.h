#pragma once
#include <BF/BlueFlame.h>

namespace AABBTest
{
	class AABBTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::RenderLayer* guiRenderLayer;
		BF::Math::Rectangle orthographicRectangle;

		BF::ECS::GameObject* sprite;
		BF::Math::Vector3f direction;
		float speed = 0.05f;

	public:
		AABBTest();
		~AABBTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;
	};
}