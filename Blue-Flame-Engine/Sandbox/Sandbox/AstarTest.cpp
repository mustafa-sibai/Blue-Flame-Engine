#include "AstarTest.h"

namespace AstarTest
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

	AstarTest::AstarTest()
	{
	}

	AstarTest::~AstarTest()
	{
	}

	void AstarTest::Initialize()
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
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		App::Initialize();
	}

	void AstarTest::Load()
	{
		App::Load();

		startingNodeTexture = new Texture2D();
		startingNodeTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/startingNode.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);

		endNodeTexture = new Texture2D();
		endNodeTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/endNode.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);

		nodeTexture = new Texture2D();
		nodeTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/node.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);
	}

	void AstarTest::PostLoad()
	{
		App::PostLoad();

		GameObject* startingNodeGameObject = scene->AddGameObject(new GameObject("Starting Node"));
		startingNodeGameObject->AddComponent(new Sprite(startingNodeTexture, Vector2f(0.5, 0.5), defaultRenderLayer));
		startingNodeGameObject->GetTransform()->SetPosition(Vector3f(-500, 200, 0));

		GameObject* endNodeGameObject = scene->AddGameObject(new GameObject("end Node"));
		endNodeGameObject->AddComponent(new Sprite(endNodeTexture, Vector2f(0.5, 0.5), defaultRenderLayer));
		endNodeGameObject->GetTransform()->SetPosition(Vector3f(400, -250, 0));




		GameObject* lineGameObject = scene->AddGameObject(new GameObject("Starting Node"));
		lineGameObject->AddComponent(new LineShape(Vector2f(-500, 200), Vector2f(400, -250), defaultRenderLayer));
		lineGameObject->GetTransform()->SetPosition(Vector3f(0, 0, 0));

		App::RunScene(*scene);
	}

	void AstarTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));

		BF::Math::Vector2f mousePosition = BF::Input::Mouse::GetPosition();

		BF::Math::Vector3f newPos = camera->ScreenToWorldPoint(Vector3f(mousePosition.x, mousePosition.y, 0), Vector2f(0.5f, 0.5f));
	}

	void AstarTest::Render()
	{
		App::Render();
	}
}