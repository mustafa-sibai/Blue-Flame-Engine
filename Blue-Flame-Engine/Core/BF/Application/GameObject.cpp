#include "GameObject.h"
#include "BF/Application/Layers/LayerManager.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::Application;

		GameObject::GameObject() :
			layerManager(nullptr), Active(true), Name(""), LayerIndex(0)
		{
		}

		GameObject::~GameObject()
		{
		}

		GameObject* GameObject::InstantiateChildGameObject(const string& name)
		{
			GameObject* gameObject = new GameObject();

			gameObject->Name = name;
			gameObject->layerManager = layerManager;

			gameObjects.emplace_back(gameObject);

			return gameObject;
		}

		void GameObject::Destroy(GameObject* gameObject)
		{
		}

		GameObject* GameObject::InsertChildGameObject(GameObject& gameObject)
		{
			gameObjects.emplace_back(&gameObject);
			return &gameObject;
		}

		void GameObject::AddComponent(Component* component)
		{
			component->gameObject = this;

			if (layerManager != nullptr)
				layerManager->GetLayer(0).AddComponent(*component);

			/*switch (component->type)
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
			}*/

			components.emplace_back(component);
		}

		void GameObject::RemoveComponent(Component* component)
		{
		}
	}
}