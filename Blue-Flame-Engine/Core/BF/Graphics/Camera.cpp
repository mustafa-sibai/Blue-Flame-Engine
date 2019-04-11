#include "Camera.h"
#include "BF/Engine.h"
#include "BF/Graphics/CameraManager.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;
		using namespace BF::Graphics;
		using namespace BF::Graphics::API;

		Camera::Camera(const Matrix4& projectionMatrix) :
			cameraManager(nullptr), bufferClearType(BufferClearType::ColorAndDepth)
		{
			type = IComponent::Type::Camera;
			
			modelMatrix = Matrix4::Identity();
			viewMatrix = Matrix4::Identity();
			this->projectionMatrix = projectionMatrix;
		}

		Camera::~Camera()
		{
		}

		void Camera::SetAsMainCamera()
		{
			cameraManager->SetMainCamera(this);
		}

		void Camera::SetClearType(BufferClearType bufferClearType)
		{
			this->bufferClearType = bufferClearType;
		}

		void Camera::SetClearColor(const Color& clearColor)
		{
			this->clearColor = clearColor;
		}

		void Camera::SetModelMatrix(const Matrix4& modelMatrix)
		{
			this->modelMatrix = modelMatrix;
			cameraManager->constantBufferManager.UpdateCameraModel(modelMatrix);
		}

		void Camera::SetViewMatrix(const Matrix4& viewMatrix)
		{
			this->viewMatrix = viewMatrix;
			//cameraManager->constantBufferManager.UpdateCameraView(viewMatrix);
		}

		void Camera::SetProjectionMatrix(const Matrix4& projectionMatrix)
		{
			this->projectionMatrix = projectionMatrix;
			//cameraManager->constantBufferManager.UpdateCameraProjection(projectionMatrix);
		}

		Vector3f Camera::ScreenToWorldPoint(const Vector3f& position, const Vector2f& pivot)
		{
			//640 - 640, 360 - 360
			//1280, 720

			Vector2i windowSize = Engine::GetWindow().GetClientSize();

			Vector2f convertedSize =  Vector2f(windowSize.x * pivot.x, windowSize.y * pivot.y);

			return Vector3f(position.x - convertedSize.x, -(position.y - convertedSize.y), 0);
		}

		void Camera::Clear()
		{
			BF::Engine::GetContext().Clear(bufferClearType, clearColor);
		}

		void Camera::SwapBuffers()
		{
			BF::Engine::GetContext().SwapBuffers();
		}
	}
}