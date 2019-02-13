#include "WEBEngineEntryPoint.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

#define BFE_FRAME_RATE_TARGET 60.0f
#define BFE_FRAME_TIME_TARGET 1000.0f / BFE_FRAME_RATE_TARGET

namespace BF
{
	namespace Platform
	{
		namespace Web
		{
			using namespace BF::Graphics::API;
			using namespace BF::Application;

			WEBEngineEntryPoint::WEBEngineEntryPoint(const WEBWindow& webWindow, Graphics::API::RenderAPI renderAPI) :
				webWindow(webWindow), context(renderAPI)
			{
			}

			WEBEngineEntryPoint::~WEBEngineEntryPoint()
			{
			}

			void WEBEngineEntryPoint::FunctionCallBack(void* thisPointer)
			{
				WEBEngineEntryPoint* self = static_cast<WEBEngineEntryPoint*>(thisPointer);
				self->MainLoop();
			}

			void WEBEngineEntryPoint::Run(Application::Scene& mainScene)
			{
				this->mainScene = &mainScene;
				emscripten_set_main_loop_arg(FunctionCallBack, this, 0, true);
			}

			//-------------------------------------- THIS TO BE REMOVED AND CHANGED LIKE THE WINDOWS VERION -------------------------------------------

			void WEBEngineEntryPoint::MainLoop()
			{
				switch (state)
				{
					case State::Initialize:
					{
						webWindow.Initialize();
						context.Initialize();
						SceneManager::AddNewScene(mainScene);
						SceneManager::GetScene(0).Run();
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
									//SceneManager::GetScene(i).FixedUpdate();
									timesToRunFixedUpdate--;
									FUPS++;
								}

								webWindow.Update();
								SceneManager::GetScene(i).Update();
								SceneManager::GetScene(i).Render();
								elapsedFrameTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();

								FPS++;
								totalTime += elapsedFrameTime;

								if (totalTime >= BFE_FRAME_TIME_TARGET)
								{
									extra += totalTime - BFE_FRAME_TIME_TARGET;
									timesToRunFixedUpdate++;

									if (extra >= BFE_FRAME_TIME_TARGET)
									{
										timesToRunFixedUpdate++;
										extra -= BFE_FRAME_TIME_TARGET;
									}

									totalTime = 0;
								}

								if (SceneManager::GetScene(i).frameRateTimer.GetElapsedTimeInSeconds() >= 1.0f)
								{
									//BFE_LOG_INFO("Frames: %d FUPS: %d FrameTime: %f", FPS, FUPS, elapsedFrameTime);
									SceneManager::GetScene(i).frameRateTimer.Reset();
									FPS = 0;
									FUPS = 0;
								}
							}
						}
						break;
					}

					case State::Exit:
					{
						break;
					}

					default:
						break;
				}
			}

			//-------------------------------------- THIS TO BE REMOVED AND CHANGED LIKE THE WINDOWS VERION -------------------------------------------

			void WEBEngineEntryPoint::LimitFrameRate(double limit)
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