#pragma once
#include <vector>
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API GameNode
		{
			public:
				enum class NodeType { Sprite, Mesh, Audio };
				NodeType nodeType;

				std::vector<GameNode*> gameNodes;

			public:
				GameNode();
				~GameNode();

			public:
				virtual void Initialize();
				virtual void Load();
				//virtual void FixedUpdate();
				virtual void Update();
				virtual void Render();
		};
	}
}