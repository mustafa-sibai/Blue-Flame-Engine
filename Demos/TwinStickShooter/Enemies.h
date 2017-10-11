#pragma once
#include <BF/BlueFlame.h>
#include "Player.h"
#include "Enemy.h"

class Enemies
{
	private:
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;
		std::vector<Enemy> enemies;

		Player& player;

	public:
		Enemies(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, Player& player);
		~Enemies();

		void Spawn();

		void Update();
		void Render();

		inline std::vector<Enemy>& GetEnemies() { return enemies; }
};