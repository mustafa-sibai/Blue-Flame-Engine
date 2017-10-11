#include "Bullet.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Bullet::Bullet(SpriteRenderer& spriteRenderer) :
	spriteRenderer(spriteRenderer), speed(10.0f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	bullet = RegularPolygon(Math::Rectangle(0, 0, 8, 8), 0, Color(0.5f, 0.0f, 0.0f, 1.0f));
}

void Bullet::Load()
{
}

void Bullet::Update()
{
	position += direction * speed;
	bullet.SetPosition(position);
}

void Bullet::Render()
{
	spriteRenderer.Render(bullet);
}

Bullet& Bullet::operator=(const Bullet& b)
{
	this->spriteRenderer = b.spriteRenderer;
	this->bullet = b.bullet;
	this->speed = b.speed;
	this->position = b.position;
	this->direction = b.direction;

	return *this;
}