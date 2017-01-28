#pragma once
#include "Camera.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API FPSCamera : public Camera
		{
			private:
				float movmentSpeed, sensitivity, yaw, pitch;

			public:
				Math::Vector3 cameraFront, cameraUp;
				Math::Vector2 windowCenter;

			public:
				FPSCamera(const Math::Matrix4& projectionMatrix);
				~FPSCamera();

				void Initialize();
				void Update();
		};
	}
}