#pragma once
#include "BF/BlueFlame.h"
#include "Food.h"

class Snake
{
private:
	BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;
	std::vector<BF::Graphics::Renderers::RegularPolygon> snakeHeads;
	BF::Math::Rectangle rectangle;
	BF::Math::Vector2 movmentDirection;
	Food& food;

	float step;
	double deltaTime;
	unsigned int score;

	BF::Math::Vector2 currentPosition;
	BF::Math::Vector2 previousPosition;

public:
	Snake(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, Food& food);
	~Snake();

	void Initialize();
	void Load();
	void Update();
	void Render();

	inline unsigned int GetScore() const { return score; }
};