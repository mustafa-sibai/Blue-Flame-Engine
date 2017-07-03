#include "Player.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Player::Player(SpriteRenderer& spriteRenderer) :
	spriteRenderer(spriteRenderer), speed(10.0f)
{
}

Player::~Player()
{

}

void Player::Initialize()
{
	player = RegularPolygon(Math::Rectangle(0, 0, 32, 128), 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
}

void Player::Load()
{

}

void Player::Update()
{
	if (Keyboard::IsKeyDown(Keyboard::Key::Code::DownArrow))
		playerPosition.y += speed;

	if (Keyboard::IsKeyDown(Keyboard::Key::Code::UpArrow))
		playerPosition.y -= speed;

	playerPosition.y = Clamp(playerPosition.y, 0.0f, (float)Engine::GetWindow().GetClientHeight() - 128.0f);
	player.SetPosition(playerPosition);
}

void Player::Render()
{
	spriteRenderer.Render(player);
}