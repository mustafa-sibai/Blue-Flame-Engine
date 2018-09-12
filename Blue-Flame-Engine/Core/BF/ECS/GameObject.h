#pragma once
#include <vector>
#include <string>
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace ECS
	{
		class BF_API GameObject
		{
			friend class BF::Application::Scene;

			private:
				static int globalID;
				int id;
				//std::vector<GameObject*> gameObjects;
				std::vector<Component*> components;

			public:
				bool Active;
				std::string Name;

			public:
				GameObject();
				virtual ~GameObject();

				inline int GetID() const { return id; }

				/*GameObject* InstantiateChildGameObject(const std::string& name);
				void Destroy(GameObject* gameObject);

				GameObject* InsertChildGameObject(GameObject& gameObject);

				void AddComponent(Component* component);
				void RemoveComponent(Component* component);*/
		};
	}
}