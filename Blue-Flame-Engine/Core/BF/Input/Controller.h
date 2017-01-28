#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include "BF/Platform/Windows/WINWindow.h"
#include <Xinput.h>
#include "BF/Common.h"

#define BF_MAX_CONTROLLER_BUTTONS 25

namespace BF
{
	namespace Input
	{
		class BF_API Controller
		{
			friend class Controllers;

			private:
				XINPUT_STATE state;
				XINPUT_VIBRATION Vibration;

				bool buttons[BF_MAX_CONTROLLER_BUTTONS];
				int ID;

			public:
				enum class Button { A, B, X, Y, Left, Right, Up, Down, Start, Back };

			public:
				Controller();
				~Controller();

				bool IsButtonPressed(Button button) const;

			private:
				void Update();
				bool IsDeviceConnected(int portNumber);
		};

		class BF_API Controllers
		{
			friend class BF::Platform::Windows::WINWindow;

			private:
				static Controller controller[XUSER_MAX_COUNT];

			private:
				static void Update();

			public:
				inline static const Controller& Primary() { return controller[0]; }
				inline static const Controller& Secondary() { return controller[1]; }
				inline static const Controller& Tertiary() { return controller[2]; }
				inline static const Controller& Quaternary() { return controller[3]; }

			private:
				static void FindNewDevices();
		};
	}
}
#endif