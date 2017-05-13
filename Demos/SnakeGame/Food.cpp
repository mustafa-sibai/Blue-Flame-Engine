#include "Food.h"

using namespace BF;
using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

Food::Food(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer) :
	spriteRenderer(spriteRenderer)
{
	srand(time(NULL));
}

Food::~Food()
{
}

void Food::Initialize()
{
	GenerateRandomPosition();
}

void Food::Load()
{
}

void Food::Update()
{
}

void Food::Render()
{
	spriteRenderer.Render(food);
}

void Food::GenerateRandomPosition()
{
	Vector2 randomPosition = Vector2(rand() % (Engine::GetWindow().GetClientWidth() - 32) + 0, rand() % (Engine::GetWindow().GetClientHeight() - 32) + 0);

	randomPosition = Vector2((int)randomPosition.x / 32, (int)randomPosition.y / 32);
	randomPosition *= 32;

	rectangle = Math::Rectangle((int)randomPosition.x, (int)randomPosition.y, 32, 32);
	food = Renderers::RegularPolygon(rectangle, 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
}