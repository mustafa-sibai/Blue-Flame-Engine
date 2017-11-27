#include "Renderable.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;
			using namespace BF::Application;

			Renderable::Renderable() :
				position(), zLayer(0), rectangle(), color()
			{
			}

			Renderable::Renderable(const Vector2f& position, const Rectangle& rectangle, unsigned int zLayer, const Color& color, NodeType nodeType) :
				position(position), rectangle(rectangle), zLayer(zLayer), color(color)
			{
				GameNode::nodeType = nodeType;
			}

			Renderable::~Renderable()
			{
			}

			void Renderable::SetPosition(const Vector2f& position)
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
			}
		}
	}
}