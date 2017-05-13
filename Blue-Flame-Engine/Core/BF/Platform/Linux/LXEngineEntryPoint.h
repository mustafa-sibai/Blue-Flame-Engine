#pragma once
#include "BF/Platform/Linux/LXWindow.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Platform
	{
		namespace Linux
		{
			class BF_API LXEngineEntryPoint
			{
				private:
					LXWindow lxWindow;
					Graphics::API::Context context;

					double deltaTime;
					double frameRateTarget, frameTimeTarget;
					unsigned int FPS;

				public:
					enum class State { Initialize, Render, Exit };
					State state;

				public:
					LXEngineEntryPoint(const LXWindow& lxWindow, Graphics::API::RenderAPI renderAPI);
					~LXEngineEntryPoint();

					void Run(Application::Scene& mainScene);
					void LimitFrameRate(double limit);

					inline double GetDeltaTime() const { return deltaTime; }
					inline LXWindow& GetWindow() { return lxWindow; }
					inline Graphics::API::Context& GetContext() { return context; }
			};
		}
	}
}