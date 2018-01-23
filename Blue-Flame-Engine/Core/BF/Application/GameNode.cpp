#include "GameNode.h"
#include "BF/Application/Layers/LayerManager.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::Application;

		GameNode::GameNode() :
			layerManager(nullptr)
		{
		}

		GameNode::~GameNode()
		{
		}

		GameNode* GameNode::InstantiateChildGameNode(const string& name)
		{
			GameNode* gameNode = new GameNode();

			gameNode->name = name;
			gameNode->layerManager = layerManager;

			gameNodes.emplace_back(gameNode);

			return gameNode;
		}

		void GameNode::Destroy(GameNode* gameNode)
		{
		}

		void GameNode::AddComponent(Component* component)
		{
			switch (component->type)
			{
				case Component::Type::Renderable:
				{
					layerManager->GetLayer(0).AddComponent(*component);
					break;
				}
				case Component::Type::GUI:
				{
					layerManager->GetLayer(1).AddComponent(*component);
					break;
				}
				default:
					break;
			}

			components.emplace_back(component);
		}

		void GameNode::RemoveComponent(Component* component)
		{
		}
	}
}