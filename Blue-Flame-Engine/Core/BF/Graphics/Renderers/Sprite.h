#pragma once
#include "BF/Math/Math.h"
#include "BF/Graphics/API/Texture2D.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			struct BF_API SpriteData
			{
				Math::Vector3 position;
				Math::Vector4 color;
				Math::Vector2 UV;
			};

			class BF_API Sprite
			{
				public:
					Math::Vector3 position;
					Math::Vector2 size;
					Math::Vector4 color;
					Graphics::API::Texture2D* texture2D;

				public:
					Sprite(Graphics::API::Texture2D* texture2D, Math::Vector3& position, Math::Vector2& size, Math::Vector4& color);
					~Sprite();
			};
		}
	}
}