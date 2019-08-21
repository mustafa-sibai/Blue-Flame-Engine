#include "SpriteRendererTest.h"

namespace SpriteRendererTest
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
	//using namespace BF::Debugging;

	SpriteRendererTest::SpriteRendererTest()
	{
	}

	SpriteRendererTest::~SpriteRendererTest()
	{
	}

	void SpriteRendererTest::Initialize()
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

		/*GameObject* sprite = scene->AddGameObject(new GameObject("sprite"));
		sprite->AddComponent(new Sprite(red, Vector2f(0.0f, 0.0f), defaultRenderLayer));
		sprite->GetComponent<Transform>()->SetPosition(Vector3f(0, 0, 0));*/

		App::Initialize();
	}

	void SpriteRendererTest::Load()
	{
		App::Load();
	}

	void SpriteRendererTest::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void SpriteRendererTest::Update(double deltaTime)
	{
		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();
		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));

		App::Update(deltaTime);
	}

	void SpriteRendererTest::Render()
	{
		App::Render();
	}
}