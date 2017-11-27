#include "WINEngineEntryPoint.h"
#include "BF/Application/App.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace BF::Graphics::API;
			using namespace BF::Application;

			WINEngineEntryPoint::WINEngineEntryPoint(const WINWindow& winWindow, Graphics::API::RenderAPI renderAPI) :
				winWindow(winWindow), context(renderAPI), frameRateTarget(0.0f), frameTimeTarget(0.0f)
			{
				LimitFrameRate(60.0f);
			}

			WINEngineEntryPoint::~WINEngineEntryPoint()
			{
			}

			void WINEngineEntryPoint::Run(Application::App& app)
			{
				while (Engine::state != Engine::State::Exit)
				{
					switch (Engine::state)
					{
						case Engine::State::Initialize:
						{
							winWindow.Initialize();
							context.Initialize();
							app.Initialize();
							app.Load();
							Engine::state = Engine::State::Render;
							break;
						}

						case Engine::State::Render:
						{
							winWindow.Update();

							if (frameTimeTarget != 0.0f)
							{
								if (app.frameTimer.GetElapsedTimeInMilliseconds() >= frameTimeTarget)
								{
									deltaTime = app.frameTimer.GetElapsedTimeInMilliseconds();
									app.frameTimer.Reset();
									app.Update();
									app.Render();
									FPS++;
								}
							}
							else
							{
								deltaTime = app.frameTimer.GetElapsedTimeInMilliseconds();
								app.frameTimer.Reset();
								app.Update();
								app.Render();
								FPS++;
							}

							if (app.frameRateTimer.GetElapsedTimeInMilliseconds() >= 1000.0f)
							{
								BF_LOG_INFO("Frames: " + std::to_string(FPS) + " LastFrameTime: " + std::to_string(deltaTime));
								app.frameRateTimer.Reset();
								FPS = 0;
							}
							break;
						}

						default:
							break;
					}
				}
			}

			void WINEngineEntryPoint::LimitFrameRate(double limit)
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