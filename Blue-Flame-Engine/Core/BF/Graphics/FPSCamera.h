#pragma once
#include "BF/Graphics/Camera.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API FPSCamera : public Camera
		{
			private:
				float movmentSpeed, sensitivity, yaw, pitch;
				bool lockMouseToCenter;

			public:
				BF::Math::Vector3f cameraFront, cameraUp;
				BF::Math::Vector2f windowCenter;

			public:
				FPSCamera(const BF::Math::Matrix4& projectionMatrix);
				~FPSCamera();

				void Initialize() override;
				void Update() override;
		};
	}
}