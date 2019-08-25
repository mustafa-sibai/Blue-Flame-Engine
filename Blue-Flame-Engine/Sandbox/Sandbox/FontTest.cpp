#include "FontTest.h"
#include "ScriptTest.h"
#include "BF/IO/ResourceManager.h"
#include "BF/IO/BFFLoader.h"

namespace FontTest
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

	FontTest::FontTest()
	{
	}

	FontTest::~FontTest()
	{
	}

	void FontTest::Initialize()
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

		BF::IO::BFFLoader BFFLoader;
		BF::Graphics::Fonts::Font* font = BFFLoader.Load("../Sandbox/Assets/Fonts/Arial.bff");

		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/cube - Copy.png"));

	/*	GameObject* sprite = scene->AddGameObject(new GameObject("main"));
		sprite->AddComponent(new Sprite(texture, Vector2f(0.0f, 0.0f), defaultRenderLayer));
		sprite->GetComponent<Transform>()->SetPosition(Vector3f(0, 0, 0));*/

		/*Texture2D* texture2 = new Texture2D();
		texture2->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/test3.png"));

		GameObject* sprite2 = scene->AddGameObject(new GameObject("main"));
		sprite2->AddComponent(new Sprite(texture2, Vector2f(0.5f, 0.5f), defaultRenderLayer));
		sprite2->GetComponent<Transform>()->SetPosition(Vector3f(0, 0, 0));*/


		/*GameObject* rect = scene->AddGameObject(new GameObject("main"));
		rect->AddComponent(new RegularPolygon(Vector2i(9, 10), Vector2f(0.5f, 0.5f), defaultRenderLayer));
		rect->GetComponent<Transform>()->SetPosition(Vector3f(0, 0, 0));*/

		/*GameObject* text = scene->AddGameObject(new GameObject("main"));
		text->AddComponent(new Text(font, "Hello world!", Vector2f(.5f, .5f), defaultRenderLayer));
		text->GetComponent<Transform>()->SetScale(Vector3f(2, 2, 2));
		text->GetComponent<Transform>()->SetPosition(Vector3f(-100, 50, 0));*/

		App::Initialize();
	}

	void FontTest::Load()
	{
		App::Load();
	}

	void FontTest::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void FontTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));
	}

	void FontTest::Render()
	{
		App::Render();
	}
}