#include "EditorScene.h"

namespace Editor
{
	using namespace BF;
	using namespace BF::Math;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;

	EditorScene::EditorScene() :
		grid(spriteRenderer), paintTile(spriteRenderer, grid, tilemap), texture(spriteRenderer.GetShader())
	{
	}

	EditorScene::~EditorScene()
	{
	}

	void EditorScene::Initialize()
	{
		spriteRenderer.Initialize();
		tilemap.Initialize();
		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	}

	void EditorScene::Load()
	{
		texture.Load("../Sandbox/Assets/Textures/tilea5.png");
		paintTile.SetCurrentTile(Sprite(&texture, Vector2(0.0f, 0.0f), 0, Color(1.0f)));
	}

	void EditorScene::FixedUpdate()
	{
	}

	void EditorScene::Update()
	{
		camera.Update();
		paintTile.Update();
	}

	void EditorScene::Render()
	{
		Engine::GetContext().Clear(Color(0.5f, 0.0f, 0.1f, 1.0f));

		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::None);
		grid.Render();
		paintTile.Render();
		spriteRenderer.End();

		tilemap.Render();

		Engine::GetContext().SwapBuffers();
	}
}