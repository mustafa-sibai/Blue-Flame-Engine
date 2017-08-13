#pragma once
#include "BF/Math/Math.h"
#include "BF/Graphics/Color.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API Renderable
			{
				friend class SpriteRenderer;

				private:
					struct FrontToBack
					{
						bool operator() (const Renderable* renderableA, const Renderable* renderableB) const
						{
							if (renderableA->rectangle.y > renderableB->rectangle.y)
								return true;
							else if (renderableA->rectangle.y == renderableB->rectangle.y && renderableA->zLayer < renderableB->zLayer)
								return true;
							else if (renderableA->rectangle.y == renderableB->rectangle.y && renderableA->zLayer == renderableB->zLayer)
								return false;
							else
								return false;
						}
					};

					struct BackToFront
					{
						bool operator() (const Renderable* renderableA, const Renderable* renderableB) const
						{
							if (renderableA->rectangle.y <= renderableB->rectangle.y)
							{
								if (renderableA->zLayer < renderableB->zLayer)
								{
									return true;
								}
							}

							if (renderableA->rectangle.y < renderableB->rectangle.y)
							{
								if (renderableA->zLayer == renderableB->zLayer)
								{
									return true;
								}
							}

							if (renderableA->rectangle.y >= renderableB->rectangle.y)
							{
								if (renderableA->zLayer < renderableB->zLayer)
								{
									return true;
								}
							}

							return false;
						}
					};

				protected:
					Math::Vector2 position;
					Math::Rectangle rectangle;

				public:
					Color color;
					unsigned int zLayer;

				public:
					enum class Type { Null, Line, RegularPolygon, Sprite, Text };
					Type type;

					Renderable();
					Renderable(const Math::Vector2& position, const Math::Rectangle& rectangle, unsigned int zLayer, const Color& color, Type type);
					~Renderable();

					void SetPosition(const Math::Vector2& position);
					void SetRectangle(const Math::Rectangle& rectangle);

					inline const Math::Vector2& GetPosition() const { return position; }
					inline const Math::Rectangle& GetRectangle() const { return rectangle; }
			};
		}
	}
}