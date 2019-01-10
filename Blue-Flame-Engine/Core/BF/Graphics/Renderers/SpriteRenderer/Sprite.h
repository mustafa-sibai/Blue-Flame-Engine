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
				BF::Math::Vector2f position;
				Color color;
				BF::Math::Vector2f UV;
				float renderingType;
			};

			class BF_API Sprite : public Renderable
			{
				friend class SpriteRenderer;

				private:
					const BF::Graphics::API::Texture2D* texture2D;
					BF::Math::Rectangle scissorRectangle;

				public:
					//Sprite();
					Sprite(const BF::Graphics::API::Texture2D* texture2D, unsigned int zLayer, const Color& color);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, unsigned int zLayer, const BF::Math::Rectangle& scissorRectangle, const Color& color);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2i& size, unsigned int zLayer, const Color& color);
					Sprite(const BF::Graphics::API::Texture2D* texture2D, const BF::Math::Vector2i& size, unsigned int zLayer, const BF::Math::Rectangle& scissorRectangle, const Color& color);
					~Sprite();

					void SetTexture(const BF::Graphics::API::Texture2D* texture2D);
					void SetScissorRectangle(const BF::Math::Rectangle& scissorRectangle);

					inline const BF::Graphics::API::Texture2D* GetTexture() const { return texture2D; }
					inline const BF::Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }
			};
		}
	}
}