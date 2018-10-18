#include "Scene.h"
#include "BF/Graphics/Transform.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::ECS;
		using namespace BF::Graphics;
		using namespace BF::Graphics::Renderers;
		//using namespace BF::Application::Layers;

		Scene::Scene(Camera& camera) :
			forwardRenderer(camera), initialized(false), loaded(false), fixedUpdateTicks(0)//, rootGameObject(nullptr)
		{
		}

		Scene::~Scene()
		{
		}

		void Scene::Initialize(/*BF::Application::Layers::LayerManager& layerManager*/)
		{
			//rootGameObject = new GameObject();
			//rootGameObject->layerManager = &layerManager;
			//spriteRenderer.Initialize();
			forwardRenderer.Initialize();
		}

		void Scene::Load()
		{
		}

		/*void Scene::FixedUpdate()
		{
		}*/

		void Scene::Update()
		{
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

			//spriteRenderer.Render(SpriteRenderer::SortingOrder::BackToFront);
			forwardRenderer.Render();
		}

		GameObject* Scene::AddGameObject(GameObject* gameObject)
		{
			if (!gameObject->added)
			{
				gameObject->components.emplace_back(new Transform());
				gameObject->components[0]->gameObject = gameObject;
				gameObjects.emplace_back(gameObject);
				gameObject->added = true;
			}
			else
				//Do copy here
				BF_LOG_WARNING("This GameObject \"" + gameObject->Name + "\" of id: \"" + std::to_string(gameObject->id) +
								" has already been added to the scene. This GameObject will not be added again.", "");
			return gameObject;
		}

		Component* Scene::AddComponentToGameObject(GameObject* gameObject, Component* component)
		{
			if (!component->added)
			{
				if (component->type == BF::ECS::Component::Type::Renderable)
				{
					component->gameObject = gameObject;
					gameObject->components.emplace_back(component);
					spriteRenderer.renderables.emplace_back((Renderable*)component);
					component->added = true;
				}
				else if (component->type == BF::ECS::Component::Type::Mesh)
				{
					component->gameObject = gameObject;
					gameObject->components.emplace_back(component);
					forwardRenderer.meshes.emplace_back((Mesh*)component);
					component->added = true;
				}
			}
			else
				//Do copy here
				BF_LOG_WARNING("This Component of id: \"" + std::to_string(component->id) + "\" has already been added to GameObject \"" + 
								gameObject->Name + "\" of id \"" + std::to_string(gameObject->id) + "\". This Component will not be added again.", "");

			return component;
		}

		void Scene::RemoveGameObject(GameObject* gameObject)
		{
			for (size_t i = 0; i < gameObject->components.size(); i++)
			{
				if (gameObject->components[i]->type == Component::Type::Renderable)
				{
					for (std::vector<Renderable*>::iterator it = spriteRenderer.renderables.begin(); it != spriteRenderer.renderables.end(); ++it)
					{
						if (((Component*)*it)->GetID() == gameObject->components[i]->GetID())
						{
							spriteRenderer.renderables.erase(it);
							break;
						}
					}
				}
			}

			for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
			{
				if (((Component*)*it)->GetID() == gameObject->GetID())
				{
					gameObjects.erase(it);
					break;
				}
			}

			delete gameObject;
		}

		void Scene::RemoveComponentFromGameObject(GameObject* gameObject, Component* component)
		{
			if (component->type == Component::Type::Renderable)
			{
				for (std::vector<Renderable*>::iterator it = spriteRenderer.renderables.begin(); it != spriteRenderer.renderables.end(); ++it)
				{
					if (((Component*)*it)->GetID() == component->GetID())
					{
						spriteRenderer.renderables.erase(it);
						break;
					}
				}
			}

			for (std::vector<Component*>::iterator it = gameObject->components.begin(); it != gameObject->components.end(); ++it)
			{
				if (((Component*)*it)->GetID() == component->GetID())
				{
					gameObject->components.erase(it);
					break;
				}
			}

			delete component;
		}

		/*GameNode* Scene::Instantiate(const string& name, GameNode* gameNode)
		{
			gameNode->name = name;

			if (gameNode->nodeType == GameNode::NodeType::GUI)
				layerManager.GetLayer(1).AddGameNode(*gameNode);
			else
				layerManager.GetLayer(0).AddGameNode(*gameNode);

			return gameNode;
		}*/

		/*GameNode* Scene::Instantiate(const string& name, GameNode* gameNode, GameNode* parent)
		{
			parent->gameNodes.emplace_back(gameNode);
			return gameNode;
		}*/

		/*void Scene::Destroy(GameNode* gameNode)
		{
			switch (gameNode->nodeType)
			{*/
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
			/*}


		}*/

		/*void Scene::RenderNode(GameNode* node)
		{*/
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
		//}
	}
}