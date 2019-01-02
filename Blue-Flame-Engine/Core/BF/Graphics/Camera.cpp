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

		void Camera::Initialize(const Matrix4& projectionMatrix)
		{
			systemBuffer.modelMatrix = Matrix4::Identity();
			systemBuffer.viewMatrix = Matrix4::Identity();
			systemBuffer.projectionMatrix = projectionMatrix;

			constantBuffer.Create(0, sizeof(SystemBuffer), nullptr);
		}

		void Camera::Update()
		{
			constantBuffer.Update(0, sizeof(SystemBuffer), &systemBuffer);
		}

		void Camera::SetModelMatrix(const Matrix4& modelMatrix)
		{
			systemBuffer.modelMatrix = modelMatrix;
			constantBuffer.Update(0, sizeof(SystemBuffer), &systemBuffer);
		}

		void Camera::SetViewMatrix(const Matrix4& viewMatrix)
		{
			systemBuffer.viewMatrix = viewMatrix;
			constantBuffer.Update(0, sizeof(SystemBuffer), &systemBuffer);
		}

		void Camera::SetProjectionMatrix(const Matrix4& projectionMatrix)
		{
			systemBuffer.projectionMatrix = projectionMatrix;
			constantBuffer.Update(0, sizeof(SystemBuffer), &systemBuffer);
		}
	}
}