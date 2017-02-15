#include "JNI.h"
#include "BF/Engine.h"
#include "BF/System/Log.h"


namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			std::thread JNI::t;
			std::mutex JNI::m;

			void JNI::NativeOnCreate(int(*main)())
			{
				BF_LOG_INFO("NativeOnCreate");
				JNI::t = std::thread(main);
			}

			void JNI::NativeOnStart()
			{
				BF_LOG_INFO("NativeOnStart");
			}

			void JNI::NativeOnResume()
			{
				BF_LOG_INFO("NativeOnResume");
			}

			void JNI::NativeOnPause()
			{
				BF_LOG_INFO("NativeOnPause");
				JNI::t.join();
			}

			void JNI::NativeOnStop()
			{
				BF_LOG_INFO("NativeOnStop");
			}

			void JNI::NativeSetSurface(ANativeWindow* window)
			{
				BF_LOG_INFO("NativeSetSurface");
				BF::Engine::GetWindow().window = window;
				BF::Engine::GetContext().Initialize();

				//if(BF::Engine::GetWindow().GetAWindow().window != nullptr)
					//BF_LOG_INFO("ok");
			}
		}
	}
}