#include "EJNI.h"
#include "BF/System/Log.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			std::thread EJNI::t;
			std::mutex EJNI::m;

			void EJNI::NativeOnCreate(int(*main)())
			{
				BF_LOG_INFO("EJNI::NativeOnCreate");
				EJNI::t = std::thread(main);
			}

			void EJNI::NativeOnStart()
			{
				BF_LOG_INFO("EJNI::NativeOnStart");
			}

			void EJNI::NativeOnResume()
			{
				BF_LOG_INFO("EJNI::NativeOnResume");
			}

			void EJNI::NativeOnPause()
			{
				BF_LOG_INFO("EJNI::NativeOnPause");
				EJNI::t.join();
			}

			void EJNI::NativeOnStop()
			{
				BF_LOG_INFO("EJNI::NativeOnStop");
			}

			void EJNI::NativeSetSurface(ANativeWindow* window)
			{
				while (&Engine::GetWindow() == NULL)
					BF_LOG_INFO("Waiting for engine thread to start...");

				m.lock();
				Engine::GetWindow().Initialize(window);
				Engine::andEngineEntryPoint->state = ANDEngineEntryPoint::State::Initialize;
				BF_LOG_INFO("EJNI::NativeSetSurface");
				m.unlock();
			}
		}
	}
}