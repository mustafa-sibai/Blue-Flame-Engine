#include "AndroidTestScene.h"
#include "BF/Engine.h"

AndroidTestScene::AndroidTestScene()
{
	BF_LOG_INFO("AndroidTestScene");
}

AndroidTestScene::~AndroidTestScene()
{
}

void AndroidTestScene::Initialize()
{
	BF_LOG_INFO("Initialize");
}

void AndroidTestScene::Load()
{
	BF_LOG_INFO("Load");
}

void AndroidTestScene::FixedUpdate()
{
	//BF_LOG_INFO("FixedUpdate");
}

void AndroidTestScene::Update()
{
	//BF_LOG_INFO("Update");
}

void AndroidTestScene::Render()
{
	BF::Engine::GetContext().Clear(BF::Math::Vector4(0.5, 0.0f, 0.0f, 1.0f));
	BF::Engine::GetContext().SwapBuffers();
	//BF_LOG_INFO("Render");
}