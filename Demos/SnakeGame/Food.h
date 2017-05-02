#pragma once
#include "BF/BlueFlame.h"

class Food
{
private:
	BF::Graphics::Renderers::RegularPolygon food;
	BF::Math::Rectangle rectangle;

public:
	Food();
	~Food();

	void Initialize();
	void Load();
	void Update();
	void Render(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);

	void GenerateRandomPosition();

	inline const BF::Math::Rectangle& GetRectangle() const { return rectangle; }
};