#pragma once
#include "BF/BlueFlame.h"
#include "Food.h"

class Snake
{
private:
	std::vector<BF::Graphics::Renderers::RegularPolygon> snakeHeads;
	BF::Math::Rectangle rectangle;
	BF::Math::Vector2 movmentDirection;
	Food& food;

	float step;
	double deltaTime;

public:
	Snake(Food& food);
	~Snake();

	void Initialize();
	void Load();
	void Update();
	void Render(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);
};