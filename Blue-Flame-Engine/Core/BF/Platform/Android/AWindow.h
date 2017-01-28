#pragma once
#include <android/native_window.h>
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			class BF_API AWindow
			{
			public:
				static ANativeWindow* window;

			public:
				AWindow();
				~AWindow();

				void Update();
				bool IsOpen();
			};
		}
	}
}