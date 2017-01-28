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
				float renderingType;
			};

			class BF_API Sprite
			{
				friend class SpriteRenderer;

				private:
					struct FrontToBack
					{
						bool operator() (const Sprite* spriteA, const Sprite* spriteB) const
						{
							return spriteB->rectangle.y < spriteA->rectangle.y;
						}
					};

					struct BackToFront
					{
						bool operator() (const Sprite* spriteA, const Sprite* spriteB) const
						{
							return spriteA->rectangle.y < spriteB->rectangle.y;
						}
					};

					const Graphics::API::Texture2D* texture2D;
					Math::Vector3 position;
					Math::Rectangle rectangle;
					Math::Rectangle scissorRectangle;
					Math::Vector4 color;
					bool submitted, recentlySubmitted;
					unsigned int indexInVector;

				public:
					Sprite() = default;
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector3& position, const Math::Vector4& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector3& position, const Math::Rectangle& scissorRectangle, const Math::Vector4& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, const Math::Vector4& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, const Math::Rectangle& scissorRectangle, const Math::Vector4& color);
					~Sprite();

					void SetTexture(const Graphics::API::Texture2D* texture2D);
					void SetPosition(const Math::Vector3& position);
					void SetColor(const Math::Vector4& color);
					void SetRectangle(const Math::Rectangle& rectangle);
					void SetScissorRectangle(const Math::Rectangle& scissorRectangle);

					inline const Graphics::API::Texture2D* GetTexture() const { return texture2D; }
					inline const Math::Vector3& GetPosition() const { return position; }
					inline const Math::Vector4& GetColor() const { return color; }
					inline const Math::Rectangle& GetRectangle() const { return rectangle; }
					inline const Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }
			};
		}
	}
}