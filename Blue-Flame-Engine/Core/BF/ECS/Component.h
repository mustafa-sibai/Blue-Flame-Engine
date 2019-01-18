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

		class BFE_API Component
		{
			friend class BF::Application::Scene;
			friend class BF::ECS::GameObject;

			private:
				static int globalID;
				int id;
				bool added;

			public:
				enum class Type { Null, Transform, Camera, Renderable, GUI, Mesh, Audio, Script };
				Type type;

				GameObject* gameObject;

			public:
				Component(Type type);
				virtual ~Component();

				inline int GetID() const { return id; }
		};
	}
}