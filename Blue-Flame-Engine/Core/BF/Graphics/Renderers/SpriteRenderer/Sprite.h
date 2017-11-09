#pragma once
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			struct BF_API SpriteBuffer
			{
				Math::Vector2f position;
				Color color;
				Math::Vector2f UV;
				float renderingType;
			};

			class BF_API Sprite : public Renderable
			{
				friend class SpriteRenderer;

				private:
					const Graphics::API::Texture2D* texture2D;
					Math::Rectangle scissorRectangle;

				public:
					Sprite();
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector2f& position, unsigned int zLayer, const Color& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Vector2f& position, unsigned int zLayer, const Math::Rectangle& scissorRectangle, const Color& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, unsigned int zLayer, const Color& color);
					Sprite(const Graphics::API::Texture2D* texture2D, const Math::Rectangle& rectangle, unsigned int zLayer, const Math::Rectangle& scissorRectangle, const Color& color);
					~Sprite();

					void SetTexture(const Graphics::API::Texture2D* texture2D);
					void SetScissorRectangle(const Math::Rectangle& scissorRectangle);

					inline const Graphics::API::Texture2D* GetTexture() const { return texture2D; }
					inline const Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }
			};
		}
	}
}