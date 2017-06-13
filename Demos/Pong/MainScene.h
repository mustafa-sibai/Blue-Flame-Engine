#pragma once
#include <BF/BlueFlame.h>
#include "Player.h"
#include "Ball.h"

class MainScene : public BF::Application::Scene
{
	private:
		BF::Graphics::Camera camera;
		BF::Graphics::Renderers::SpriteRenderer spriteRenderer;

		Player player;
		Ball ball;

	public:
		MainScene();
		~MainScene();

	private:
		void Initialize() override;
		void Load() override;
		void Update() override;
		void Render() override;
};