#include "Controller.h"
#include "BF/System/Log.h"

#ifdef BF_PLATFORM_WINDOWS

namespace BF
{
	namespace Input
	{
		Controller Controllers::controller[XUSER_MAX_COUNT];
		System::Timer Controllers::timer;

		Controller::Controller() :
			ID(-1)
		{
			ZeroMemory(&state, sizeof(XINPUT_STATE));
			ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

			for (unsigned int i = 0; i < BF_MAX_CONTROLLER_BUTTONS; i++)
				buttons[i] = false;
		}

		Controller::~Controller()
		{
		}

		void Controller::Update()
		{
			/*Vibration.wLeftMotorSpeed = 65535;
			Vibration.wRightMotorSpeed = 65535;
			XInputSetState(0, &Vibration);
			*/

			if (XInputGetState(ID, &state) == ERROR_SUCCESS)
			{
				buttons[(unsigned char)Button::A] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0);
				buttons[(unsigned char)Button::B] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_B) != 0);
				buttons[(unsigned char)Button::X] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_X) != 0);
				buttons[(unsigned char)Button::Y] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) != 0);

				buttons[(unsigned char)Button::Left] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != 0);
				buttons[(unsigned char)Button::Right] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != 0);
				buttons[(unsigned char)Button::Up] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0);
				buttons[(unsigned char)Button::Down] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0);

				buttons[(unsigned char)Button::Start] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_START) != 0);
				buttons[(unsigned char)Button::Back] = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != 0);
			}
			else if (ID != -1)
				ID = -1;
		}

		bool Controller::IsButtonPressed(Button button) const
		{
			return buttons[(unsigned char)button];
		}

		bool Controller::IsDeviceConnected(int portNumber)
		{
			if (XInputGetState(portNumber, &state) == ERROR_SUCCESS)
				return true;

			return false;
		}

		void Controllers::Update()
		{
			if (timer.GetElapsedTimeInMilliseconds() > 1000)
			{
				FindNewDevices();
				timer.Reset();
			}

			for (unsigned int i = 0; i < 4; i++)
				controller[i].Update();
		}

		void Controllers::FindNewDevices()
		{
			for (unsigned int i = 0; i < XUSER_MAX_COUNT; i++)
			{
				if (controller[i].ID == -1)
				{
					int* j = GetOtherControllersIndecies(i);

					if (controller[i].IsDeviceConnected(i) && controller[j[0]].ID != i && controller[j[1]].ID != i && controller[j[2]].ID != i)
						controller[i].ID = i;

					delete[] j;
				}
			}
		}

		int* Controllers::GetOtherControllersIndecies(int controllerIndex)
		{
			int index = 0;
			int controllerNumbers[3];

			for (unsigned int i = 0; i < XUSER_MAX_COUNT; i++)
			{
				if (controllerIndex != i)
				{
					controllerNumbers[index] = i;
					index++;
				}
			}

			return new int[3]{ controllerNumbers[0], controllerNumbers[1], controllerNumbers[2] };
		}
	}
}
#endif