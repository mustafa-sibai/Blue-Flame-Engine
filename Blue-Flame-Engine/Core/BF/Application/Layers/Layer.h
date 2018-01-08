#pragma once
#include <vector>
#include "BF/Application/GameNode.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class BF_API Layer
			{
				private:
					std::string name;
					std::vector<GameNode*> gameNodes;

				public:
					Layer(const std::string& name);
					~Layer();

					void Add(GameNode& gameNode);
					void Remove(GameNode& gameNode);

					inline const std::string& GetName() { return name; }

					inline GameNode& GetGameNode(int index) { return *gameNodes[index]; }
					inline const size_t GetSize() { return gameNodes.size(); }
			};
		}
	}
}