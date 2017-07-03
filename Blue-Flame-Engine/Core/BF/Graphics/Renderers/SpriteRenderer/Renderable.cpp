#include "Renderable.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			Renderable::Renderable() :
				position(), zLayer(0), rectangle(), color()
			{
			}

			Renderable::Renderable(const Math::Vector2& position, const Math::Rectangle& rectangle, unsigned int zLayer, const Color& color, Type type) :
				position(position), rectangle(rectangle), zLayer(zLayer), color(color), type(type)
			{
			}

			Renderable::~Renderable()
			{
			}

			void Renderable::SetPosition(const Math::Vector2& position)
			{
				this->position = position;
				this->rectangle.x = (int)position.x;
				this->rectangle.y = (int)position.y;
			}

			void Renderable::SetRectangle(const Math::Rectangle& rectangle)
			{
				this->rectangle = rectangle;
				this->position.x = (float)rectangle.x;
				this->position.y = (float)rectangle.y;
			}
		}
	}
}