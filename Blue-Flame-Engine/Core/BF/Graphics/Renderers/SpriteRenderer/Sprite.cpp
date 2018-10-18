#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace Math;
			using namespace Graphics::API;

			/*Sprite::Sprite() :
				texture2D(nullptr), scissorRectangle(), Renderable(Vector2f(), Math::Rectangle(), 0, Color(), RenderableType::Sprite)
			{
			}*/

			Sprite::Sprite(const Texture2D* texture2D, const Vector2f& position, unsigned int zLayer, const Color& color) :
				Renderable(position, Math::Rectangle((int)position.x, (int)position.y, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height), zLayer, color, RenderableType::Sprite),
				texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Vector2f& position, unsigned int zLayer, const Rectangle& scissorRectangle, const Color& color) :
				Renderable(position, Math::Rectangle((int)position.x, (int)position.y, scissorRectangle.width, scissorRectangle.height), zLayer, color, RenderableType::Sprite),
				texture2D(texture2D), scissorRectangle(scissorRectangle)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, unsigned int zLayer, const Color& color) :
				Renderable(Vector2f((float)rectangle.x, (float)rectangle.y), rectangle, zLayer, color, RenderableType::Sprite),
				texture2D(texture2D), scissorRectangle(0, 0, texture2D->GetTextureData()->width, texture2D->GetTextureData()->height)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, unsigned int zLayer, const Rectangle& scissorRectangle, const Color& color) :
				Renderable(Vector2f((float)rectangle.x, (float)rectangle.y), rectangle, zLayer, color, RenderableType::Sprite),
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