#pragma once
#include "BF/Application/GameNode.h"
#include "BF/Math/Math.h"
#include "BF/Graphics/Color.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API Renderable : public BF::Application::GameNode
			{
				friend class SpriteRenderer;

				private:
					struct FrontToBack
					{
						bool operator() (const Renderable* renderableA, const Renderable* renderableB) const
						{
							/*if (renderableA == nullptr || renderableB == nullptr)
								return true;
							if (renderableA->rectangle.y > renderableB->rectangle.y)
								return true;
							else if (renderableA->rectangle.y == renderableB->rectangle.y && renderableA->zLayer < renderableB->zLayer)
								return true;
							else if (renderableA->rectangle.y == renderableB->rectangle.y && renderableA->zLayer == renderableB->zLayer)
								return false;
							else*/
								return false;
						}
					};

					struct BackToFront
					{
						bool operator() (Renderable* renderableA, Renderable* renderableB) const
						{
							if (renderableA == nullptr)
								return false;

							if (renderableB == nullptr)
								return true;

							if (renderableA->rectangle.y <= renderableB->rectangle.y)
							{
								if (renderableA->zLayer < renderableB->zLayer)
								{
									renderableA->index--;
									renderableB->index++;
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
					BF::Math::Vector2f position;
					BF::Math::Rectangle rectangle;

				public:
					Color color;
					unsigned int zLayer;

				public:
					Renderable();
					Renderable(const BF::Math::Vector2f& position, const BF::Math::Rectangle& rectangle, unsigned int zLayer, const Color& color, NodeType nodeType);
					~Renderable();

					virtual void SetPosition(const BF::Math::Vector2f& position);
					virtual void SetRectangle(const BF::Math::Rectangle& rectangle);

					inline const BF::Math::Vector2f& GetPosition() const { return position; }
					inline const BF::Math::Rectangle& GetRectangle() const { return rectangle; }
			};
		}
	}
}