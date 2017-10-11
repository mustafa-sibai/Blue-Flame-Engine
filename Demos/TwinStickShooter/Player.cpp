#include "Player.h"
#include "Enemies.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Player::Player(SpriteRenderer& spriteRenderer, Enemies& enemies) :
	spriteRenderer(spriteRenderer), enemies(enemies), speed(10.0f)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	player = RegularPolygon(Math::Rectangle(960 - 16, 540 - 16, 32, 32), 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
	playerPosition = player.GetPosition();
}

void Player::Load()
{
}

void Player::Update()
{
	if (Keyboard::IsKeyDown(Keyboard::Key::Code::D))
		playerPosition.x += speed;

	else if (Keyboard::IsKeyDown(Keyboard::Key::Code::A))
		playerPosition.x -= speed;

	if (Keyboard::IsKeyDown(Keyboard::Key::Code::W))
		playerPosition.y -= speed;

	else if (Keyboard::IsKeyDown(Keyboard::Key::Code::S))
		playerPosition.y += speed;

	if (Mouse::IsButtonPressed(Mouse::Button::Left))
	{
		bullets.push_back(Bullet(spriteRenderer));
		bullets[bullets.size() - 1].Initialize();
		bullets[bullets.size() - 1].Load();
		bullets[bullets.size() - 1].position = playerPosition;
		bullets[bullets.size() - 1].direction = (Mouse::GetPosition() - playerPosition).Normalize();
	}

	playerPosition.y = Clamp(playerPosition.y, 0.0f, (float)Engine::GetWindow().GetClientHeight() - 128.0f);
	player.SetPosition(playerPosition);


	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update();

		if (enemies.GetEnemies()[0].GetRectangle().Intersect(bullets[i].GetRectangle()))
			bullets.erase(bullets.begin() + i);
	}
}

void Player::Render()
{
	spriteRenderer.Render(player);

	for (size_t i = 0; i < bullets.size(); i++)
		bullets[i].Render();
}