#pragma once
#include "BF/Platform/Windows/WINWindow.h"
#include <Xinput.h>
#include "BF/Math/Math.h"
#include "BF/System/Timer.h"
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

				float leftTrigger;
				float rightTrigger;

				Math::Vector2f leftStick;
				Math::Vector2f rightStick;

			public:
				enum class Button { A, B, X, Y, Left, Right, Up, Down, LeftShoulder, RightShoulder, Start, Back };

			public:
				Controller();
				~Controller();

				bool IsButtonPressed(Button button) const;

				Math::Vector2f CalculateStickPosition(const Math::Vector2f& stickPosition, const Math::Vector2f& stickDeadZone);

				inline float GetLeftTrigger() const { return leftTrigger; }
				inline float GetRightTrigger() const { return rightTrigger; }

				inline const Math::Vector2f& GetLeftStike() const { return leftStick; }
				inline const Math::Vector2f& GetRightStike() const { return rightStick; }

			private:
				void Update();
				bool IsDeviceConnected(int portNumber);
		};

		class BF_API Controllers
		{
			friend class BF::Platform::Windows::WINWindow;

			private:
				static Controller controller[XUSER_MAX_COUNT];
				static System::Timer timer;

			private:
				static void Update();

			public:
				inline static const Controller& Primary() { return controller[0]; }
				inline static const Controller& Secondary() { return controller[1]; }
				inline static const Controller& Tertiary() { return controller[2]; }
				inline static const Controller& Quaternary() { return controller[3]; }

			private:
				static void FindNewDevices();
				static int* GetOtherControllersIndecies(int controllerIndex);
		};
	}
}