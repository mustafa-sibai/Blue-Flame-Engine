#include "GameObject.h"

namespace BF
{
	namespace ECS
	{
		using namespace std;

		int GameObject::globalID = 0;

		GameObject::GameObject() :
			Active(true), Name(""), id(0)
		{
			GameObject::globalID++;
			id = globalID;
		}

		GameObject::~GameObject()
		{
		}

		/*GameObject* GameObject::InstantiateChildGameObject(const string& name)
		{
			GameObject* gameObject = new GameObject();

			gameObject->Name = name;
			//gameObjects.emplace_back(gameObject);

			return gameObject;
		}

		void GameObject::Destroy(GameObject* gameObject)
		{
		}

		GameObject* GameObject::InsertChildGameObject(GameObject& gameObject)
		{
			//gameObjects.emplace_back(&gameObject);
			return &gameObject;
		}

		void GameObject::AddComponent(Component* component)
		{
			component->gameObject = this;
			components.emplace_back(component);
		}

		void GameObject::RemoveComponent(Component* component)
		{
		}*/
	}
}