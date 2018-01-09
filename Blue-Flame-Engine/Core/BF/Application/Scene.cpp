#include "Scene.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::Graphics::GUI;
		using namespace BF::Graphics::Renderers;
		using namespace BF::Application::Layers;

		Scene::Scene(BF::Application::Layers::LayerManager& layerManager) :
			layerManager(layerManager), initialized(false), loaded(false), fixedUpdateTicks(0), spriteRenderer(layerManager)
		{
		}

		Scene::~Scene()
		{
		}

		void Scene::Initialize()
		{
			spriteRenderer.Initialize();
			widgetManager.Initialize();
			/*
			for (size_t i = 0; i < gameNodes.size(); i++)
				gameNodes[i]->Initialize();*/
		}

		void Scene::Load()
		{
			widgetManager.Load();

			/*for (size_t i = 0; i < gameNodes.size(); i++)
				gameNodes[i]->Load();*/
		}

		/*void Scene::FixedUpdate()
		{
		}*/

		void Scene::Update()
		{
			/*for (size_t i = 0; i < gameNodes.size(); i++)
				gameNodes[i]->Update();*/


			widgetManager.Update();
		}

		void Scene::Render()
		{
			/*for (size_t i = 0; i < gameNodes.size(); i++)
			{
				switch (gameNodes[i]->nodeType)
				{
					case GameNode::NodeType::Sprite:
					{
						spriteRenderer.Render(*(RegularPolygon*)gameNodes[i]);
						break;
					}
					case GameNode::NodeType::GUI:
					{
						widgetManager.AddWidget((Widget*)gameNodes[i]);
						break;
					}
					case GameNode::NodeType::Mesh:
					{
						break;
					}
					case GameNode::NodeType::Audio:
					{
						break;
					}
					default:
					{
						break;
					}
				}

				RenderNode(gameNodes[i]);
			}*/

			spriteRenderer.Render(SpriteRenderer::SortingOrder::BackToFront);
			widgetManager.Render();
		}

		GameNode* Scene::Instantiate(const string& name, GameNode* gameNode)
		{
			gameNode->name = name;
			gameNodes.insert({ name, gameNode });

			if (gameNode->nodeType == GameNode::NodeType::GUI)
				layerManager.GetLayer(1).Add(*gameNode);
			else
				layerManager.GetLayer(0).Add(*gameNode);

			return gameNode;
		}

		GameNode* Scene::Instantiate(const string& name, GameNode* gameNode, GameNode* parent)
		{
			parent->gameNodes.insert({ name, gameNode });
			return gameNode;
		}

		void Scene::Destroy(GameNode* gameNode)
		{
			switch (gameNode->nodeType)
			{
				/*case GameNode::NodeType::Line:
				{
					break;
				}
				case GameNode::NodeType::RegularPolygon:
				{
					//spriteRenderer.Remove(*(RegularPolygon*)gameNode);					
					break;
				}
				case GameNode::NodeType::Sprite:
				{
					break;
				}
				case GameNode::NodeType::Text:
				{
					break;
				}
				case GameNode::NodeType::GUI:
				{
					widgetManager.RemoveWidget((Widget*)gameNode);
					gameNodes.erase(gameNode->name);
					delete (Widget*)gameNode;
					break;
				}
				case GameNode::NodeType::Mesh:
				{
					break;
				}
				case GameNode::NodeType::Audio:
				{
					break;
				}
				default:
				{
					break;
				}*/
			}


		}

		void Scene::RenderNode(GameNode* node)
		{
			/*for (size_t i = 0; i < node->gameNodes.size(); i++)
			{
				RenderNode(node->gameNodes[i]);

				switch (gameNodes[i]->nodeType)
				{
					case GameNode::NodeType::Sprite:
					{
						spriteRenderer.Render(*(RegularPolygon*)(node->gameNodes[i]));
						break;
					}
					case GameNode::NodeType::GUI:
					{
						break;
					}
					case GameNode::NodeType::Mesh:
					{
						break;
					}
					case GameNode::NodeType::Audio:
					{
						break;
					}
					default:
					{
						break;
					}
				}
			}*/
		}
	}
}