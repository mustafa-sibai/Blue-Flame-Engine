#include "MainScene.h"

using namespace BF;
using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

MainScene::MainScene() :
	snake(food)
{
}

MainScene::~MainScene()
{
}

void MainScene::Initialize()
{
	camera.Initialize(Matrix4::Orthographic(0.0f, (float)Engine::GetWindow().GetClientWidth(), 0.0f, (float)Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	spriteRenderer.Initialize();

	snake.Initialize();
	food.Initialize();
}

void MainScene::Load()
{
	snake.Load();
	food.Load();
}

void MainScene::Update()
{
	camera.Update();
	snake.Update();
	food.Update();
}

void MainScene::Render()
{
	Engine::GetContext().Clear(Color(0.0f, 0.0f, 0.0f, 1.0f));
	spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::Null);
	snake.Render(spriteRenderer);
	food.Render(spriteRenderer);
	spriteRenderer.End();
	Engine::GetContext().SwapBuffers();
}