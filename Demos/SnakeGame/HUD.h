#pragma once
#include "BF/BlueFlame.h"
#include "Snake.h"

class HUD
{
private:
	BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;
	BF::Graphics::Fonts::Font font;
	BF::Graphics::Fonts::FontAtlas* fontAtlas;

	const Snake& snake;
	std::string scoreText;

public:
	HUD(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, const Snake& snake);
	~HUD();

	void Initialize();
	void Load();
	void Update();
	void Render();
};