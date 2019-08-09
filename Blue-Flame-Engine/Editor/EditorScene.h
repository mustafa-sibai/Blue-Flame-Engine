#pragma once
#include <BF/BlueFlame.h>

namespace Editor
{
	class EditorApp : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::RenderLayer* guiRenderLayer;
		BF::Math::Rectangle orthographicRectangle;

	public:
		EditorApp();
		~EditorApp();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;
	};
}