#pragma once
#include "BF/Physics/Collider.h"
#include "BF/Math/Vector2.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class BFE_API BoxCollider2D : public Collider<BoxCollider2D>
		{
			friend class BF::Physics::PhysicsEngine;

		private:
			int leftEdge, rightEdge, topEdge, bottomEdge;

		public:
			int x, y, width, height;
			BF::Math::Vector2f pivot;

			BoxCollider2D();
			BoxCollider2D(int x, int y, int width, int height);
			BoxCollider2D(int x, int y, int width, int height, const BF::Math::Vector2f& pivot);
			~BoxCollider2D();

		private:
			void CalculateEdges(int offsetX, int offsetY);
			BoxCollider2D GetIntersectionArea(const BoxCollider2D& boxCollider2D) const;
		};
	}
}