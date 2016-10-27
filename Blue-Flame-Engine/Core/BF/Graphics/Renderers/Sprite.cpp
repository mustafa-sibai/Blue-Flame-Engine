#include "Sprite.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			Sprite::Sprite(Math::Vector3 position, Math::Vector2 size, Math::Vector4 color) : 
				position(position), size(size), color(color)
			{
			}

			Sprite::~Sprite()
			{
			}
		}
	}
}