#include "Light.h"

namespace BF
{
	namespace Graphics
	{
		Light::Light()
		{
		}

		Light::~Light()
		{
		}

		void Light::SetLight(Math::Vector3 position, Math::Vector4 color)
		{
			this->position = position;
			this->color = color;
		}
	}
}