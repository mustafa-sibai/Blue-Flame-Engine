#include "CameraViewCullingTest.h"

namespace CameraViewCullingTest
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

	CameraViewCullingTest::CameraViewCullingTest()
	{
	}

	CameraViewCullingTest::~CameraViewCullingTest()
	{
	}

	void CameraViewCullingTest::Initialize()
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
		BF::Math::Rectangle newRect = orthographicRectangle.GetEdgeOffset();
		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(Vector2f(newRect.x, newRect.y), Vector2f(newRect.width, newRect.height), -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		App::Initialize();
	}

	void CameraViewCullingTest::Load()
	{
		App::Load();
	}

	void CameraViewCullingTest::PostLoad()
	{
		App::PostLoad();

		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/g.png"), Texture::Format::R8G8B8A8);

		Texture2D* texture2 = new Texture2D();
		texture2->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/cube.png"), Texture::Format::R8G8B8A8);

		Texture2D* texture3 = new Texture2D();
		texture3->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/point.png"), Texture::Format::R8G8B8A8);

		GameObject* g = scene->AddGameObject(new GameObject("main"));
		sprite = (Sprite*)g->AddComponent(new Sprite(texture, Vector2f(0.0f, 0.0f), 6, *defaultRenderLayer));

		GameObject* g2 = scene->AddGameObject(new GameObject("main2"));
		sprite2 = (Sprite*)g2->AddComponent(new Sprite(texture2, Vector2f(1.0f, 1.0f), 5, *defaultRenderLayer));
		sprite2->gameObject->GetTransform()->SetPosition(Vector3f(0, 0, 0));

		GameObject* X = scene->AddGameObject(new GameObject("X"));
		pointX = (Sprite*)X->AddComponent(new Sprite(texture3, Vector2f(0.5f, 0.5f), 10, *defaultRenderLayer));

		GameObject* Y = scene->AddGameObject(new GameObject("Y"));
		pointY = (Sprite*)Y->AddComponent(new Sprite(texture3, Vector2f(0.5f, 0.5f), 10, *defaultRenderLayer));

		GameObject* W = scene->AddGameObject(new GameObject("W"));
		pointW = (Sprite*)W->AddComponent(new Sprite(texture3, Vector2f(0.5f, 0.5f), 10, *defaultRenderLayer));

		GameObject* H = scene->AddGameObject(new GameObject("H"));
		pointH = (Sprite*)H->AddComponent(new Sprite(texture3, Vector2f(0.5f, 0.5f), 10, *defaultRenderLayer));

		App::RunScene(*scene);
	}

	void CameraViewCullingTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle newRect = orthographicRectangle.GetEdgeOffset();

		camera->SetProjectionMatrix(Matrix4::Orthographic(Vector2f(newRect.x, newRect.y), Vector2f(newRect.width, newRect.height), -1.0f, 1.0f));
	
		if(BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::D))
			sprite->gameObject->GetTransform()->SetPosition(sprite->gameObject->GetTransform()->GetPosition() + Vector3f(0.2f, 0, 0));
		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::A))
			sprite->gameObject->GetTransform()->SetPosition(sprite->gameObject->GetTransform()->GetPosition() + Vector3f(-0.2f, 0, 0));
		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::W))
			sprite->gameObject->GetTransform()->SetPosition(sprite->gameObject->GetTransform()->GetPosition() + Vector3f(0, 0.2f, 0));
		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::S))
			sprite->gameObject->GetTransform()->SetPosition(sprite->gameObject->GetTransform()->GetPosition() + Vector3f(0, -0.2f, 0));
	

		BF::Math::Rectangle spriteRect = BF::Math::Rectangle(
											sprite->gameObject->GetTransform()->GetPosition().x,
											sprite->gameObject->GetTransform()->GetPosition().y,
											sprite->GetTexture()->GetTextureData()->width,
											sprite->GetTexture()->GetTextureData()->height, sprite->pivot);

		BF::Math::Rectangle spriteRect2 = BF::Math::Rectangle(
											sprite2->gameObject->GetTransform()->GetPosition().x,
											sprite2->gameObject->GetTransform()->GetPosition().y,
											sprite2->GetTexture()->GetTextureData()->width,
											sprite2->GetTexture()->GetTextureData()->height, sprite2->pivot);

		std::vector<Vector2i> corners = spriteRect2.GetCorners();

		pointX->gameObject->GetTransform()->SetPosition(Vector3f(corners[0].x, corners[0].y, 0));
		pointY->gameObject->GetTransform()->SetPosition(Vector3f(corners[1].x, corners[1].y, 0));
		pointW->gameObject->GetTransform()->SetPosition(Vector3f(corners[2].x, corners[2].y, 0));
		pointH->gameObject->GetTransform()->SetPosition(Vector3f(corners[3].x, corners[3].y, 0));

		if (spriteRect.Intersect(spriteRect2))
		{
			BFE_LOG_INFO("IN", "");
		}
	}

	void CameraViewCullingTest::Render()
	{
		App::Render();
	}
}