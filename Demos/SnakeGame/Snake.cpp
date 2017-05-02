#include "Snake.h"

using namespace BF;
using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Snake::Snake(Food& food) :
	food(food), deltaTime(0.0f)
{
	step = 32.0f;
}

Snake::~Snake()
{
}

void Snake::Initialize()
{
	rectangle = Math::Rectangle(0, 0, 32, 32);
	snakeHeads.push_back(Renderers::RegularPolygon(rectangle, 0, Color(0.0f, 0.0f, 1.0f, 1.0f)));
}

void Snake::Load()
{
}

void Snake::Update()
{
	if (Keyboard::IsKeyPressed(Keyboard::Key::D) && movmentDirection != Vector2(-1.0f, 0.0f))
		movmentDirection = Vector2(1.0f, 0.0f);
	else if (Keyboard::IsKeyPressed(Keyboard::Key::A) && movmentDirection != Vector2(1.0f, 0.0f))
		movmentDirection = Vector2(-1.0f, 0.0f);
	else if (Keyboard::IsKeyPressed(Keyboard::Key::W) && movmentDirection != Vector2(0.0f, 1.0f))
		movmentDirection = Vector2(0.0f, -1.0f);
	else if (Keyboard::IsKeyPressed(Keyboard::Key::S) && movmentDirection != Vector2(0.0f, -1.0f))
		movmentDirection = Vector2(0.0f, 1.0f);

	deltaTime += Engine::GetDeltaTime();

	if (deltaTime >= 100.0f)
	{
		for (size_t i = 0; i < snakeHeads.size(); i++)
		{
			snakeHeads[i].SetPosition(snakeHeads[i].GetPosition() + (movmentDirection * step));
		}

		deltaTime = 0.0f;
	}

	rectangle.x = snakeHeads[0].GetPosition().x;
	rectangle.y = snakeHeads[0].GetPosition().y;

	if (rectangle.Intersect(food.GetRectangle()))
	{
		BF::Math::Rectangle rec = BF::Math::Rectangle(
			snakeHeads[snakeHeads.size() - 1].GetPosition().x + (-movmentDirection.x * rectangle.width),
			snakeHeads[snakeHeads.size() - 1].GetPosition().y + (-movmentDirection.y * rectangle.height),
			rectangle.width, rectangle.height);

		snakeHeads.push_back(Renderers::RegularPolygon(rec, 0, Color(0.0f, 0.0f, 1.0f, 1.0f)));
		food.GenerateRandomPosition();
	}
}

void Snake::Render(SpriteRenderer& spriteRenderer)
{
	for (size_t i = 0; i < snakeHeads.size(); i++)
		spriteRenderer.Render(snakeHeads[i]);
}