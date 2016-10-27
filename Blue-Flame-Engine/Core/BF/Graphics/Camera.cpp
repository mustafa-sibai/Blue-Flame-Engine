#include "Camera.h"

namespace BF
{
	namespace Graphics
	{
		Camera::Camera(const Math::Matrix4& projectionMatrix) : 
			projectionMatrix(projectionMatrix), viewMatrix(Math::Matrix4::Identity()), position(), rotation()
		{
		}

		Camera::~Camera()
		{
		}
	}
}