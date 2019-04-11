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

	void SpriteAnimationTest::PostLoad()
	{
		App::PostLoad();

		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/player.png"), Texture::Format::R8G8B8A8);

		GameObject* playerGameObject = scene->AddGameObject(new GameObject("player"));
		currentSprite = (Sprite*)playerGameObject->AddComponent(new Sprite(texture, Vector2f(0.5f, 0.5f), 0,
			*defaultRenderLayer, BF::Math::Rectangle(0, 0, 32, 48), Color::Whites::White()));
		currentSprite->gameObject->GetTransform()->SetScale(Vector3f(2, 2, 2));


		App::RunScene(*scene);
	}
	float time = 0;
	int maxIndex = 7;
	int i = 0;

	void SpriteAnimationTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5, 0.5f));
		BF::Math::Rectangle rect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(rect.x, rect.width, rect.y, rect.height, -1.0f, 1.0f));

		time += deltaTime;

		if (time >= 100)
		{
			currentSprite->SetScissorRectangle(BF::Math::Rectangle(32 * i, 0, 32, 48));
			i++;
			time = 0;

			if (i > 7)
				i = 0;
		}
		BFE_LOG_INFO(std::to_string(time), "");
	}

	void SpriteAnimationTest::Render()
	{
		App::Render();
	}
}