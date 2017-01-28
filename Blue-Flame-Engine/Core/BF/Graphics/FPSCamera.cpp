#include "FPSCamera.h"
#include "BF/Engine.h"
#include "BF/Input/Mouse.h"
#include "BF/Input/Keyboard.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Input;
		using namespace BF::Math;

		FPSCamera::FPSCamera(const Math::Matrix4& projectionMatrix) :
			Camera(projectionMatrix), movmentSpeed(0.1f), sensitivity(0.05f), yaw(0.0f), pitch(0.0f)
		{
		}

		FPSCamera::~FPSCamera()
		{
		}

		void FPSCamera::Initialize()
		{
			cameraFront = Vector3(0.0f, 0.0f, 1.0f);
			cameraUp = Vector3(0.0f, 1.0f, 0.0f);
			windowCenter = Vector2(floor((float)Engine::GetWindow().GetClientWidth() / 2.0f), floor((float)Engine::GetWindow().GetClientHeight() / 2.0f));
			BF::Input::Mouse::ShowMouseCursor(false);
			BF::Input::Mouse::SetPosition(windowCenter);
		}

		void FPSCamera::Update()
		{
			if (Keyboard::IsKeyPressed(Keyboard::Key::W))
				position += cameraFront * movmentSpeed;
			if (Keyboard::IsKeyPressed(Keyboard::Key::S))
				position -= cameraFront * movmentSpeed;
			if (Keyboard::IsKeyPressed(Keyboard::Key::A))
				position -= cameraFront.Cross(cameraUp).Normalize() * movmentSpeed;
			if (Keyboard::IsKeyPressed(Keyboard::Key::D))
				position += cameraFront.Cross(cameraUp).Normalize() * movmentSpeed;

			BF::Input::Mouse::SetPosition(windowCenter);
			yaw += (Mouse::GetPosition().x - windowCenter.x) * sensitivity;
			pitch += (windowCenter.y - Mouse::GetPosition().y) * sensitivity;

			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;

			cameraFront.x = cos(ToRadians(yaw)) * cos(ToRadians(pitch));
			cameraFront.y = sin(ToRadians(pitch));
			cameraFront.z = sin(ToRadians(yaw)) * cos(ToRadians(pitch));
			cameraFront = cameraFront.Normalize();

			viewMatrix = Matrix4::LookAt(position, position + cameraFront, cameraUp);
		}
	}
}