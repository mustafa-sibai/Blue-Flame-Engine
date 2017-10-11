#pragma once
#include <BF/BlueFlame.h>

class Player
{
	private:
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;

		BF::Graphics::Renderers::RegularPolygon player;
		BF::Math::Vector2 playerPosition;
		float speed;

	public:
		Player(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);
		~Player();

		void Initialize();
		void Load();
		void Update();
		void Render();

		inline const BF::Math::Rectangle& GetRectangle() const { return player.GetRectangle(); }
};