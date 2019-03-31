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

		Scene::Scene(BF::Application::App& app) :
			app(app)
		{
		}

		Scene::~Scene()
		{
		}

		GameObject* Scene::AddGameObject(GameObject* gameObject)
		{
			if (!gameObject->added)
			{
				gameObjects.emplace_back(gameObject);
				gameObject->added = true;
				gameObject->scene = this;
			}
			else
				//Do copy here
				BFE_LOG_WARNING("This GameObject \"" + gameObject->Name + "\" of id: \"" + std::to_string(gameObject->id) +
					" has already been added to the scene. This GameObject will not be added again.", "");
			return gameObject;
		}

		GameObject* Scene::AddGameObject(GameObject* gameObject, GameObject* parent)
		{
			if (!gameObject->added)
			{
				gameObject->parent = parent;
				parent->gameObjects.emplace_back(gameObject);
				gameObject->added = true;
			}
			else
				//Do copy here
				BFE_LOG_WARNING("This GameObject \"" + gameObject->Name + "\" of id: \"" + std::to_string(gameObject->id) +
					" has already been added to the scene. This GameObject will not be added again.", "");
			return gameObject;
		}

		void Scene::RemoveGameObject(GameObject* gameObject)
		{
			/*for (size_t i = 0; i < gameObject->components.size(); i++)
			{
				if (gameObject->components[i]->type == Component::Type::Renderable)
				{
					for (vector<Renderable*>::iterator it = spriteRenderer.renderables.begin(); it != spriteRenderer.renderables.end(); ++it)
					{
						if (((Component*)*it)->GetID() == gameObject->components[i]->GetID())
						{
							spriteRenderer.renderables.erase(it);
							break;
						}
					}
				}
			}

			for (vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
			{
				if (((Component*)*it)->GetID() == gameObject->GetID())
				{
					gameObjects.erase(it);
					break;
				}
			}

			delete gameObject;*/
		}

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
	}
}