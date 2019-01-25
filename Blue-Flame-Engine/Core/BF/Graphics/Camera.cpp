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
			Component(Component::Type::Camera)
		{
			systemBuffer.modelMatrix = Matrix4::Identity();
			systemBuffer.viewMatrix = Matrix4::Identity();
			systemBuffer.projectionMatrix = projectionMatrix;
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