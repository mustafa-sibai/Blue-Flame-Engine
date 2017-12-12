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
				BF::Math::Vector3f cameraFront, cameraUp;
				BF::Math::Vector2f windowCenter;

			public:
				FPSCamera();
				~FPSCamera();

				void Initialize(const BF::Math::Matrix4& projectionMatrix) override;
				void Update() override;
		};
	}
}