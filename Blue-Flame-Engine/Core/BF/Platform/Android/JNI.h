#pragma once
#include <EGL/egl.h>
#include "BF/Common.h"
#include <thread>
#include <mutex>

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			class BF_API JNI
			{
			public:
				static std::thread t;
				static std::mutex m;

			public:
				static void NativeOnCreate(int(*main)());
				static void NativeOnStart();
				static void NativeOnResume();
				static void NativeOnPause();
				static void NativeOnStop();
				static void NativeSetSurface(ANativeWindow* window);
			};
		}
	}
}