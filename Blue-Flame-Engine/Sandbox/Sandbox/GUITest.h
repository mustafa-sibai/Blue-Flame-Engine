#pragma once
#include <BF/BlueFlame.h>
#include "BF/Graphics/GUI3/Button.h"
#include "BF/Graphics/GUI3/CheckBox.h"

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
		BF::Graphics::GUI::Button* button;
		BF::Graphics::GUI::CheckBox* checkBox;

	public:
		GUITest();
		~GUITest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update(double deltaTime) override;
		void Render() override;

		//Text UI creation
		void CreateTestButton();
		void ButtonStateTest();
		void CreateTestCheckBox();
	};
}