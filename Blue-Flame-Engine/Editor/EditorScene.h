#pragma once
#include <BF/BlueFlame.h>
#include "ScenePanel.h"

namespace Editor
{
	class EditorScene : public BF::Application::Scene
	{
	private:
		BF::Graphics::Camera camera;

		TileSheetPanel tilesheet;
		ScenePanel scenePanel;

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