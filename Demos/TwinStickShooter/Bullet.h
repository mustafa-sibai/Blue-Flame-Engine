#pragma once
#include <BF/BlueFlame.h>

class Bullet
{
	private:
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;

		BF::Graphics::Renderers::RegularPolygon bullet;
		float speed;

	public:
		BF::Math::Vector2 position;
		BF::Math::Vector2 direction;

	public:
		Bullet(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);
		~Bullet();

		void Initialize();
		void Load();
		void Update();
		void Render();

		Bullet& operator=(const Bullet& bullet);

		inline const BF::Math::Rectangle& GetRectangle() const { return bullet.GetRectangle(); }
};