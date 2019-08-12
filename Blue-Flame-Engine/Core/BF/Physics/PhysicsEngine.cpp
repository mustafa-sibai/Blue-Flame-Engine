#include "PhysicsEngine.h"
#include "BF/System/Debug.h"
#include "BF/Scripting/Script.h"

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
			for (size_t i = 0; i < colliders.size(); i++)
			{
				switch (((ICollider*)colliders[i])->type)
				{
				case ICollider::Type::BoxCollider2D:
				{
					BoxCollider2D* boxA = (BoxCollider2D*)colliders[i];

					for (size_t j = 0; j < colliders.size(); j++)
					{
						if (colliders[i] == colliders[j])
							continue;

						BoxCollider2D* boxB = (BoxCollider2D*)colliders[j];

						if (IsColliding(boxA, boxB))
						{
							BF::Scripting::IScript* script = boxA->gameObject->GetComponent<IScript>();

							if (script != nullptr)
								script->OnTriggerEnter(*boxB);

							//BFE_LOG_INFO("Collision", "");
						}
					}
					break;
				}
				default:
					break;
				}
			}
		}

		void PhysicsEngine::Render()
		{
		}

		void PhysicsEngine::AddComponent(IComponent* component)
		{
			colliders.emplace_back((ICollider*)component);
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