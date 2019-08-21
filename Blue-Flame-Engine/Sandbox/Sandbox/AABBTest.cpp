#include "AABBTest.h"
#include "ScriptTest.h"

namespace AABBTest
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::Graphics::Renderers::SpriteRendererComponents;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;
	using namespace BF::IO;
	using namespace BF::Physics;

	AABBTest::AABBTest()
	{
	}

	AABBTest::~AABBTest()
	{
	}

	void AABBTest::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		defaultRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.GetDefaultRenderLayer();
		spriteRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.AddRenderLayer(new RenderLayer("Sprites", RenderLayer::SortingOrder::BackToFrontRightToLeft));
		guiRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.AddRenderLayer(new RenderLayer("GUI", RenderLayer::SortingOrder::BackToFrontRightToLeft));

		GameObject* CameraGameObject = scene->AddGameObject(new GameObject("Camera"));

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		Texture2D* green = new Texture2D();
		green->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/g.png"));

		Texture2D* red = new Texture2D();
		red->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/r.png"));

		sprite = scene->AddGameObject(new GameObject("sprite"));
		sprite->AddComponent(new Sprite(red, Vector2f(0.0f, 0.0f), defaultRenderLayer));
		r = (Rigidbody2D*)sprite->AddComponent(new Rigidbody2D());
		sprite->AddComponent(new BoxCollider2D(0, 0, 32, 32, Vector2f(0, 0)));
		sprite->AddComponent(new ScriptTest());

		sprite->GetComponent<Transform>()->SetPosition(Vector3f(0, 0, 0));

		GameObject* sprite2 = scene->AddGameObject(new GameObject("sprite2"));
		sprite2->AddComponent(new Sprite(green, Vector2f(0.0f, 0.0f), defaultRenderLayer));
		sprite2->AddComponent(new BoxCollider2D(0, 0, 32, 32, Vector2f(0, 0)));
		//sprite2->AddComponent(new ScriptTest());
		sprite2->GetComponent<Transform>()->SetPosition(Vector3f(100, 0, 0));

		App::Initialize();
	}

	void AABBTest::Load()
	{
		App::Load();
	}

	void AABBTest::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void AABBTest::Update(double deltaTime)
	{
		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));

		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::W))
		{
			direction = Vector3f(direction.x, 1, direction.z);
		}

		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::S))
		{
			direction = Vector3f(direction.x, -1, direction.z);
		}

		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::D))
		{
			direction = Vector3f(1, direction.y, direction.z);
		}

		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::A))
		{
			direction = Vector3f(-1, direction.y, direction.z);
		}
	
		sprite->GetComponent<Transform>()->SetPosition(sprite->GetComponent<Transform>()->GetPosition() + (direction * speed * deltaTime));
		direction = Vector3f(0, 0, 0);

		App::Update(deltaTime);
	}

	void AABBTest::Render()
	{
		App::Render();
	}
}