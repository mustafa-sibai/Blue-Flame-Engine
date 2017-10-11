#include "LXEngineEntryPoint.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Platform
	{
		namespace Linux
		{
			using namespace BF::Graphics::API;
			using namespace BF::Application;

			LXEngineEntryPoint::LXEngineEntryPoint(const LXWindow& lxWindow, Graphics::API::RenderAPI renderAPI) :
				lxWindow(lxWindow), context(renderAPI), frameRateTarget(0.0f), frameTimeTarget(0.0f)
			{
				LimitFrameRate(60.0f);
			}

			LXEngineEntryPoint::~LXEngineEntryPoint()
			{
			}

			void LXEngineEntryPoint::Run(Scene& mainScene)
			{
				BF_LOG_INFO("Engine Run");
				while (Engine::state != Engine::State::Exit)
				{
					switch (Engine::state)
					{
					case Engine::State::Initialize:
					{
						lxWindow.Initialize();
						context.Initialize();
						SceneManager::AddNewScene(&mainScene);
						SceneManager::GetScene(0).Run();
						Engine::state = Engine::State::Render;
						break;
					}

					case Engine::State::Render:
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

								lxWindow.Update();

								if (frameTimeTarget != 0.0f)
								{
									if (SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds() >= frameTimeTarget)
									{
										deltaTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();
										SceneManager::GetScene(i).frameTimer.Reset();
										SceneManager::GetScene(i).Update();
										SceneManager::GetScene(i).Render();
										FPS++;
									}
								}
								else
								{
									deltaTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();
									SceneManager::GetScene(i).frameTimer.Reset();
									SceneManager::GetScene(i).Update();
									SceneManager::GetScene(i).Render();
									FPS++;
								}

								if (SceneManager::GetScene(i).frameRateTimer.GetElapsedTimeInMilliseconds() >= 1000.0f)
								{
									BF_LOG_INFO("Frames: %d, LastFrameTime: %f", FPS, deltaTime);
									SceneManager::GetScene(i).frameRateTimer.Reset();
									FPS = 0;
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

			void LXEngineEntryPoint::LimitFrameRate(double limit)
			{
				if (limit != 0.0f)
				{
					frameRateTarget = limit;
					frameTimeTarget = 1000.0f / frameRateTarget;
				}
				else
					frameTimeTarget = 0.0f;
			}
		}
	}
}