#pragma once
#include "BF/Math/Math.h"
#include "BF/Graphics/Color.h"
#include "BF/Graphics/API/Texture2D.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			struct BF_API SpriteBuffer
			{
				Math::Vector2 position;
				Color color;
				Math::Vector2 UV;
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
							if (spriteA->rectangle.y > spriteB->rectangle.y)
								return true;
							else if (spriteA->rectangle.y == spriteB->rectangle.y && spriteA->zLayer < spriteB->zLayer)
								return true;
							else if (spriteA->rectangle.y == spriteB->rectangle.y && spriteA->zLayer == spriteB->zLayer)
								return false;
							else
								return false;
						}
					};

					struct BackToFront
					{
						bool operator() (const Sprite* spriteA, const Sprite* spriteB) const
						{
							if (spriteA->rectangle.y < spriteB->rectangle.y)
								return true;
							else if (spriteA->rectangle.y == spriteB->rectangle.y && spriteA->zLayer < spriteB->zLayer)
								return true;
							else if (spriteA->rectangle.y == spriteB->rectangle.y && spriteA->zLayer == spriteB->zLayer)
								return false;
							else
								return false;
						}
					};

					const Graphics::API::Texture2D* texture2D;
					Math::Vector2 position;
					Math::Rectangle rectangle;
					Math::Rectangle scissorRectangle;
					Color color;
					unsigned int zLayer;

				public:
					Sprite() = default;
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector2& position, unsigned int zLayer, const Color& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector2& position, unsigned int zLayer, const Math::Rectangle& scissorRectangle, const Color& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, unsigned int zLayer, const Color& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, unsigned int zLayer, const Math::Rectangle& scissorRectangle, const Color& color);
					~Sprite();

					void SetTexture(const Graphics::API::Texture2D* texture2D);
					void SetPosition(const Math::Vector2& position);
					void SetColor(const Color& color);
					void SetRectangle(const Math::Rectangle& rectangle);
					void SetScissorRectangle(const Math::Rectangle& scissorRectangle);
					void SetZLayer(unsigned int zLayer);

					inline const Graphics::API::Texture2D* GetTexture() const { return texture2D; }
					inline const Math::Vector2& GetPosition() const { return position; }
					inline const Color& GetColor() const { return color; }
					inline const Math::Rectangle& GetRectangle() const { return rectangle; }
					inline const Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }
					inline unsigned int GetZLayer() const { return zLayer; }
			};
		}
	}
}