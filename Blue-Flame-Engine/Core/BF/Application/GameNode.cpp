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

		GameNode* GameNode::Instantiate(const string& name, GameNode* gameNode)
		{
			gameNode->name = name;
			gameNode->layerManager = layerManager;

			switch (gameNode->nodeType)
			{
				case NodeType::Renderable:
				{
					layerManager->GetLayer(0).AddGameNode(*gameNode);
					break;
				}
				case NodeType::GUI:
				{

					break;
				}
				default:
					break;
			}

			gameNodes.emplace_back(gameNode);

			return gameNode;
		}

		void GameNode::Destroy(GameNode* gameNode)
		{
		}
	}
}