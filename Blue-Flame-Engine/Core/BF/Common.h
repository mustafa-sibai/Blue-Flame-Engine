#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#pragma warning (disable:4251)
#endif

#if !defined (BF_PLATFORM_WINDOWS) && !defined (BF_PLATFORM_LINUX) && !defined (BF_PLATFORM_WEBGL) && !defined (BF_PLATFORM_ANDROID)
	#error Platform is not defined. Please define one of the following platforms. BF_PLATFORM_WINDOWS or BF_PLATFORM_LINUX or BF_PLATFORM_ANDROID or BF_PLATFORM_WEBGL
#endif

#ifdef BF_PLATFORM_WINDOWS
	#ifdef BF_CORE_DLL
		#define BF_API __declspec(dllexport)
	#else
		#define BF_API __declspec(dllimport)
	#endif
#else
	#define BF_API
#endif