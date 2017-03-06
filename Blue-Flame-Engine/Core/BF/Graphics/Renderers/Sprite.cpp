#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace Graphics::API;
			using namespace Math;

			Sprite::Sprite() :
				texture2D(nullptr), position(), zLayer(0), rectangle(), scissorRectangle(), color()
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Vector2& position, unsigned int zLayer, const Color& color) :
				texture2D(texture2D), position(position), zLayer(zLayer), rectangle((int)position.x, (int)position.y, texture2D->GetTextureData().width, texture2D->GetTextureData().height),
				scissorRectangle(0, 0, texture2D->GetTextureData().width, texture2D->GetTextureData().height), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Vector2& position, unsigned int zLayer, const Rectangle& scissorRectangle, const Color& color) :
				texture2D(texture2D), position(position), zLayer(zLayer), rectangle((int)position.x, (int)position.y, scissorRectangle.width, scissorRectangle.height),
				scissorRectangle(scissorRectangle), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, unsigned int zLayer, const Color& color) :
				texture2D(texture2D), position((float)rectangle.x, (float)rectangle.y), zLayer(zLayer), rectangle(rectangle),
				scissorRectangle(0, 0, texture2D->GetTextureData().width, texture2D->GetTextureData().height), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, unsigned int zLayer, const Rectangle& scissorRectangle, const Color& color) :
				texture2D(texture2D), position((float)rectangle.x, (float)rectangle.y), zLayer(zLayer), rectangle(rectangle),
				scissorRectangle(scissorRectangle), color(color)
			{
			}

			Sprite::~Sprite()
			{
			}

			void Sprite::SetTexture(const Graphics::API::Texture2D* texture2D)
			{
				this->texture2D = texture2D;
			}

			void Sprite::SetPosition(const Math::Vector2& position)
			{
				this->position = position;
				this->rectangle.x = (int)position.x;
				this->rectangle.y = (int)position.y;
			}

			void Sprite::SetColor(const Color& color)
			{
				this->color = color;
			}

			void Sprite::SetRectangle(const Math::Rectangle& rectangle)
			{
				this->rectangle = rectangle;
				this->position.x = (float)rectangle.x;
				this->position.y = (float)rectangle.y;
			}

			void Sprite::SetScissorRectangle(const Math::Rectangle& scissorRectangle)
			{
				this->scissorRectangle = scissorRectangle;
			}

			void Sprite::SetZLayer(unsigned int zLayer)
			{
				this->zLayer = zLayer;
			}
		}
	}
}