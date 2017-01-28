#include "Camera.h"

namespace BF
{
	namespace Graphics
	{
		Camera::Camera(const Math::Matrix4& projectionMatrix) : 
			projectionMatrix(projectionMatrix), viewMatrix(Math::Matrix4::Identity()), position()
		{
			position = Math::Vector3(0.0f, 0.0f, 0.0f);
			direction = Math::Vector3(0.0f, 0.0f, 0.0f);
		}

		Camera::~Camera()
		{
		}
	}
}