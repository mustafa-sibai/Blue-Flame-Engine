#include "WINEngineEntryPoint.h"
#include "BF/Application/App.h"
#include "BF/Input/Keyboard.h"
#include "BF/Input/Mouse.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Application;
			using namespace BF::Input;

			WINEngineEntryPoint::WINEngineEntryPoint(const WINWindow& winWindow, RenderAPI renderAPI) :
				winWindow(winWindow), context(renderAPI), deltaTime(0.0), frameRateTarget(0.0), frameTimeTarget(0.0), FPS(0)
			{
			}

			WINEngineEntryPoint::~WINEngineEntryPoint()
			{
			}

			void WINEngineEntryPoint::Run(App& app)
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
							app.PostLoad();

							if(Engine::state != Engine::State::Exit)
								Engine::state = Engine::State::Render;

							app.frameTimer.Reset();
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
									app.Update(deltaTime);
									app.Render();
									Mouse::Update();
									Keyboard::Update();
									FPS++;
								}
							}
							else
							{
								deltaTime = app.frameTimer.GetElapsedTimeInMilliseconds();
								app.frameTimer.Reset();
								app.Update(deltaTime);
								app.Render();
								Mouse::Update();
								Keyboard::Update();
								FPS++;
							}

							if (app.frameRateTimer.GetElapsedTimeInMilliseconds() >= 1000.0f)
							{
								BFE_LOG_INFO("Frames: " + to_string(FPS) + " LastFrameTime: " + to_string(deltaTime), "");
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