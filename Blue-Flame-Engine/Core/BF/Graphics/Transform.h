#pragma once
#include "BF/ECS/Component.h"
#include "BF/Math/Vector3.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BF_API Transform : public BF::ECS::Component
		{
			BF::Math::Vector3f position;
			BF::Math::Vector3f rotation;
			BF::Math::Vector3f scale;
			float angle = 0.0f;
		};
	}
}