#include "PhysicsEngine.h"
#include "BF/System/Debug.h"
#include "BF/Scripting/Script.h"
#include "BF/Physics/Rigidbody2D.h"

namespace BF
{
	namespace Physics
	{
		using namespace BF::ECS;
		using namespace BF::Math;
		using namespace BF::Graphics;
		using namespace BF::Scripting;

		PhysicsEngine::PhysicsEngine()
		{
		}

		PhysicsEngine::~PhysicsEngine()
		{
		}

		void PhysicsEngine::Initialize()
		{
		}

		void PhysicsEngine::Load()
		{
		}

		void PhysicsEngine::PostLoad()
		{
		}

		void PhysicsEngine::Update(double deltaTime)
		{
			for (size_t i = 0; i < physicsObjects.size(); i++)
			{
				switch (physicsObjects[i]->type)
				{
				case IPhysicsObject::Type::Rigidbody2D:
				{
					/*BF::Graphics::Transform* transform = physicsObjects[i]->gameObject->GetComponent<Transform>();
					Vector3f position = transform->GetPosition();
					Rigidbody2D* rigidbody2D = (Rigidbody2D*)physicsObjects[i];

					rigidbody2D->veclotiy += rigidbody2D->direction * rigidbody2D->speed;

					position += Vector3f(rigidbody2D->veclotiy.x, rigidbody2D->veclotiy.y, 0);
					transform->SetPosition(position);*/












					//BFE_LOG_INFO("d: " + rigidbody2D->direction + " p: " + position, "");
					break;
				}
				case IPhysicsObject::Type::Collider:
				{
					BoxCollider2D* boxA = (BoxCollider2D*)physicsObjects[i];

					for (size_t j = 0; j < physicsObjects.size(); j++)
					{
						if (physicsObjects[i] == physicsObjects[j] || physicsObjects[j]->type != IPhysicsObject::Type::Collider)
							continue;

						BoxCollider2D* boxB = (BoxCollider2D*)physicsObjects[j];

						Transform* boxATransform = boxA->gameObject->GetComponent<Transform>();
						Transform* boxBTransform = boxB->gameObject->GetComponent<Transform>();

						if (IsColliding(boxA, boxB))
						{
							IScript* script = boxA->gameObject->GetComponent<IScript>();

							if (script != nullptr)
								script->OnTriggerEnter(*boxB);



							Vector3f positionA = boxATransform->GetPosition();
							Vector3f positionB = boxBTransform->GetPosition();


							BoxCollider2D ir = boxA->GetIntersectionArea(*boxB);

							//BFE_LOG_INFO("x " + std::to_string(ir.x) + " y " + std::to_string(ir.y) + " w " + std::to_string(ir.width) + " h " + std::to_string(ir.height), "");

							Vector3f v = Min((float)ir.width, (float)ir.height) * boxATransform->GetDirection();
							Vector3f r = boxATransform->GetPosition() - v;

							Vector3f allowedDir = Vector3f(0, -1, 0);// - v;
							boxATransform->SetPosition(r);
							//boxATransform->SetPosition(boxATransform->GetPosition() + boxATransform->GetDirection() * 0.05f);
							BFE_LOG_INFO(r, "");
						}


					}
					break;
				}
				}
			}
		}

		void PhysicsEngine::Render()
		{
		}

		void PhysicsEngine::AddComponent(IComponent* component)
		{
			physicsObjects.emplace_back((IPhysicsObject*)component);
		}

		void PhysicsEngine::RemoveComponent(IComponent* component)
		{
		}

		bool PhysicsEngine::IsColliding(BoxCollider2D* boxA, BoxCollider2D* boxB)
		{
			Vector3f boxAPosition = boxA->gameObject->GetComponent<Transform>()->GetPosition();
			Vector3f boxBPosition = boxB->gameObject->GetComponent<Transform>()->GetPosition();

			boxA->CalculateEdges((int)boxAPosition.x, (int)boxAPosition.y);
			boxB->CalculateEdges((int)boxBPosition.x, (int)boxBPosition.y);

			if (boxB->leftEdge < boxA->rightEdge && boxB->rightEdge > boxA->leftEdge &&
				boxB->topEdge > boxA->bottomEdge && boxB->bottomEdge < boxA->topEdge)
				return true;

			return false;
		}
	}
}