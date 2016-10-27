#pragma once
#include <EGL/egl.h>
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace WebGL
		{
			class BF_API WEBWindow
			{
				private:
					EGLDisplay display;
					EGLint numConfigs;

				public:
					WEBWindow();
					~WEBWindow();

					void Update();
					bool IsOpen();

					inline EGLDisplay GetDisplay() const { return display; }
					inline EGLint& GetNumConfigs() { return numConfigs; }
			};
		}
	}
}