#pragma once
#include <unordered_map>
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class Layer;
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

			public:
				int index = 0;
				std::string name;
				std::unordered_map<std::string, GameNode*> gameNodes;

			/*
			public:
				GameNode();

			protected:
				GameNode(NodeType nodeType);
				~GameNode();
			*/

			/*
			public:
				GameNode();
				~GameNode();

			public:
				virtual void Initialize() = 0;
				virtual void Load() = 0;
				//virtual void FixedUpdate();
				virtual void Update() = 0;
				virtual void Render() = 0;
			*/
		};
	}
}