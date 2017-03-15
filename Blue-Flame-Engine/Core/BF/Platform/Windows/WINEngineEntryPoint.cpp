#include "WINEngineEntryPoint.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

#define BF_FRAME_RATE_TARGET 60.0f
#define BF_FRAME_TIME_TARGET 1000.0f / BF_FRAME_RATE_TARGET

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace BF::Graphics::API;
			using namespace BF::Application;

			WINEngineEntryPoint::WINEngineEntryPoint(const WINWindow& winWindow, Graphics::API::RenderAPI renderAPI) :
				winWindow(winWindow), context(renderAPI)
			{
			}

			WINEngineEntryPoint::~WINEngineEntryPoint()
			{
			}

			void WINEngineEntryPoint::Run()
			{
				BF_LOG_INFO("Engine Run");
				while (state != State::Exit)
				{
					switch (state)
					{
					case State::Initialize:
					{
						winWindow.Initialize();
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

								winWindow.Update();
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