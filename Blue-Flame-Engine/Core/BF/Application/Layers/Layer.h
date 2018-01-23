#pragma once
#include <vector>
#include "BF/Application/Component.h"
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
						bool operator() (Component* componentA, Component* componentB)
						{
							BF::Graphics::Renderers::Renderable* renderableA = ((BF::Graphics::Renderers::Renderable*)componentA);
							BF::Graphics::Renderers::Renderable* renderableB = ((BF::Graphics::Renderers::Renderable*)componentB);

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

							return false;
						}
					};

					std::string name;
					std::vector<Component*> components;

					bool sortLayer;

				public:
					Layer(const std::string& name);
					~Layer();

					void Update();

					void AddComponent(Component& component);
					void RemoveComponent(Component& component);

					inline const std::string& GetName() { return name; }

					inline Component& GetComponent(int index) { return *components[index]; }
					inline const size_t GetSize() { return components.size(); }
			};
		}
	}
}