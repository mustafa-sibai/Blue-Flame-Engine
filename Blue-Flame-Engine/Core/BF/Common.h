#ifdef BFE_PLATFORM_WINDOWS
	#pragma warning (disable:4251)
#endif

#if !defined (BFE_PLATFORM_WINDOWS) && !defined (BFE_PLATFORM_LINUX) && !defined (BFE_PLATFORM_WEB) && !defined (BFE_PLATFORM_ANDROID)
	#error Platform is not defined. Please define one of the following platforms. BFE_PLATFORM_WINDOWS or BFE_PLATFORM_LINUX or BFE_PLATFORM_ANDROID or BFE_PLATFORM_WEB
#endif

#ifdef BFE_PLATFORM_WINDOWS
	#ifdef BFE_CORE_DLL
		#define BFE_API __declspec(dllexport)
	#else
		#define BFE_API __declspec(dllimport)
	#endif
#else
	#define BFE_API
#endif