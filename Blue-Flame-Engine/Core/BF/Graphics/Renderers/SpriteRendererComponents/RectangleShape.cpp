#include "RectangleShape.h"
#include "BF/Graphics/Renderers/RenderLayer.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				using namespace std;
				using namespace BF::Math;
				using namespace BF::Graphics::Renderers;

				RectangleShape::RectangleShape(int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::RectangleShape, zSortingOrder, renderLayer, Color::Whites::White())
				{
					/*worldTransformation = Matrix4::Identity();
					transformation = Matrix4::Identity();
					scale = Vector3f(1);*/
				}

				RectangleShape::RectangleShape(int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::RectangleShape, zSortingOrder, renderLayer, color)
				{
					/*worldTransformation = Matrix4::Identity();
					transformation = Matrix4::Identity();
					scale = Vector3f(1);*/
				}

				RectangleShape::~RectangleShape()
				{
				}

				void RectangleShape::SetPosition(Vector2i& size, Vector2f& pivot, Vector2f& position)
				{
					this->size = size;
					this->position = position;
					/*this->pivot = pivot;

					transformation = Matrix4::Translate(position) *
						Matrix4::Rotate(angle, rotation) *
						Matrix4::Scale(scale);

					position = transformation.GetTranslationVector();

					direction = (position - prevPos).Normalize();
					worldTransformation = worldTransformation * transformation;*/



					//if (transforms[i]->transformables[j]->updatePivotAndSize)
					/*{
						Vector2i scaledSprite = Vector2i(size.x * scale.x, size.y * scale.y);
						edges = BF::Math::Rectangle(position.x, position.y, scaledSprite.x, scaledSprite.y, pivot).GetEdgeOffsetByPivotAtOrigin();
						//updatePivotAndSize = false;
					}*/

					//Top Left
					/*corners[0] = Vector2f(position.x + edges.x, edges.y + position.y);

					//Top Right
					corners[1] = Vector2f(position.x + edges.width, edges.y + position.y);

					//Bottom Right
					corners[2] = Vector2f(position.x + edges.width, edges.height + position.y);

					//Bottom Left
					corners[3] = Vector2f(position.x + edges.x, edges.y + position.y);*/

				}
			}
		}
	}
}