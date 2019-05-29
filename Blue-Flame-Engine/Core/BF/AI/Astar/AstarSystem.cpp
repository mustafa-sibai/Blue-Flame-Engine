#include "AstarSystem.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			AstarSystem::AstarSystem()
			{
			}

			AstarSystem::~AstarSystem()
			{
			}

			void AstarSystem::Initialize()
			{
			}

			void AstarSystem::Load()
			{
			}

			void AstarSystem::PostLoad()
			{
			}

			void AstarSystem::Update(double deltaTime)
			{
				for (size_t i = 0; i < nodes.size(); i++)
				{

				}
			}

			void AstarSystem::Render()
			{
			}

			void AstarSystem::AddNode(BF::ECS::IComponent* component)
			{
				nodes.emplace_back((AstarNode*)component);
			}

			void AstarSystem::RemoveNode(BF::ECS::IComponent* component)
			{
			}

			void AstarSystem::FindPath(AstarNode* startingNode, AstarNode* endingNode)
			{
			}
		}
	}
}