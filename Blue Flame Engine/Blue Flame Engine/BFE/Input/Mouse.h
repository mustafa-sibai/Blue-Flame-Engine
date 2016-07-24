#pragma once
#include "../Graphics/Window.h"
#include "../Math/Vector2.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

using namespace BFE::Math;

namespace BFE
{
	namespace Graphics
	{
		class Window;
	}

	namespace Input
	{
		class DLLEXPORT Mouse
		{
			friend class BFE::Graphics::Window;

			private:
				static Vector2 *Position;

			public:
				const static Vector2 GetPosition();
		};
	}
}