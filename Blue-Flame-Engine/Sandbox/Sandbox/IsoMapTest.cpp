#include "IsoMapTest.h"
#include "ScriptTest.h"

namespace IsoMapTest
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

	IsoMapTest::IsoMapTest()
	{
	}

	IsoMapTest::~IsoMapTest()
	{
	}

	void IsoMapTest::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		/*GameObject* parent = scene->AddGameObject(new GameObject(*scene, "parent"));
		parent->GetTransform()->SetPosition(Vector3f(100, 100, 100));
		parent->GetTransform()->SetScale(Vector3f(0.5, 0.5, 0.5));*/

		GameObject* CameraGameObject = scene->AddGameObject(new GameObject("Camera"));

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y);
		orthographicRectangle.SetPivotPoint(Vector2f(0.5, 0.5f));
		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(orthographicRectangle.x, orthographicRectangle.width, orthographicRectangle.y, orthographicRectangle.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		/*Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/test.png"), Texture::Format::R8G8B8A8, Texture::Wrap::ClampToEdge, Texture::Filter::Point);

		GameObject* sprite = scene->AddGameObject(new GameObject("main"));
		sprite->AddComponent(new Sprite(texture, Vector2f(0.5f, 0.5f)));
		sprite->GetTransform()->SetPosition(Vector3f(0, 0, 0));*/

		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/grass_test.png"), Texture::Format::R8G8B8A8);

		GameObject* sprite;
		int row = 10;
		for (size_t y = 0; y < 10; y++)
		{
			for (size_t x = 0; x < row; x++)
			{
				sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));
				int xx = ((texture->GetTextureData()->width / 2) * (x + y));
				int yy = ((texture->GetTextureData()->width / 4) * x) - ((texture->GetTextureData()->width / 4) * y);

				sprite->GetTransform()->SetPosition(Vector3f(xx - 500, yy - 200, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = xx + yy * row;
				sprite->GetComponent<Sprite>()->xySortingOrder = xx + yy * row;
				sprite->GetComponent<Sprite>()->zSortingOrder = 0;

				//if (y % 2 == 0)
					//sprite->GetComponent<Sprite>()->color = Color::Yellows::Yellow();
			}
		}

		App::Initialize();
	}

	void IsoMapTest::Load()
	{
		App::Load();
	}

	void IsoMapTest::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void IsoMapTest::Update()
	{
		App::Update();

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y);
		orthographicRectangle.SetPivotPoint(Vector2f(0.5, 0.5f));

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthographicRectangle.x, orthographicRectangle.width, orthographicRectangle.y, orthographicRectangle.height, -1.0f, 1.0f));
	}

	void IsoMapTest::Render()
	{
		App::Render();
	}
}