#pragma once
#include <vector>
#include <string>
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

			protected:
				enum class NodeType { Null, Renderable, GUI, Mesh, Audio };
				NodeType nodeType;

			private:
				std::string name;
				std::vector<GameNode*> gameNodes;
				BF::Application::Layers::LayerManager* layerManager;

			public:
				int layerIndex = 0;

			public:
				GameNode();
				~GameNode();

				GameNode* Instantiate(const std::string& name, GameNode* gameNode);
				void Destroy(GameNode* gameNode);
		};
	}
}