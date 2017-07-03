#pragma once
#include <BF/BlueFlame.h>
#include "Bullet.h"

class Enemies;

class Player
{
	private:
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;

		BF::Graphics::Renderers::RegularPolygon player;
		BF::Math::Vector2 playerPosition;
		float speed;

		std::vector<Bullet> bullets;
		Enemies& enemies;


	public:
		Player(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, Enemies& enemies);
		~Player();

		void Initialize();
		void Load();
		void Update();
		void Render();

		inline const BF::Math::Rectangle& GetRectangle() const { return player.GetRectangle(); }
		inline const BF::Math::Vector2& GetPosition() const { return playerPosition; }
};