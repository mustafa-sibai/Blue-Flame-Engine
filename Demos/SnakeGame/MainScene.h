#pragma once
#include "BF/BlueFlame.h"

class MainScene : public BF::Application::Scene
{
private:
	BF::Graphics::Camera camera;
	BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
	BF::Graphics::Renderers::RegularPolygon rectangle;

public:
	MainScene();
	~MainScene();

private:
	void Initialize() override;
	void Load() override;
	void FixedUpdate() override;
	void Update() override;
	void Render() override;
};