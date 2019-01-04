#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace ECS
	{
		class GameObject;

		class BF_API Component
		{
			friend class BF::Application::Scene;

			private:
				static int globalID;
				int id;
				bool added;

			public:
				enum class Type { Null, Renderable, GUI, Mesh, Audio, Script };
				Type type;

				GameObject* gameObject;

			public:
				Component();
				virtual ~Component();

				inline int GetID() const { return id; }
		};
	}
}