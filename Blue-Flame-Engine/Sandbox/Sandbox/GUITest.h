#pragma once
#include <BF/BlueFlame.h>

namespace GUITest
{
	class GUITest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Math::Rectangle orthographicRectangle;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::RenderLayer* guiRenderLayer;

	public:
		GUITest();
		~GUITest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update() override;
		void Render() override;
	};
}