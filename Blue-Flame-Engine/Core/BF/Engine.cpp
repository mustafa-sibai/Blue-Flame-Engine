#include "Engine.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

using namespace BF::Graphics::API;
using namespace BF::Application;

Window Engine::window;
Context Engine::context = Context(RenderAPI::Default);

Engine::Engine(Window window, RenderAPI renderAPI) :
	totalTime(0), extra(0), FPS(0), FUPS(0), extraTimesToRunFixedUpdate(0), runFixedUpdate(false)
{
	Engine::window = window;
	Engine::context = Context(renderAPI);
	Engine::context.Initialize();
}

Engine::~Engine()
{
}

void Engine::Run()
{
	while (window.IsOpen())
	{
		window.Update();

		for (int i = 0; i < SceneManager::GetScenes().size(); i++)
		{
			if (SceneManager::GetScene(i).IsRunning())
			{
				if (!SceneManager::GetScene(i).initialized)
				{
					SceneManager::GetScene(i).Initialize();
					SceneManager::GetScene(i).initialized = true;
				}

				if (!SceneManager::GetScene(i).loaded)
				{
					SceneManager::GetScene(i).Load();
					SceneManager::GetScene(i).loaded = true;
				}

				SceneManager::GetScene(i).frameTimer.Reset();
				if (runFixedUpdate || extraTimesToRunFixedUpdate > 0)
				{
					SceneManager::GetScene(i).FixedUpdate();
					extraTimesToRunFixedUpdate--;
					runFixedUpdate = false;
				}

				SceneManager::GetScene(i).Update();
				SceneManager::GetScene(i).Render();
				double elapsedFrameTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();

				FPS++;
				totalTime += elapsedFrameTime;

				if (totalTime >= frameTimeTarget)
				{
					extra += totalTime - frameTimeTarget;
					FUPS++;
					runFixedUpdate = true;

					if (extra >= frameTimeTarget)
					{
						extraTimesToRunFixedUpdate++;
						FUPS++;
						extra -= frameTimeTarget;
					}

					totalTime = 0;
				}

				if (SceneManager::GetScene(i).frameRateTimer.GetElapsedTimeInSeconds() >= 1.0f)
				{
					BF_INFO("frames: %d FUPS: %d", FPS, FUPS);
					SceneManager::GetScene(i).frameRateTimer.Reset();
					FPS = 0;
					FUPS = 0;
				}
			}
		}
	}
}