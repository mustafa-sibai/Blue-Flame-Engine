#pragma once

#ifdef BF_PLATFORM_WINDOWS
	#ifdef BF_CORE_DLL
		#define BF_API __declspec(dllexport)
	#else
		#define BF_API __declspec(dllimport)
	#endif
#else
	#define BF_API
#endif