#include "PhysicsScene.h"

namespace PhysicsScene
{
	using namespace BF;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;

	PhysicsScene::PhysicsScene() : 
		floorRigidbody2D(floor), boxRigidbody2D(box)
	{
	}

	PhysicsScene::~PhysicsScene()
	{
	}

	void PhysicsScene::Initialize()
	{
		//Engine::LimitFrameRate(0);
		//Engine::GetContext().EnableVsync(false);
		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		spriteRenderer.Initialize();
	}

	void PhysicsScene::Load()
	{
		floor = RegularPolygon(Math::Rectangle(64, Engine::GetWindow().GetClientHeight() - 128, Engine::GetWindow().GetClientWidth() - 128, 74), 0, Color(0.0f, 0.0f, 1.0f, 1.0f));
		box = RegularPolygon(Math::Rectangle((Engine::GetWindow().GetClientWidth() / 2) - 64, 64, 64, 64), 1, Color(1.0f, 1.0f, 1.0f, 1.0f));
		
		//floor = RegularPolygon(Math::Rectangle(64, 96, 512, 480), 0, Color(0.0f, 0.0f, 1.0f, 1.0f));
		//box = RegularPolygon(Math::Rectangle(128, 20, 256, 352), 1, Color(1.0f, 1.0f, 1.0f, 1.0f));

		Math::Rectangle r = box.GetRectangle().IntersectRectangle(floor.GetRectangle());
		BF_LOG_INFO(r);

		boxRigidbody2D.useGravity = true;
		floorRigidbody2D.useGravity = false;

		BF::Physics::PhysicsEngine::Add(&floorRigidbody2D);
		BF::Physics::PhysicsEngine::Add(&boxRigidbody2D);
	}

	void PhysicsScene::Update()
	{
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		camera.Update();

		BF::Physics::PhysicsEngine::Update();
	}

	void PhysicsScene::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));

		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);
		spriteRenderer.Render(floor);
		spriteRenderer.Render(box);
		spriteRenderer.End();

		BF::Engine::GetContext().SwapBuffers();
	}
}