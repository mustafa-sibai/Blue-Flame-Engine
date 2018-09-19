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
				bool added;
				std::vector<Component*> components;

			public:
				bool Active;
				std::string Name;

			public:
				GameObject(const std::string& name);
				virtual ~GameObject();

				inline int GetID() const { return id; }
				inline const std::vector<Component*>& GetComponents() const{ return components; }
		};
	}
}