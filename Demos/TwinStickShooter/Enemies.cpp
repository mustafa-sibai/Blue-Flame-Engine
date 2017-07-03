#include "Enemies.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;

Enemies::Enemies(SpriteRenderer& spriteRenderer, Player& player) :
	spriteRenderer(spriteRenderer), player(player)
{
}

Enemies::~Enemies()
{
}

void Enemies::Spawn()
{
	int randW, randH;

	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	randW = rand() % 1920;
	randH = rand() % 1080;


	Vector2 position((float)randW, (float)randH);

	enemies.push_back(Enemy(spriteRenderer, player));
	enemies[enemies.size() - 1].Initialize(position);
	enemies[enemies.size() - 1].Load();
}

void Enemies::Update()
{
	for (size_t i = 0; i < enemies.size(); i++)
		enemies[i].Update();
}

void Enemies::Render()
{
	for (size_t i = 0; i < enemies.size(); i++)
		enemies[i].Render();
}