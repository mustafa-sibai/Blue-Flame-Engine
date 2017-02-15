#include "Camera.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;

		Camera::Camera()
		{
		}

		Camera::~Camera()
		{
		}

		void Camera::Initialize(const Math::Matrix4& projectionMatrix)
		{
			systemBuffer.modelMatrix = Matrix4::Identity();
			systemBuffer.viewMatrix = Matrix4::Identity();
			systemBuffer.projectionMatrix = projectionMatrix;

			constentBuffer.Create(sizeof(SystemBuffer), 0);
		}

		void Camera::Update()
		{
			constentBuffer.Update(&systemBuffer, sizeof(SystemBuffer));
		}

		void Camera::SetModelMatrix(const Math::Matrix4& modelMatrix)
		{
			systemBuffer.modelMatrix = modelMatrix;
			constentBuffer.Update(&systemBuffer, sizeof(SystemBuffer));
		}

		void Camera::SetViewMatrix(const Math::Matrix4& viewMatrix)
		{
			systemBuffer.viewMatrix = viewMatrix;
			constentBuffer.Update(&systemBuffer, sizeof(SystemBuffer));
		}

		void Camera::SetProjectionMatrix(const Math::Matrix4& projectionMatrix)
		{
			systemBuffer.projectionMatrix = projectionMatrix;
			constentBuffer.Update(&systemBuffer, sizeof(SystemBuffer));
		}
	}
}