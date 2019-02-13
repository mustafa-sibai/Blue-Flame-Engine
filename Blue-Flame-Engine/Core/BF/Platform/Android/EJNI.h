#pragma once
#define INCLUDE_OPENGL
#include <android/native_window.h>
#include <thread>
#include <mutex>
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			class BFE_API EJNI
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