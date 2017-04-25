#include "MainScene.h"

using namespace BF;
using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;

MainScene::MainScene()
{
	//BF::Graphics::Camera camera;
	//BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
}

MainScene::~MainScene()
{
}

void MainScene::Initialize()
{
	camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	spriteRenderer.Initialize();

	rectangle = Renderers::RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color(0.0f, 0.0f, 1.0f, 1.0f));
}

void MainScene::Load()
{
}

void MainScene::FixedUpdate()
{
}

void MainScene::Update()
{
	camera.Update();
}

void MainScene::Render()
{
	Engine::GetContext().Clear(Color(0.75f, 0.0f, 0.0f, 1.0f));
	spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::Null);
	spriteRenderer.Render(rectangle);
	spriteRenderer.End();
	Engine::GetContext().SwapBuffers();
}