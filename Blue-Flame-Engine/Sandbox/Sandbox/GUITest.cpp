#include "GUITest.h"

namespace GUITest
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

	GUITest::GUITest()
	{
	}

	GUITest::~GUITest()
	{
	}

	void GUITest::Initialize()
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

		App::Initialize();
	}

	void GUITest::Load()
	{
		App::Load();
	}

	void GUITest::PostLoad()
	{
		App::PostLoad();
		CreateTestButton();
		//CreateTestCheckBox();
		App::RunScene(*scene);
	}

	void GUITest::CreateTestButton()
	{
		GameObject* ButtonGameObject = scene->AddGameObject(new GameObject("Test Button"));
		button = (Button*)ButtonGameObject->AddComponent(new Button());
		button->gameObject->GetTransform()->SetPosition(Vector3f(100, 0, 0));
		button->currentSprite->pivot = Vector2f(0.5f, 0.5f);
	}

	void GUITest::CreateTestCheckBox()
	{
		GameObject* CheckBoxGameObject = scene->AddGameObject(new GameObject("Test CheckBox"));
		checkBox = (CheckBox*)CheckBoxGameObject->AddComponent(new CheckBox());
		checkBox->gameObject->GetTransform()->SetPosition(Vector3f(100, 0, 0));
		checkBox->currentSprite->pivot = Vector2f(0.5f, 0.5f);
	}

	void GUITest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));

		BF::Math::Vector2f mousePosition = BF::Input::Mouse::GetPosition();

		BF::Math::Vector3f newPos = camera->ScreenToWorldPoint(Vector3f(mousePosition.x, mousePosition.y, 0), Vector2f(0.5f, 0.5f));

		ButtonStateTest();
	}

	void GUITest::ButtonStateTest()
	{
		if (button->state == Button::State::Hovered)
		{
			BFE_LOG_INFO("YOOOO, button Hovered", "");
		}

		if (button->state == Button::State::Pressed)
		{
			BFE_LOG_INFO("YOOOO, button pressed", "");
		}

		if (button->state == Button::State::Released)
		{
			BFE_LOG_INFO("YOOOO, button Released", "");
		}
	}

	void GUITest::Render()
	{
		App::Render();
	}
}