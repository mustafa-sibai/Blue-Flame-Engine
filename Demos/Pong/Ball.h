#pragma once
#include <BF/BlueFlame.h>
#include "Player.h"

class Ball
{
	private:
		Player& player;
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;

		BF::Graphics::Renderers::RegularPolygon ball;
		BF::Math::Rectangle ballRect;
		BF::Math::Vector2 ballPosition;
		float xVelocity, yVelocity;

	public:
		Ball(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, Player& player);
		~Ball();

		void Initialize();
		void Load();
		void Update();
		void Render();
};