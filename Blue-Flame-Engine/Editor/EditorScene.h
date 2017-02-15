#pragma once
#include <BF/BlueFlame.h>
#include "PaintTile.h"
#include "Grid.h"
#include "TileMap.h"

namespace Editor
{
	class EditorScene : public BF::Application::Scene
	{
	private:
		BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
		BF::Graphics::Camera camera;

		BF::Graphics::API::Texture2D texture;

		Grid grid;
		PaintTile paintTile;
		Editor::TileMap tilemap;

	public:
		EditorScene();
		~EditorScene();

		void Initialize() override;
		void Load() override;
		void FixedUpdate() override;
		void Update() override;
		void Render() override;
	};
}