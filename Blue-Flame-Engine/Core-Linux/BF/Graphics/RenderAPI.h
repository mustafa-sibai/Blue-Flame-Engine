#pragma once

namespace BF
{
	namespace Graphics
	{
		enum class BF_API RenderAPI
		{
#ifdef BF_PLATFORM_WINDOWS
			OpenGL, DirectX
#elif BF_PLATFORM_LINUX
			OpenGL
#else
#error define BF_PLATFORM_WINDOWS or BF_PLATFORM_LINUX
#endif	
		};

		static RenderAPI renderAPI;
	}
}