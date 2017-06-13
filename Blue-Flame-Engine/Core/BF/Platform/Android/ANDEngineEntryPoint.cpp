#include "ANDEngineEntryPoint.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

#define BF_FRAME_RATE_TARGET 60.0f
#define BF_FRAME_TIME_TARGET 1000.0f / BF_FRAME_RATE_TARGET

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			using namespace BF::Graphics::API;
			using namespace BF::Application;

			ANDEngineEntryPoint::ANDEngineEntryPoint(const ANDWindow& andWindow, Graphics::API::RenderAPI renderAPI) :
				andWindow(andWindow), context(renderAPI)
			{
			}

			ANDEngineEntryPoint::~ANDEngineEntryPoint()
			{
			}

			void ANDEngineEntryPoint::Run(Scene& mainScene)
			{
				BF_LOG_INFO("Engine Run");
				while (Engine::state != Engine::State::Exit)
				{
					switch (Engine::state)
					{
					case Engine::State::Initialize:
					{
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

								SceneManager::GetScene(i).frameTimer.Reset();
								if (timesToRunFixedUpdate > 0)
								{
									SceneManager::GetScene(i).FixedUpdate();
									timesToRunFixedUpdate--;
									FUPS++;
								}

								andWindow.Update();
								SceneManager::GetScene(i).Update();
								SceneManager::GetScene(i).Render();
								elapsedFrameTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();

								FPS++;
								totalTime += elapsedFrameTime;

								if (totalTime >= BF_FRAME_TIME_TARGET)
								{
									extra += totalTime - BF_FRAME_TIME_TARGET;
									timesToRunFixedUpdate++;

									if (extra >= BF_FRAME_TIME_TARGET)
									{
										timesToRunFixedUpdate++;
										extra -= BF_FRAME_TIME_TARGET;
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
	}
}