#pragma once
/*
#if ! defined BF_PLATFORM_WINDOWS && ! defined BF_PLATFORM_LINUX && ! defined BF_PLATFORM_WEBGL 
#error define BF_PLATFORM_WINDOWS or BF_PLATFORM_LINUX or BF_PLATFORM_WEBGL
#endif*/

#ifdef BF_PLATFORM_WINDOWS
	#ifdef BF_CORE_DLL
		#define BF_API __declspec(dllexport)
	#else
		#define BF_API __declspec(dllimport)
	#endif
#else
	#define BF_API
#endif