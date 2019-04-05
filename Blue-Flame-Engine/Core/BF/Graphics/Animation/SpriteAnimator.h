#pragma once
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API SpriteAnimator : public BF::ECS::Component<SpriteAnimator>
			{
			public:
				SpriteAnimator();
				~SpriteAnimator();
			};
		}
	}
}