#pragma once
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Camera
		{
			protected:
				Math::Matrix4 projectionMatrix, viewMatrix;
				Math::Vector3 position, rotation;

			public:
				Camera(const Math::Matrix4& projectionMatrix);
				~Camera();

				inline void SetProjectionMatrix(const Math::Matrix4& projectionMatrix) { this->projectionMatrix = projectionMatrix; }
				inline const Math::Matrix4& GetProjectionMatrix() const { return projectionMatrix; }

				inline void SetViewMatrix(const Math::Matrix4& viewMatrix) { this->viewMatrix = viewMatrix; }
				inline const Math::Matrix4& GetViewMatrix() const { return viewMatrix; }
		};
	}
}