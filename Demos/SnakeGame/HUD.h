#pragma once
#include "BF/BlueFlame.h"
#include "BF/Graphics/Renderers/SpriteRenderer/Text.h"
#include "Snake.h"

class HUD
{
private:
	BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;
	BF::Graphics::Fonts::Font font;
	BF::Graphics::Renderers::Text text;

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