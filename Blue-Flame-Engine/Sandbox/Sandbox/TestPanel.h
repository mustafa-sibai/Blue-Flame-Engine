#pragma once
#include <BF/BlueFlame.h>

class TestPanel : public BF::Graphics::GUI::Panel
{
private:
	BF::Graphics::API::Texture2D* t;
	BF::Graphics::Renderers::Sprite s;

public:
	TestPanel(BF::Application::Scene& scene);
	~TestPanel();

protected:
	void Initialize(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
	void Load(const BF::Graphics::GUI::StyleSheet& StyleSheet, const std::string& widgetName) override;
	void Update() override;
	void Render() override;
};