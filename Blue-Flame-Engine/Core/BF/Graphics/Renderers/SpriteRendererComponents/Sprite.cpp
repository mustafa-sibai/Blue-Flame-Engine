#include "Sprite.h"
#include "BF/Graphics/Renderers/RenderLayer.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				using namespace std;
				using namespace Math;
				using namespace Graphics::API;
				using namespace BF::Graphics::Renderers;

				Sprite::Sprite(const Texture2D* texture2D, RenderLayer* renderLayer) :
					Renderable(Type::Sprite, Vector2i(), Vector2f(0.5f), 0, renderLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(Rectangle())
				{
					size = texture2D != nullptr ? Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Vector2i();
					scissorRectangle = texture2D != nullptr ? Rectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Rectangle();
				}

				Sprite::Sprite(const Sprite& sprite) :
					Renderable(Type::Sprite, sprite.size, sprite.pivot, sprite.zSortingOrder, sprite.renderLayer, sprite.color),
					texture2D(sprite.texture2D), scissorRectangle(sprite.scissorRectangle)
				{
					gameObject = sprite.gameObject;
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, RenderLayer* renderLayer) :
					Renderable(Type::Sprite, Vector2i(), pivot, 0, renderLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(Rectangle())
				{
					size = texture2D != nullptr ? Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Vector2i();
					scissorRectangle = texture2D != nullptr ? Rectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Rectangle();
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::Sprite, Vector2i(), pivot, zSortingOrder, renderLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(Rectangle())
				{
					size = texture2D != nullptr ? Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Vector2i();
					scissorRectangle = texture2D != nullptr ? Rectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Rectangle();
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::Sprite, Vector2i(), pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(Rectangle())
				{
					size = texture2D != nullptr ? Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Vector2i();
					scissorRectangle = texture2D != nullptr ? Rectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Rectangle();
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer, const Rectangle& scissorRectangle, const Color& color) :
					Renderable(Type::Sprite, Vector2i(scissorRectangle.width, scissorRectangle.height), pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(scissorRectangle)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, const Vector2i& size, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::Sprite, size, pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(Rectangle())
				{
					scissorRectangle = texture2D != nullptr ? Rectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height) : Rectangle();
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, const Vector2i& size, int zSortingOrder, RenderLayer* renderLayer, const Rectangle& scissorRectangle, const Color& color) :
					Renderable(Type::Sprite, size, pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(scissorRectangle)
				{
				}

				Sprite::~Sprite()
				{
				}

				Sprite& Sprite::operator=(Sprite& rhs)
				{
					Sprite temp(rhs);
					Swap(temp);
					return *this;
				}

				void Sprite::SetTexture(const Texture2D* texture2D)
				{
					this->texture2D = texture2D;
				}

				void Sprite::SetScissorRectangle(const Math::Rectangle& scissorRectangle)
				{
					this->scissorRectangle = scissorRectangle;
				}

				void Sprite::Swap(Sprite& rhs)
				{
					renderLayer = rhs.renderLayer;
					texture2D = rhs.texture2D;
					gameObject = rhs.gameObject;

					std::swap(type, rhs.type);
					std::swap(size, rhs.size);
					std::swap(pivot, rhs.pivot);
					std::swap(zSortingOrder, rhs.zSortingOrder);
					std::swap(color, rhs.color);
					std::swap(scissorRectangle, rhs.scissorRectangle);
				}
			}
		}
	}
}