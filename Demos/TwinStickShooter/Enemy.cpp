#include "Enemy.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Enemy::Enemy(SpriteRenderer& spriteRenderer, Player& player) :
	spriteRenderer(spriteRenderer), player(player), speed(2.0f)
{
}

Enemy::~Enemy()
{

}

void Enemy::Initialize(Vector2 position)
{
	this->position = position;

	enemy = RegularPolygon(Math::Rectangle((int)position.x, (int)position.y, 16, 16), 0,
							Color(0.5f, 0.0f, 0.0f, 1.0f));
}

void Enemy::Load()
{

}

void Enemy::Update()
{
	position += (player.GetPosition() - position).Normalize() * speed;
	enemy.SetPosition(position);
}

void Enemy::Render()
{
	spriteRenderer.Render(enemy);
}