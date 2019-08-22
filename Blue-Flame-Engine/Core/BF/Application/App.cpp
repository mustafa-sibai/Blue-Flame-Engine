#include "App.h"

namespace BF
{
	namespace Application
	{
		using namespace BF::Graphics::Renderers;

		App::App() :
			cameraManager(constantBufferManager), guiSystem(renderPipeline), animationSystem(renderPipeline), renderPipeline(constantBufferManager, cameraManager), initialized(false), loaded(false), fixedUpdateTicks(0), mainScene(nullptr)
		{
		}

		App::~App()
		{
		}

		void App::Initialize()
		{
			constantBufferManager.Initialize();
			cameraManager.Initialize();
			transformSystem.Initialize();
			physicsEngine.Initialize();
			renderPipeline.Initialize();
			animationSystem.Initialize();
			scriptExecutor.Initialize();
			guiSystem.Initialize();
			astarSystem.Initialize();
		}

		void App::Load()
		{
			constantBufferManager.Load();
			cameraManager.Load();
			transformSystem.Load();
			physicsEngine.Load();
			renderPipeline.Load();
			animationSystem.Load();
			scriptExecutor.Load();
			guiSystem.Load();
			astarSystem.Load();
		}

		void App::PostLoad()
		{
			constantBufferManager.PostLoad();
			cameraManager.PostLoad();
			transformSystem.PostLoad();
			physicsEngine.PostLoad();
			renderPipeline.PostLoad();
			animationSystem.PostLoad();
			scriptExecutor.PostLoad();
			guiSystem.PostLoad();
			astarSystem.PostLoad();
		}

		void App::Update(double deltaTime)
		{
			constantBufferManager.Update(deltaTime);
			cameraManager.Update(deltaTime);
			transformSystem.Update(deltaTime);
			physicsEngine.Update(deltaTime);
			renderPipeline.Update(deltaTime);
			animationSystem.Update(deltaTime);
			scriptExecutor.Update(deltaTime);
			guiSystem.Update(deltaTime);
			astarSystem.Update(deltaTime);
		}

		void App::Render()
		{
			constantBufferManager.Render();
			cameraManager.Render();
			transformSystem.Render();
			physicsEngine.Render();
			renderPipeline.Render();
			animationSystem.Render();
			scriptExecutor.Render();
			guiSystem.Render();
			astarSystem.Render();
		}

		void App::RunScene(Scene& scene)
		{
			mainScene = &scene;
		}
	}
}