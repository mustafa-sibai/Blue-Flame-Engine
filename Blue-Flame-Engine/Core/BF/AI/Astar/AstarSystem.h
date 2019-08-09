#pragma once
#include "BF/ECS/ISystem.h"
#include "BF/AI/Astar/AstarNode.h"
#include "BF/AI/Astar/AstarAgent.h"
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
				std::vector<BF::AI::Astar::AstarAgent*> agents;

			public:
				AstarSystem();
				~AstarSystem();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void AddComponent(BF::AI::Astar::IAstarComponent* component);
				void RemoveComponent(BF::AI::Astar::IAstarComponent* component);

				void FindPath(AstarNode* startingNode, AstarNode* endingNode);
			};
		}
	}
}