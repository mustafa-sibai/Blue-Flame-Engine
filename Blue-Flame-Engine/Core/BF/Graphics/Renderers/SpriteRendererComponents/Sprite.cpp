#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				using namespace Math;
				using namespace Graphics::API;

				Sprite::Sprite(const Texture2D* texture2D) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), Vector2f(0.5f), 0, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), pivot, 0, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, unsigned int zLayer) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), pivot, zLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, unsigned int zLayer, const Color& color) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), pivot, zLayer, color),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, unsigned int zLayer, const Rectangle& scissorRectangle, const Color& color) :
					Renderable(Vector2i(scissorRectangle.width, scissorRectangle.height), pivot, zLayer, color),
					texture2D(texture2D), scissorRectangle(scissorRectangle)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, const Vector2i& size, unsigned int zLayer, const Color& color) :
					Renderable(size, pivot, zLayer, color),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, const Vector2i& size, unsigned int zLayer, const Rectangle& scissorRectangle, const Color& color) :
					Renderable(size, pivot, zLayer, color),
					texture2D(texture2D), scissorRectangle(scissorRectangle)
				{
				}

				Sprite::~Sprite()
				{
				}

				void Sprite::SetTexture(const Texture2D* texture2D)
				{
					this->texture2D = texture2D;
				}

				void Sprite::SetScissorRectangle(const Math::Rectangle& scissorRectangle)
				{
					this->scissorRectangle = scissorRectangle;
				}
			}
		}
	}
}