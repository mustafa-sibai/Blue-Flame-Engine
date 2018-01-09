#pragma once
#include <vector>
#include "BF/Application/GameNode.h"
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
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
					struct SortingFunction
					{
						bool operator() (GameNode* gameNodeA, GameNode* gameNodeB)
						{
							if (gameNodeA->nodeType == GameNode::NodeType::Mesh && gameNodeB->nodeType == GameNode::NodeType::Renderable)
								return true;

							if (gameNodeA->nodeType == GameNode::NodeType::Renderable && gameNodeB->nodeType == GameNode::NodeType::Renderable)
							{
								BF::Graphics::Renderers::Renderable* renderableA = ((BF::Graphics::Renderers::Renderable*)gameNodeA);
								BF::Graphics::Renderers::Renderable* renderableB = ((BF::Graphics::Renderers::Renderable*)gameNodeB);

								if (renderableA->GetRectangle().y <= renderableB->GetRectangle().y)
								{
									if (renderableA->zLayer < renderableB->zLayer)
									{
										//renderableA->index--;
										//renderableB->index++;
										return true;
									}
								}

								if (renderableA->GetRectangle().y < renderableB->GetRectangle().y)
								{
									if (renderableA->zLayer == renderableB->zLayer)
									{
										return true;
									}
								}

								if (renderableA->GetRectangle().y >= renderableB->GetRectangle().y)
								{
									if (renderableA->zLayer < renderableB->zLayer)
									{
										return true;
									}
								}
							}
							return false;
						}
					};

					std::string name;
					std::vector<GameNode*> gameNodes;

					bool sortLayer;

				public:
					Layer(const std::string& name);
					~Layer();

					void Update();

					void Add(GameNode& gameNode);
					void Remove(GameNode& gameNode);

					inline const std::string& GetName() { return name; }

					inline GameNode& GetGameNode(int index) { return *gameNodes[index]; }
					inline const size_t GetSize() { return gameNodes.size(); }
			};
		}
	}
}