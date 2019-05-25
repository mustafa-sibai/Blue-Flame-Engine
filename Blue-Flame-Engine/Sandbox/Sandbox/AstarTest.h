#pragma once
#include <BF/BlueFlame.h>

namespace AstarTest
{
	class AstarTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Math::Rectangle orthographicRectangle;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::API::Texture2D* startingNodeTexture;
		BF::Graphics::API::Texture2D* endNodeTexture;
		BF::Graphics::API::Texture2D* nodeTexture;

	public:
		AstarTest();
		~AstarTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;
	};
}