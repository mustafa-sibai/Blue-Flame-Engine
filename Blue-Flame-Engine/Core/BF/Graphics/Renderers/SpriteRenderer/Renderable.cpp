#include "Renderable.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;
			using namespace BF::ECS;

			/*Renderable::Renderable() :
				position(), zLayer(0), rectangle(), color()
			{
				Component::type = Component::Type::Renderable;
			}*/

			Renderable::Renderable(const Vector2i& size, unsigned int zLayer, const Color& color, RenderableType renderableType) :
				size(size), zLayer(zLayer), color(color), renderableType(renderableType)
			{
				Component::type = Component::Type::Renderable;
			}

			Renderable::~Renderable()
			{
			}

			/*void Renderable::SetPosition(const Vector2f& position)
			{
				this->position = position;
				this->rectangle.x = (int)position.x;
				this->rectangle.y = (int)position.y;
			}

			void Renderable::SetRectangle(const Rectangle& rectangle)
			{
				this->rectangle = rectangle;
				this->position.x = (float)rectangle.x;
				this->position.y = (float)rectangle.y;
			}*/
		}
	}
}