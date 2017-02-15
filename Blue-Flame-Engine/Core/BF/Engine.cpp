#include "Engine.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

namespace BF
{
	using namespace BF::Graphics::API;
	using namespace BF::Application;

	Window Engine::window = Window("", 0, 0, 0, 0, Application::WindowStyle::Windowed);
	Context Engine::context = Context(RenderAPI::OpenGL);
	Engine::State Engine::state;

	Engine::Engine(Window window, RenderAPI renderAPI) :
		totalTime(0), extra(0), FPS(0), FUPS(0), timesToRunFixedUpdate(0), elapsedFrameTime(0)
	{
		BF_LOG_INFO("Blue Flame Engine v%d.%d.%d", BF_ENGINE_MAJOR_VERSION, BF_ENGINE_MINOR_VERSION, BF_ENGINE_PATCH_VERSION);

		Engine::window = window;
		Engine::context = Context(renderAPI);
	}

	Engine::~Engine()
	{
		BF_LOG_INFO("Engine DEstructor");
	}

	void Engine::Run()
	{
		BF_LOG_INFO("Engine Run");
		while (state != State::Exit)
		{
			switch (state)
			{
				case State::Initialize:
				{
					window.Initialize();
					context.Initialize();
					state = State::Render;
					break;
				}

				case State::Render:
				{
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
							if (timesToRunFixedUpdate > 0)
							{
								SceneManager::GetScene(i).FixedUpdate();
								timesToRunFixedUpdate--;
								FUPS++;
							}

							window.Update();
							SceneManager::GetScene(i).Update();
							SceneManager::GetScene(i).Render();
							elapsedFrameTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();

							FPS++;
							totalTime += elapsedFrameTime;

							if (totalTime >= frameTimeTarget)
							{
								extra += totalTime - frameTimeTarget;
								timesToRunFixedUpdate++;

								if (extra >= frameTimeTarget)
								{
									timesToRunFixedUpdate++;
									extra -= frameTimeTarget;
								}

								totalTime = 0;
							}

							if (SceneManager::GetScene(i).frameRateTimer.GetElapsedTimeInSeconds() >= 1.0f)
							{
								BF_LOG_INFO("Frames: %d FUPS: %d FrameTime: %f", FPS, FUPS, elapsedFrameTime);
								SceneManager::GetScene(i).frameRateTimer.Reset();
								FPS = 0;
								FUPS = 0;
							}
						}
					}
					break;
				}

				default:
					break;
			}
		}
	}
}