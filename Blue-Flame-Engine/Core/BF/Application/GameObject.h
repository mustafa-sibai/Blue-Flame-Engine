#pragma once
#include <vector>
#include <string>
#include "BF/Application/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class Layer;
			class LayerManager;
		}
	}

	namespace Application
	{
		class Scene;

		class BF_API GameObject
		{
			friend BF::Application::Scene;
			friend BF::Application::Layers::Layer;

			private:
				std::vector<GameObject*> gameObjects;
				std::vector<Component*> components;
				BF::Application::Layers::LayerManager* layerManager;

			public:
				bool Active;
				std::string Name;
				int LayerIndex;

			public:
				GameObject();
				virtual ~GameObject();

				GameObject* InstantiateChildGameObject(const std::string& name);
				void Destroy(GameObject* gameObject);

				GameObject* InsertChildGameObject(GameObject& gameObject);

				void AddComponent(Component* component);
				void RemoveComponent(Component* component);
		};
	}
}