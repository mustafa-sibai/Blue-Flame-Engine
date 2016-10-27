#include "FPSCamera.h"
#include "BF/Input/Keyboard.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Input;
		using namespace BF::Math;

		FPSCamera::FPSCamera(const Math::Matrix4& projectionMatrix) :
			Camera(projectionMatrix), speed(0.1f)
		{
		}

		FPSCamera::~FPSCamera()
		{
		}

		void FPSCamera::Update()
		{
			if (Keyboard::IsKeyPressed(Keyboard::Key::D))
			{
				this->position += Vector3(-speed, 0, 0);
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::A))
			{
				this->position -= Vector3(-speed, 0, 0);
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::W))
			{
				this->position += Vector3(0, 0, -speed);
			}

			if (Keyboard::IsKeyPressed(Keyboard::Key::S))
			{
				this->position -= Vector3(0, 0, -speed);
			}

			viewMatrix = Math::Matrix4::Translate(position);
		}
	}
}