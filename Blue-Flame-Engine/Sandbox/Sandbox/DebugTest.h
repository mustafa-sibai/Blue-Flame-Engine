#pragma once
#include <BF/BlueFlame.h>
#include <BF/Debug/Debug.h>

namespace DebugTest
{
	class DebugTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Graphics::Renderers::RenderLayer* defaultRenderLayer;
		BF::Graphics::Renderers::RenderLayer* spriteRenderLayer;
		BF::Graphics::Renderers::RenderLayer* guiRenderLayer;
		BF::Math::Rectangle orthographicRectangle;

		std::vector<BF::System::Transform*> transforms;

	public:
		DebugTest();
		~DebugTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;
	};
}