#pragma once
#include "BF/Math/Math.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			struct SpriteData
			{
				Math::Vector3 position;
			};

			class BF_API Sprite
			{
				public:
					Math::Vector3 position;
					Math::Vector2 size;
					Math::Vector4 color;

				public:
					Sprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color);
					~Sprite();
			};
		}
	}
}