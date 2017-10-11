#include "HUD.h"

using namespace BF;
using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Graphics::Fonts;
using namespace BF::Math;
using namespace BF::Input;

HUD::HUD(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, const Snake& snake) :
	spriteRenderer(spriteRenderer), font(spriteRenderer.GetShader()), snake(snake)
{

}

HUD::~HUD()
{
}

void HUD::Initialize()
{

}

void HUD::Load()
{
	font.Load("Assets/Fonts/arial.ttf", 50, FontAtlasFactory::Language::English);
	
}

void HUD::Update()
{
	scoreText = "Score: " + std::to_string(snake.GetScore());
	text = Text(&font, scoreText, Vector2(), 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
}

void HUD::Render()
{
	spriteRenderer.Render(text);
}