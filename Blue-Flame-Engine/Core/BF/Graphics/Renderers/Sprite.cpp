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
				texture2D(texture2D), position(position), rectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), sourceRectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Vector3& position, const Rectangle& sourceRectangle, const Vector4& color) :
				texture2D(texture2D), position(position), rectangle(0, 0, sourceRectangle.width, sourceRectangle.height), sourceRectangle(sourceRectangle), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, const Vector4& color) :
				texture2D(texture2D), position(), rectangle(rectangle), sourceRectangle(0, 0, texture2D->GetWidth(), texture2D->GetHeight()), color(color)
			{
			}

			Sprite::Sprite(const Texture2D* texture2D, const Rectangle& rectangle, const Rectangle& sourceRectangle, const Vector4& color) :
				texture2D(texture2D), position(), rectangle(rectangle), sourceRectangle(sourceRectangle), color(color)
			{
			}

			Sprite::~Sprite()
			{
			}
		}
	}
}