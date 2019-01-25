#include "App.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/Renderers/PostProcessing.h"

namespace BF
{
	namespace Application
	{
		using namespace BF::Graphics::Renderers;

		App::App() :
			renderPipeline(cameraManager), initialized(false), loaded(false), fixedUpdateTicks(0), mainScene(nullptr)
		{
		}

		App::~App()
		{
		}

		void App::Initialize()
		{
			//BF::Application::SceneManager::GetScenes()[0]->Initialize();

			cameraManager.Initialize();
			renderPipeline.Initialize();
		}

		void App::Load()
		{
			//styleSheet.Load("../Sandbox/Assets/GUI/StyleSheet.xml");
			//BF::Application::SceneManager::GetScenes()[0]->Load();
		}

		void App::PostLoad()
		{
			renderPipeline.PostLoad();
			scriptExecutor.Start();
		}

		void App::Update()
		{
			cameraManager.Update();
			renderPipeline.Update();
			scriptExecutor.Update();

			//layerManager.Update();
			//sceneManager.GetCurrentScene().Update();
			//BF::Application::SceneManager::GetScenes()[0]->Update();
		}

		void App::Render()
		{
			renderPipeline.Render();

			//sceneManager.GetCurrentScene().Render();
			//BF::Application::SceneManager::GetScenes()[0]->Render();
		}

		void App::RunScene(Scene& scene)
		{
			mainScene = &scene;
		}
	}
}