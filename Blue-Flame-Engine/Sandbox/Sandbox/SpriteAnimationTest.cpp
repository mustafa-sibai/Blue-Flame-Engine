#include "SpriteAnimationTest.h"

namespace SpriteAnimationTest
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::GUI;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::Graphics::Renderers::SpriteRendererComponents;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;
	using namespace BF::IO;

	SpriteAnimationTest::SpriteAnimationTest()
	{
	}

	SpriteAnimationTest::~SpriteAnimationTest()
	{
	}

	void SpriteAnimationTest::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		defaultRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.GetDefaultRenderLayer();
		spriteRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.AddRenderLayer(new RenderLayer("Sprites", RenderLayer::SortingOrder::BackToFrontRightToLeft));

		GameObject* CameraGameObject = scene->AddGameObject(new GameObject("Camera"));

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y);
		orthographicRectangle.SetPivotPoint(Vector2f(0.5, 0.5f));
		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(orthographicRectangle.x, orthographicRectangle.width, orthographicRectangle.y, orthographicRectangle.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		App::Initialize();
	}

	void SpriteAnimationTest::Load()
	{
		App::Load();
	}

	void SpriteAnimationTest::PostLoad()
	{
		App::PostLoad();

		App::RunScene(*scene);
	}

	void SpriteAnimationTest::Update()
	{
		App::Update();

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y);
		orthographicRectangle.SetPivotPoint(Vector2f(0.5, 0.5f));

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthographicRectangle.x, orthographicRectangle.width, orthographicRectangle.y, orthographicRectangle.height, -1.0f, 1.0f));
	}

	void SpriteAnimationTest::Render()
	{
		App::Render();
	}
}