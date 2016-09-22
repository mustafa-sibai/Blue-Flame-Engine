#pragma once
#include "../Common.h"
#include "../Graphics/RenderAPI.h"
#include "../Math/Vector4.h"

#ifdef BF_PLATFORM_WINDOWS
	#include "../Platform/Windows/WINWindow.h"
	#include "../Platform/OpenGL/WINGLContext.h"
#elif BF_PLATFORM_LINUX
	#include "../Platform/Linux/LXWindow.h"
	#include "../Platform/OpenGL/LXGLContext.h"
#endif

namespace BF
{
	namespace Application
	{
		class BF_API Window
		{
		private:
#ifdef BF_PLATFORM_WINDOWS
			Platform::Windows::WINWindow *winWindow;
			Platform::Windows::WINGLContext *winGLContext;
#elif BF_PLATFORM_LINUX
			Platform::Linux::LXWindow *lxWindow;
			Platform::Linux::LXGLContext *lxGLContext;
#endif
		public:
			Window(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style, Graphics::RenderAPI renderAPI);
			~Window();
			void Update();
			bool IsOpen();
			void Clear(Math::Vector4 Color);
			void SwapBuffers();
		};
	}
}