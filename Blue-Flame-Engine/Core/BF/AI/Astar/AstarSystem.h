#pragma once
#include "BF/ECS/ISystem.h"
#include "BF/ECS/IComponent.h"
#include "BF/AI/Astar/AstarNode.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			class BFE_API AstarSystem : public BF::ECS::ISystem
			{
			private:
				std::vector<BF::AI::Astar::AstarNode*> nodes;

			public:
				AstarSystem();
				~AstarSystem();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void AddNode(BF::ECS::IComponent* component);
				void RemoveNode(BF::ECS::IComponent* component);

				void FindPath(AstarNode* startingNode, AstarNode* endingNode);
			};
		}
	}
}