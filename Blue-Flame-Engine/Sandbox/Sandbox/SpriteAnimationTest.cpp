#include "SpriteAnimationTest.h"

namespace SpriteAnimationTest
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::GUI;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Animation;
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

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5, 0.5f));
		BF::Math::Rectangle rect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(rect.x, rect.width, rect.y, rect.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		App::Initialize();
	}

	void SpriteAnimationTest::Load()
	{
		App::Load();
	}

	Sprite* currentSprite;
	SpriteAnimationData data;

	void SpriteAnimationTest::PostLoad()
	{
		App::PostLoad();

		GameObject* playerGameObject = scene->AddGameObject(new GameObject("player"));

		data.textureName = "../Sandbox/Assets/Textures/player.png";
		data.filePath = "../Sandbox/Assets/Textures/player.png";

		for (size_t i = 0; i < 8; i++)
			data.keyFrames.emplace_back(KeyFrame(100 * (i + 1), BF::Math::Rectangle(32 * i, 0, 32, 48)));

		SpriteAnimator * animator = (SpriteAnimator*)playerGameObject->AddComponent(new SpriteAnimator(&data, true));
		animator->gameObject->GetTransform()->SetScale(Vector3f(3, 3, 3));

		App::RunScene(*scene);
	}

	void SpriteAnimationTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5, 0.5f));
		BF::Math::Rectangle rect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(rect.x, rect.width, rect.y, rect.height, -1.0f, 1.0f));
	}

	void SpriteAnimationTest::Render()
	{
		App::Render();
	}
}