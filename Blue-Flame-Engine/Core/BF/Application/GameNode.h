#pragma once
#include <unordered_map>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class SpriteRenderer;
		}
	}

	namespace Application
	{
		class Scene;

		class BF_API GameNode
		{
			friend BF::Application::Scene;
			friend BF::Graphics::Renderers::SpriteRenderer;

			protected:
				enum class NodeType { Null, Line, RegularPolygon, Sprite, Text, GUI, Mesh, Audio };
				NodeType nodeType;

			public:
				int index;
				std::string name;
				std::unordered_map<std::string, GameNode*> gameNodes;
/*
			public:
				GameNode();

			protected:
				GameNode(NodeType nodeType);
				~GameNode();*/

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