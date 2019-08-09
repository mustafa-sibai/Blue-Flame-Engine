#include "EditorScene.h"

//#include <BF/IO/BFALoader.h>
#include <BF/IO/BFFLoader.h>

#include "Fonts/FontAtlasFactory.h"

/*#include "IO/FBXLoader.h"
#include "IO/BFXWriter.h"
#include "IO/BFMWriter.h"
#include "IO/BFAWriter.h"*/
#include "IO/BFFWriter.h"

namespace Editor
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
	using namespace Editor::Fonts;
	using namespace Editor::IO;

	EditorApp::EditorApp()
	{
	}

	EditorApp::~EditorApp()
	{
	}

	void EditorApp::Initialize()
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

	void EditorApp::Load()
	{
		App::Load();
	}

	void EditorApp::PostLoad()
	{
		App::PostLoad();

		FontAtlasFactory fontAtlasFactory;
		BF::Graphics::Fonts::Font* font = fontAtlasFactory.GetFont("../Sandbox/Assets/Fonts/arial.ttf", 24, Editor::Fonts::FontAtlasFactory::Language::English);

		BFFWriter bffWriter;
		bffWriter.WriteToFile("Arial", *font);

		BF::IO::BFFLoader BFFLoader;
		BF::Graphics::Fonts::Font* fontNew = BFFLoader.Load("Arial.bff");

		GameObject* sprite = scene->AddGameObject(new GameObject("main"));
		sprite->AddComponent(new Sprite(fontNew->texture, Vector2f(0, 0), defaultRenderLayer));

		App::RunScene(*scene);
	}

	void EditorApp::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));
	}

	void EditorApp::Render()
	{
		App::Render();
	}
}