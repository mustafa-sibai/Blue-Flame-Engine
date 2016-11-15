#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			Sprite::Sprite(Graphics::API::Texture2D* texture2D, Math::Vector3& position, Math::Vector4& color) :
				texture2D(texture2D), position(position), rectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), sourceRectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), color(color)
			{
			}

			Sprite::Sprite(Graphics::API::Texture2D* texture2D, Math::Vector3& position, Math::Rectangle& sourceRectangle, Math::Vector4& color) :
				texture2D(texture2D), position(position), rectangle(0, 0, sourceRectangle.width, sourceRectangle.height), sourceRectangle(sourceRectangle), color(color)
			{
			}

			Sprite::Sprite(Graphics::API::Texture2D* texture2D, Math::Rectangle& rectangle, Math::Vector4& color) :
				texture2D(texture2D), position(), rectangle(rectangle), sourceRectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), color(color)
			{
			}

			Sprite::Sprite(Graphics::API::Texture2D* texture2D, Math::Rectangle& rectangle, Math::Rectangle& sourceRectangle, Math::Vector4& color) :
				texture2D(texture2D), position(), rectangle(rectangle), sourceRectangle(sourceRectangle), color(color)
			{
			}

			Sprite::~Sprite()
			{
			}
		}
	}
}