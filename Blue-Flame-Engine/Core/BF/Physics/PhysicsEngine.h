#pragma once
#include <vector>
#include "BF/ECS/ISystem.h"
#include "BF/Physics/ICollider.h"
#include "BF/Physics/BoxCollider2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Physics
	{
		class BFE_API PhysicsEngine : public BF::ECS::ISystem
		{
		private:
			std::vector<ICollider*> colliders;

		public:
			PhysicsEngine();
			virtual ~PhysicsEngine();

			void Initialize()			  override;
			void Load()					  override;
			void PostLoad()				  override;
			void Update(double deltaTime) override;
			void Render()				  override;

			void AddComponent(BF::ECS::IComponent* component);
			void RemoveComponent(BF::ECS::IComponent* component);

		private:
			bool IsColliding(BF::Physics::BoxCollider2D* boxA, BF::Physics::BoxCollider2D* boxB);
		};
	}
}