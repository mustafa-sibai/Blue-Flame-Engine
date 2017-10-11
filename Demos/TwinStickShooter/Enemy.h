#pragma once
#include <BF/BlueFlame.h>
#include "Player.h"

class Enemy
{
	private:
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;

		BF::Graphics::Renderers::RegularPolygon enemy;
		float speed;

		Player& player;

	public:
		BF::Math::Vector2 position;
		BF::Math::Vector2 direction;

	public:
		Enemy(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, Player& player);
		~Enemy();

		void Initialize(BF::Math::Vector2 position);
		void Load();
		void Update();
		void Render();

		inline BF::Math::Rectangle GetRectangle() { return enemy.GetRectangle(); }
};