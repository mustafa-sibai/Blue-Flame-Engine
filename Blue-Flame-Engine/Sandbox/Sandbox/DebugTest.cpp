#include "DebugTest.h"

namespace DebugTest
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

	DebugTest::DebugTest()
	{
	}

	DebugTest::~DebugTest()
	{
	}

	void DebugTest::Initialize()
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

	void DebugTest::Load()
	{
		App::Load();
	}

	void DebugTest::PostLoad()
	{
		//6,660 sprites = 62 FPS
		/*for (size_t y = 0; y < 189; y++)
		{
			for (size_t x = 0; x < 317; x++)
			{
				BF::Debugging::Debug::DrawRectangle(Vector2f(-950.0f + (float)x * 6.0f, 560.0f - (float)y * 6.0f), Vector2f(5.0f, 5.0f), Vector2f(0.5f, 0.5f), Color(0.2f, 0.3f, 0.5f, 1));
			}
		}*/

		//3,250 sprite = 62 FPS
		for (size_t y = 0; y < 189; y++)
		{
			for (size_t x = 0; x < 317; x++)
			{
				GameObject* sprite = scene->AddGameObject(new GameObject("sprite"));
				sprite->AddComponent(new RectangleShape(Vector2i(5, 5), Vector2f(0.5f, 0.5f), 0, defaultRenderLayer, Color(0.5f, 0.3f, 0.3f, 1)));
				sprite->GetComponent<Transform>()->SetPosition(Vector3f(-950.0f + (float)x * 6.0f, 560.0f - (float)y * 6.0f, 0));
			}
		}


		/**/

		/*BF::Debugging::Debug::DrawRectangle(Vector2f(-600 + 0 * 12, 250), Vector2f(10, 10), Vector2f(0.5f, 0.5f), Color(0.2f, 0.3f, 0.5f, 1));
		BF::Debugging::Debug::DrawRectangle(Vector2f(-600 + 1 * 12, 250), Vector2f(10, 10), Vector2f(0.5f, 0.5f), Color(0.2f, 0.3f, 0.5f, 1));*/

		App::PostLoad();
		App::RunScene(*scene);
	}

	void DebugTest::Update(double deltaTime)
	{
		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();
		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));

		App::Update(deltaTime);

		//old system 1280 fps
		//new system fps 1500

		
		/*BF::Debugging::Debug::DrawLine(Vector2f(0, -200), Vector2f(100, -200), 10, Color(1, 1, 0, 1));
		BF::Debugging::Debug::DrawLine(Vector2f(-100, -300), Vector2f(-200, -300), 5, Color(0, 1, 1, 1));

		BF::Debugging::Debug::DrawLine(Vector2f(-300, -200), Vector2f(-400, -300), 1, Color(1, 1, 1, 1));
		BF::Debugging::Debug::DrawLine(Vector2f(200, -200), Vector2f(300, -300), 3, Color(1, 1, 1, 1));

		BF::Debugging::Debug::DrawRegularPolygon(Vector2f(250, 0), 100, 3, Color(1, 0, 0, 1));
		BF::Debugging::Debug::DrawRegularPolygon(Vector2f(0, 0), 100, 4, Color(0, 1, 0, 1));
		BF::Debugging::Debug::DrawRegularPolygon(Vector2f(-250, 0), 100, 8, Color(0, 0, 1, 1));
		BF::Debugging::Debug::DrawRegularPolygon(Vector2f(-450, 0), 50, 12, Color(1, 1, 1, 1));
		BF::Debugging::Debug::DrawRegularPolygon(Vector2f(0, 250), 100, 100, Color(0, 1, 0.5f, 1));*/
		

		/*BF::Debugging::Debug::DrawRectangle(Vector2f(300, 250), Vector2f(100, 100), Vector2f(0.5f, 0.5f), Color(0.2f, 0.3f, 0.5f, 1));
		BF::Debugging::Debug::DrawRectangle(Vector2f(500, 250), Vector2f(100, 100), Vector2f(0.5f, 0.5f), Color(0.6f, 0.2f, 0.2f, 1));*/
	}

	void DebugTest::Render()
	{
		App::Render();
	}
}