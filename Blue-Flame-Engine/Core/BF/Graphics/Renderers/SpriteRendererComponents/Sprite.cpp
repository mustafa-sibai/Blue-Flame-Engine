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

				Sprite::Sprite(const Texture2D* texture2D, RenderLayer& renderLayer) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), Vector2f(0.5f), 0, renderLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, RenderLayer& renderLayer) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), pivot, 0, renderLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), pivot, zSortingOrder, renderLayer, Color::Whites::White()),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					Renderable(Vector2i(texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer, const Rectangle& scissorRectangle, const Color& color) :
					Renderable(Vector2i(scissorRectangle.width, scissorRectangle.height), pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(scissorRectangle)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, const Vector2i& size, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					Renderable(size, pivot, zSortingOrder, renderLayer, color),
					texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
				{
				}

				Sprite::Sprite(const Texture2D* texture2D, const Vector2f& pivot, const Vector2i& size, int zSortingOrder, RenderLayer& renderLayer, const Rectangle& scissorRectangle, const Color& color) :
					Renderable(size, pivot, zSortingOrder, renderLayer, color),
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