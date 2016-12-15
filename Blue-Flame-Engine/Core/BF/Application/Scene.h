#pragma once
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API Scene
		{
			friend class Engine;

			private:
				BF::System::Timer frameTimer;
				BF::System::Timer frameRateTimer;

				bool run = false;
				bool initialized = false;
				bool loaded = false;
				int fixedUpdateTicks = 0;

			public:
				inline void Run() { run = true; }
				inline void Stop() { run = false; }

				inline bool IsRunning() const { return run; }

			protected:
				virtual void Initialize() = 0;
				virtual void Load() = 0;
				virtual void FixedUpdate() = 0;
				virtual void Update() = 0;
				virtual void Render() = 0;
		};
	}
}