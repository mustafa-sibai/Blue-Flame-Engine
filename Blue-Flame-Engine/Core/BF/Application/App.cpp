#include "App.h"

namespace BF
{
	namespace Application
	{
		using namespace BF::Graphics::Renderers;

		App::App() :
			cameraManager(constantBufferManager), guiSystem(renderPipeline), renderPipeline(constantBufferManager, cameraManager), initialized(false), loaded(false), fixedUpdateTicks(0), mainScene(nullptr)
		{
		}

		App::~App()
		{
		}

		void App::Initialize()
		{
			//BF::Application::SceneManager::GetScenes()[0]->Initialize();
			constantBufferManager.Initialize();
			renderPipeline.Initialize();
			guiSystem.Initialize();
		}

		void App::Load()
		{
			//BF::Application::SceneManager::GetScenes()[0]->Load();
			guiSystem.Load();
		}

		void App::PostLoad()
		{
			renderPipeline.PostLoad();
			scriptExecutor.Start();
			guiSystem.PostLoad();
		}

		void App::Update()
		{
			cameraManager.Update();
			renderPipeline.Update();
			scriptExecutor.Update();
			guiSystem.Update();

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