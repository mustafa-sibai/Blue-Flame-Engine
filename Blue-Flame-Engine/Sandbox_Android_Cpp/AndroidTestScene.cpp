#include "AndroidTestScene.h"
#include "BF/Engine.h"
#include "BF/Graphics/Color.h"

AndroidTestScene::AndroidTestScene()
{
	BFE_LOG_INFO("AndroidTestScene");
}

AndroidTestScene::~AndroidTestScene()
{
}

void AndroidTestScene::Initialize()
{
	BFE_LOG_INFO("Initialize");
}

void AndroidTestScene::Load()
{
	BFE_LOG_INFO("Load");
}

void AndroidTestScene::FixedUpdate()
{
	//BFE_LOG_INFO("FixedUpdate");
}

void AndroidTestScene::Update()
{
	//BFE_LOG_INFO("Update");
}

void AndroidTestScene::Render()
{
	BF::Engine::GetContext().Clear(BF::Graphics::Color(0.5, 0.0f, 0.0f, 1.0f));
	BF::Engine::GetContext().SwapBuffers();
	//BFE_LOG_INFO("Render");
}