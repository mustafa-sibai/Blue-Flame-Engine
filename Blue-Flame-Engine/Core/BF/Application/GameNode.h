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

		class BF_API GameNode
		{
			friend BF::Application::Scene;
			friend BF::Application::Layers::Layer;

			private:
				std::string name;
				std::vector<GameNode*> gameNodes;
				std::vector<Component*> components;
				BF::Application::Layers::LayerManager* layerManager;

			public:
				int layerIndex = 0;

			public:
				GameNode();
				virtual ~GameNode();

				GameNode* InstantiateChildGameNode(const std::string& name);
				void Destroy(GameNode* gameNode);

				void AddComponent(Component* component);
				void RemoveComponent(Component* component);
		};
	}
}