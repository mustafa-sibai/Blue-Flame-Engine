#pragma once
#include "BF/Graphics/Camera.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API FPSCamera : public Camera
		{
			private:
				float movmentSpeed, sensitivity, yaw, pitch;
				bool lockMouseToCenter;

			public:
				Math::Vector3 cameraFront, cameraUp;
				Math::Vector2 windowCenter;

			public:
				FPSCamera();
				~FPSCamera();

				void Initialize(const Math::Matrix4& projectionMatrix) override;
				void Update() override;
		};
	}
}