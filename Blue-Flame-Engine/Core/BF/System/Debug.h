#pragma once
#include <iostream>
#include <string>

#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_WEB) || defined(BF_PLATFORM_LINUX)
#include <stdio.h>
#endif

#ifdef BF_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#ifdef BF_PLATFORM_ANDROID
#include <strings.h>
#include <android/log.h>
#endif

namespace BF
{
	namespace System
	{
		struct Debug
		{
		//private:
			enum class LogLevel { Info, Warning, Error, Fatal };

			template<typename T>
			static void Log(T value, LogLevel level);
		};

#include "BF/System/Debug.inl"
	}
}