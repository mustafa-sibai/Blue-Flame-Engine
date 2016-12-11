#include "FPSCamera.h"
#include "BF/Input/Mouse.h"
#include "BF/Input/Keyboard.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Input;
		using namespace BF::Math;

		FPSCamera::FPSCamera(const Math::Matrix4& projectionMatrix) :
			Camera(projectionMatrix), movmentSpeed(0.1f), yaw(0.0f)
		{
		}

		FPSCamera::~FPSCamera()
		{
		}

		void FPSCamera::Update()
		{
			Math::Vector3 cameraFront = Math::Vector3(0.0f, 0.0f, 1.0f);
			Math::Vector3 cameraUp = Math::Vector3(0.0f, 1.0f, 0.0f);

			if (Keyboard::IsKeyPressed(Keyboard::Key::D))
			{
				this->position += cameraFront.Cross(cameraUp).Normalize() * movmentSpeed;
				this->direction += cameraFront.Cross(cameraUp).Normalize() * movmentSpeed;
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::A))
			{
				this->position -= cameraFront.Cross(cameraUp).Normalize() * movmentSpeed;
				this->direction -= cameraFront.Cross(cameraUp).Normalize() * movmentSpeed;
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::W))
			{
				this->position += Vector3(0, 0, movmentSpeed);
				this->direction += Vector3(0, 0, movmentSpeed);
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::S))
			{
				this->position -= Vector3(0, 0, movmentSpeed);
				this->direction -= Vector3(0, 0, movmentSpeed);
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::R))
				this->position += Vector3(0, movmentSpeed, 0);

			if (Keyboard::IsKeyPressed(Keyboard::Key::F))
				this->position -= Vector3(0, movmentSpeed, 0);

			if (Keyboard::IsKeyPressed(Keyboard::Key::E))
				yaw += 0.5f;

			if (Keyboard::IsKeyPressed(Keyboard::Key::Q))
				yaw -= 0.5f;

			//this->direction = Vector3(cos(Math::ToRadians(yaw)), 0, Math::ToRadians(yaw));
			viewMatrix = Math::Matrix4::LookAt(position, direction, Vector3(0, 1, 0));
		}
	}
}