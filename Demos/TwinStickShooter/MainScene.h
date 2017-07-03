#pragma once
#include <BF/BlueFlame.h>
#include "Player.h"
#include "Enemies.h"

class MainScene : public BF::Application::Scene
{
	private:
		BF::Graphics::Camera camera;
		BF::Graphics::Renderers::SpriteRenderer spriteRenderer;

		Player player;
		Enemies enemies;

	public:
		MainScene();
		~MainScene();

	private:
		void Initialize() override;
		void Load() override;
		void Update() override;
		void Render() override;
};