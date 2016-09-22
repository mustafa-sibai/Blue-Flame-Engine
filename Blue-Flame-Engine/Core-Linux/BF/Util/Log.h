#if 0
#pragma once

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Util
	{
		class DLLEXPORT Log
		{
			public:
				Log();
				~Log();

				static void DisplayErrorMessage();
				static void GLCall(bool call);
		};
	}
}
#endif // DEBUG