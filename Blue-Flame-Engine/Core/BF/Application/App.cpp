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
			cameraManager.Initialize();
			renderPipeline.Initialize();
			animationSystem.Initialize();
			scriptExecutor.Initialize();
			guiSystem.Initialize();
		}

		void App::Load()
		{
			//BF::Application::SceneManager::GetScenes()[0]->Load();
			constantBufferManager.Load();
			cameraManager.Load();
			renderPipeline.Load();
			animationSystem.Load();
			scriptExecutor.Load();
			guiSystem.Load();
		}

		void App::PostLoad()
		{
			constantBufferManager.PostLoad();
			cameraManager.PostLoad();
			renderPipeline.PostLoad();
			animationSystem.PostLoad();
			scriptExecutor.PostLoad();
			guiSystem.PostLoad();
		}

		void App::Update(double deltaTime)
		{
			constantBufferManager.Update(deltaTime);
			cameraManager.Update(deltaTime);
			renderPipeline.Update(deltaTime);
			animationSystem.Update(deltaTime);
			scriptExecutor.Update(deltaTime);
			guiSystem.Update(deltaTime);

			//layerManager.Update();
			//sceneManager.GetCurrentScene().Update();
			//BF::Application::SceneManager::GetScenes()[0]->Update();
		}

		void App::Render()
		{
			constantBufferManager.Render();
			cameraManager.Render();
			renderPipeline.Render();
			animationSystem.Render();
			scriptExecutor.Render();
			guiSystem.Render();

			//sceneManager.GetCurrentScene().Render();
			//BF::Application::SceneManager::GetScenes()[0]->Render();
		}

		void App::RunScene(Scene& scene)
		{
			mainScene = &scene;
		}
	}
}