#include "EditorScene.h"

namespace Editor
{
	using namespace BF;
	using namespace BF::Math;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;

	EditorScene::EditorScene() :
		tilesheet(*this), scenePanel(*this, tilesheet)
	{
	}

	EditorScene::~EditorScene()
	{
	}

	void EditorScene::Initialize()
	{
		Scene::Initialize();
		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	}

	void EditorScene::Load()
	{
		Scene::Load();
	}

	void EditorScene::FixedUpdate()
	{
	}

	void EditorScene::Update()
	{
		Scene::Update();
		camera.Update();
	}

	void EditorScene::Render()
	{
		Engine::GetContext().Clear(Color(0.5f, 0.0f, 0.1f, 1.0f));
		Scene::Render();
		scenePanel.RenderTileMap();
		Engine::GetContext().SwapBuffers();
	}
}