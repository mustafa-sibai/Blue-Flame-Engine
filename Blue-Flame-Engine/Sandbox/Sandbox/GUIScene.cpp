#include "GUIScene.h"


namespace GUIScene
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::GUI;
	using namespace BF::Math;
	using namespace BF::System;

	GUIScene::GUIScene() :
		button(*this), label(*this)
	{
	}

	GUIScene::~GUIScene()
	{
	}

	void GUIScene::Initialize()
	{
		Scene::Initialize();

		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		//spriteRenderer.Initialize();

		//button.SetRectangle(BF::Math::Rectangle(700, 100, 300, 300));
		//button.SetZLayer(0);

	}

	void GUIScene::Load()
	{
		Scene::Load();
	}

	void GUIScene::Update()
	{
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		Scene::Update();
		camera.Update();
	}

	void GUIScene::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));
		Scene::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}
