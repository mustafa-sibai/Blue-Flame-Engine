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
				{
					rigidbodies[i]->Update();
				}

				if (i + 1 < rigidbodies.size())
				{
					if (rigidbodies[i]->renderable.GetRectangle().Intersect(rigidbodies[i + 1]->renderable.GetRectangle()))
					{
						if (rigidbodies[i]->veclotiy > 0)
						{
							rigidbodies[i]->veclotiy = 0;
							rigidbodies[i]->renderable.SetPosition(rigidbodies[i + 1]->renderable.GetPosition() -
								rigidbodies[i]->renderable.GetRectangle().height);
						}
						else if (rigidbodies[i + 1]->veclotiy > 0)
						{
							Math::Vector2 ov = rigidbodies[i + 1]->veclotiy;
							rigidbodies[i + 1]->veclotiy = 0;
							//rigidbodies[i + 1]->speed = 0;
							//rigidbodies[i + 1]->direction = 0;
							if (!rigidbodies[i + 1]->correctCollisionPosition)
							{
								Math::Rectangle r = rigidbodies[i]->renderable.GetRectangle().IntersectRectangle(rigidbodies[i + 1]->renderable.GetRectangle());



								Vector2 d = rigidbodies[i + 1]->direction;

								d.x = d.x > 0.1 ? 1.0f : 0.0f;
								d.y = d.y > 0.1 ? 1.0f : 0.0f;

								Vector2 v = Min(r.width, r.height) * d;

								BF_LOG_INFO("xxx %i %i %i %i", r.x, r.y, r.width, r.height);

								rigidbodies[i + 1]->renderable.SetPosition(rigidbodies[i + 1]->renderable.GetPosition() - v);
								rigidbodies[i + 1]->correctCollisionPosition = true;
								//rigidbodies[i + 1]->speed = 150;
							}
						}

						BF_LOG_INFO("COLLIIISIONONNN !!");
					}
				}
			}
		}
	}
}