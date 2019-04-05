#pragma once
#include <BF/BlueFlame.h>

namespace IsoMapTest
{
	class IsoMapTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Math::Rectangle orthographicRectangle;
		BF::ECS::GameObject* movingSprite;
		BF::Math::Vector2f IsoPosition;
		BF::Math::Vector2f carPosition;
		BF::Math::Vector2f IsoPosition2f;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::RenderLayer* guiRenderLayer;

	public:
		IsoMapTest();
		~IsoMapTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;

	private:
		void CreateMap();
		void SortingTest();
	};
}