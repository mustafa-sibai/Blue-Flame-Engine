#include "Ball.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Ball::Ball(SpriteRenderer& spriteRenderer, Player& player) :
	spriteRenderer(spriteRenderer), player(player), xVelocity(5.0f), yVelocity(5.0f)
{
}

Ball::~Ball()
{

}

void Ball::Initialize()
{
	ballPosition = Vector2((Engine::GetWindow().GetClientWidth() / 2) - 8, (Engine::GetWindow().GetClientHeight() / 2) - 8);
	ball = RegularPolygon(Math::Rectangle((int)ballPosition.x, (int)ballPosition.y, 16, 16), 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
}

void Ball::Load()
{

}

void Ball::Update()
{
	if (ballPosition.x > Engine::GetWindow().GetClientWidth() - ball.GetRectangle().width)
		xVelocity *= -1;

	if (ballPosition.y > Engine::GetWindow().GetClientHeight() - ball.GetRectangle().height ||
		ballPosition.y < ball.GetRectangle().height)
		yVelocity *= -1;

	ballPosition += Vector2(xVelocity, yVelocity);
	ball.SetPosition(ballPosition);

	ballRect = ball.GetRectangle();

	if (ballRect.Intersect(player.GetRectangle()))
		xVelocity *= -1;
}

void Ball::Render()
{
	spriteRenderer.Render(ball);
}