#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace Graphics::API;
			using namespace Math;

			Sprite::Sprite(const Texture2D* texture2D, const Vector3& position, const Vector4& color) :
				texture2D(texture2D), position(position), rectangle((int)position.x, (int)position.y, texture2D->GetWidth(), texture2D->GetHeight()), scissorRectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Vector3& position, const Rectangle& scissorRectangle, const Vector4& color) :
				texture2D(texture2D), position(position), rectangle((int)position.x, (int)position.y, scissorRectangle.width, scissorRectangle.height), scissorRectangle(scissorRectangle), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, const Vector4& color) :
				texture2D(texture2D), position((float)rectangle.x, (float)rectangle.y, 0.0f), rectangle(rectangle), scissorRectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, const Rectangle& scissorRectangle, const Vector4& color) :
				texture2D(texture2D), position((float)rectangle.x, (float)rectangle.y, 0.0f), rectangle(rectangle), scissorRectangle(scissorRectangle), color(color)
			{
			}

			Sprite::~Sprite()
			{
			}

			void Sprite::SetTexture(const Graphics::API::Texture2D* texture2D)
			{
				this->texture2D = texture2D;
			}

			void Sprite::SetPosition(const Math::Vector3& position)
			{
				this->position = position;
			}

			void Sprite::SetColor(const Math::Vector4& color)
			{
				this->color = color;
			}

			void Sprite::SetRectangle(const Math::Rectangle& rectangle)
			{
				this->rectangle = rectangle;
			}

			void Sprite::SetScissorRectangle(const Math::Rectangle& scissorRectangle)
			{
				this->scissorRectangle = scissorRectangle;
			}
		}
	}
}