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

		//CreateMap();
		SortingTest();

		App::Initialize();
	}

	Vector2f CartesianToIsometric(Vector2f position)
	{
		return Vector2f(position.x - position.y, -(position.x + position.y) * 0.5f);
	}

	Vector2f IsometricToCartesian(Vector2f position)
	{
		return Vector2f((2 * -position.y + position.x) * 0.5f, (2 * -position.y - position.x) * 0.5f);
	}

	void IsoMapTest::CreateMap()
	{
		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/grass.png"), Texture::Format::R8G8B8A8);

		GameObject* sprite;

		int row = 5;
		int column = 5;
		int height = 11;
		int mostTiles = row > column ? row : column;
		//mostTiles = mostTiles > height ? mostTiles : height;

		float heightInPixels = 15;
		for (size_t z = 0; z < height; z++)
		{
			for (size_t y = 0; y < column; y++)
			{
				for (size_t x = 0; x < row; x++)
				{
					sprite = scene->AddGameObject(new GameObject("main"));
					sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

					Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
					Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

					sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
					sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
					sprite->GetComponent<Sprite>()->zSortingOrder = z;

					if (x == 0 && y == 1)
						sprite->GetComponent<Sprite>()->color = Color::Yellows::Yellow();

					if (z % 2 != 0)
						sprite->GetComponent<Sprite>()->color = Color::Reds::Red();
				}
			}
		}
	}
	Vector2f IsoPosition;
	Vector2f carPosition;
	Vector2f IsoPosition2f;

	void IsoMapTest::SortingTest()
	{
		Texture2D* roadTexture = new Texture2D();
		roadTexture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/road.png"), Texture::Format::R8G8B8A8);

		/*GameObject* movingSprite2 = scene->AddGameObject(new GameObject("main2"));
		movingSprite2->AddComponent(new Sprite(roadTexture, Vector2f(0, 0)));
		movingSprite2->GetTransform()->SetPosition(Vector3f(200, 200, 0));*/

		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/grass.png"), Texture::Format::R8G8B8A8);

		/*GameObject* movingSprite = scene->AddGameObject(new GameObject("main"));
		movingSprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));
		movingSprite->GetTransform()->SetPosition(Vector3f(0, 0, 0));*/


		int row = 7;
		int column = 7;
		int height = 1;
		int mostTiles = row > column ? row : column;
		//mostTiles = mostTiles > height ? mostTiles : height;

		float heightInPixels = 15;

		//ground
		for (size_t z = 0; z < height; z++)
		{
			for (size_t y = 0; y < column; y++)
			{
				for (size_t x = 0; x < row; x++)
				{
					GameObject* sprite = scene->AddGameObject(new GameObject("main"));
					sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

					Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
					Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

					sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
					sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
					sprite->GetComponent<Sprite>()->zSortingOrder = z;

					if (x == 0 && y == 1)
						sprite->GetComponent<Sprite>()->color = Color::Yellows::Yellow();

					if (z % 2 != 0)
						sprite->GetComponent<Sprite>()->color = Color::Reds::Red();
				}
			}
		}

		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//pillerA 1
		{
			int x = 3;
			int y = 0;

			for (size_t z = 0; z < 7; z++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

				Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
				Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

				sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
				sprite->GetComponent<Sprite>()->zSortingOrder = z;
			}
		}

		//bridgeA
		{
			int x = 3;
			int z = 7;

			for (size_t y = 0; y < 6; y++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

				Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
				Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

				sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
				sprite->GetComponent<Sprite>()->zSortingOrder = z;
			}
		}

		//pillerA 2
		{
			int x = 3;
			int y = 5;

			for (size_t z = 0; z < 7; z++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

				Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
				Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

				sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
				sprite->GetComponent<Sprite>()->zSortingOrder = z;
			}
		}


		//pillerB 1
		{
			int x = 6;
			int y = 3;

			for (size_t z = 0; z < 11; z++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

				Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
				Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

				sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
				sprite->GetComponent<Sprite>()->zSortingOrder = z;
			}
		}


		//bridgeB
		{
			int y = 3;
			int z = 11;

			for (size_t x = 0; x < 7; x++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

				Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
				Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

				sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
				sprite->GetComponent<Sprite>()->zSortingOrder = z;
			}
		}

		//pillerB 2
		{
			int x = 0;
			int y = 3;

			for (size_t z = 0; z < 11; z++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("main"));
				sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));

				Vector2f carPosition((texture->GetTextureData()->width / 2) * x, (texture->GetTextureData()->height - heightInPixels) * y);
				Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));

				sprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
				sprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
				sprite->GetComponent<Sprite>()->zSortingOrder = z;
			}
		}

		{
			int x = 0;
			int y = 1;
			int z = 1;

			movingSprite = scene->AddGameObject(new GameObject("main"));
			movingSprite->AddComponent(new Sprite(roadTexture, Vector2f(0, 0)));

			Vector2f carPosition((roadTexture->GetTextureData()->width / 2) * x, (roadTexture->GetTextureData()->height - heightInPixels) * y);
			Vector2f isoPosition = CartesianToIsometric(carPosition - Vector2f(heightInPixels * z));
			Vector2f hh = IsometricToCartesian(isoPosition);

			movingSprite->GetTransform()->SetPosition(Vector3f(isoPosition.x, isoPosition.y, 0));
			movingSprite->GetComponent<Sprite>()->xySortingOrder = ((int)carPosition.x + (int)carPosition.y * mostTiles);
			movingSprite->GetComponent<Sprite>()->zSortingOrder = z;
		}

		IsoPosition = Vector2f(movingSprite->GetTransform()->GetPosition().x, movingSprite->GetTransform()->GetPosition().y);
		carPosition = IsometricToCartesian(Vector2f(IsoPosition.x, IsoPosition.y));
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

		carPosition += Vector2f(0.05f, 0);
		IsoPosition = CartesianToIsometric(carPosition);

		movingSprite->GetTransform()->SetPosition(Vector3f((int)IsoPosition.x, (int)IsoPosition.y, 0));
	}

	void IsoMapTest::Render()
	{
		App::Render();
	}
}