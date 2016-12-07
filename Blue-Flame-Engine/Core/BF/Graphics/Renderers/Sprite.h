#pragma once
#include "BF/Math/Math.h"
#include "BF/Graphics/API/Texture2D.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			struct BF_API SpriteBuffer
			{
				Math::Vector3 position;
				Math::Vector4 color;
				Math::Vector2 UV;
				float textureID;
			};

			class BF_API Sprite
			{
				public:
					const Graphics::API::Texture2D* texture2D;
					Math::Vector3 position;
					Math::Rectangle rectangle;
					Math::Rectangle sourceRectangle;
					Math::Vector4 color;

				public:
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector3& position, const Math::Vector4& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector3& position, const Math::Rectangle& sourceRectangle, const Math::Vector4& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, const Math::Vector4& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, const Math::Rectangle& sourceRectangle, const Math::Vector4& color);
					~Sprite();
			};
		}
	}
}