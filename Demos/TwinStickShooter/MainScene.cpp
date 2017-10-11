#include "MainScene.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::Input;

MainScene::MainScene() : 
	player(spriteRenderer, enemies), enemies(spriteRenderer, player)
{
}

MainScene::~MainScene()
{
}

void MainScene::Initialize()
{
	camera.Initialize(Matrix4::Orthographic(0, Engine::GetWindow().GetClientWidth(), 0, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	spriteRenderer.Initialize();

	player.Initialize();
	enemies.Spawn();
}

void MainScene::Load() 
{
}

void MainScene::Update() 
{
	camera.Update();

	player.Update();
	enemies.Update();
}

void MainScene::Render()
{
	Engine::GetContext().Clear(Color(0.0f, 0.0f, 0.0f, 1.0f));
	
	spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::Null);
	player.Render();
	enemies.Render();
	spriteRenderer.End();

	Engine::GetContext().SwapBuffers();
}