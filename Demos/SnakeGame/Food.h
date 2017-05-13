#pragma once
#include "BF/BlueFlame.h"

class Food
{
private:
	BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;
	BF::Graphics::Renderers::RegularPolygon food;
	BF::Math::Rectangle rectangle;

public:
	Food(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);
	~Food();

	void Initialize();
	void Load();
	void Update();
	void Render();

	void GenerateRandomPosition();

	inline const BF::Math::Rectangle& GetRectangle() const { return rectangle; }
};