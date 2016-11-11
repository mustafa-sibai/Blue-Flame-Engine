#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			Sprite::Sprite(Graphics::API::Texture2D* texture2D, Math::Vector3& position, Math::Vector2& size, Math::Vector4& color) :
				texture2D(texture2D), position(position), size(size), color(color)
			{
			}

			Sprite::~Sprite()
			{
			}
		}
	}
}