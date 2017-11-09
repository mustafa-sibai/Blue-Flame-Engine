#include "PhysicsEngine.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF;
		using namespace BF::Math;
		using namespace BF::Physics;

		std::vector<Rigidbody2D*> PhysicsEngine::rigidbodies;

		void PhysicsEngine::Add(Rigidbody2D* rigidbody2D)
		{
			rigidbodies.push_back(rigidbody2D);
		}

		void PhysicsEngine::Update()
		{
			for (size_t i = 0; i < rigidbodies.size(); i++)
			{
				if (rigidbodies[i]->useGravity)
					rigidbodies[i]->Update();

				if (i + 1 < rigidbodies.size())
				{
					if (rigidbodies[i]->CheckNextFrameCollision().Intersect(rigidbodies[i + 1]->CheckNextFrameCollision()))
					{
						if (rigidbodies[i]->veclotiy > 0)
						{
							rigidbodies[i]->veclotiy = 0;
							rigidbodies[i]->renderable.SetPosition(rigidbodies[i + 1]->renderable.GetPosition() - (float)rigidbodies[i]->renderable.GetRectangle().height);
						}
						else if (rigidbodies[i + 1]->veclotiy > 0)
						{
							if (!rigidbodies[i + 1]->correctCollisionPosition)
							{
								Math::Rectangle ir = rigidbodies[i]->CheckNextFrameCollision().IntersectRectangle(rigidbodies[i + 1]->CheckNextFrameCollision());

								Vector2f d = rigidbodies[i + 1]->direction;
								Vector2f v = Min((float)ir.width, (float)ir.height) * d;

								Math::Rectangle r = rigidbodies[i + 1]->CheckNextFrameCollision();
								Vector2f p((float)r.x, (float)r.y);

								rigidbodies[i + 1]->renderable.SetPosition(p - v);
								rigidbodies[i + 1]->correctCollisionPosition = true;
							}

							rigidbodies[i + 1]->veclotiy = 0;
						}

						BF_LOG_INFO("COLLIIISIONONNN !!");
					}
				}
			}
		}
	}
}