#include "Camera.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;
		using namespace BF::Graphics;
		using namespace BF::Graphics::API;

		Camera::Camera(const Matrix4& projectionMatrix) :
			Component(Component::Type::Camera)
		{
			systemBuffer.modelMatrix = Matrix4::Identity();
			systemBuffer.viewMatrix = Matrix4::Identity();
			systemBuffer.projectionMatrix = projectionMatrix;
		}

		Camera::~Camera()
		{
		}

		void Camera::Initialize()
		{
			constantBuffer.Create(0, sizeof(SystemBuffer), nullptr);
		}

		void Camera::Update()
		{
			constantBuffer.Update(0, sizeof(SystemBuffer), &systemBuffer);
		}

		void Camera::Clear(BufferClearType bufferClearType, const Color& color)
		{
			BF::Engine::GetContext().Clear(bufferClearType, color);
		}

		void Camera::SwapBuffers()
		{
			BF::Engine::GetContext().SwapBuffers();
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