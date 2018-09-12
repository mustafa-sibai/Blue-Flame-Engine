#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace ECS
	{
		class GameObject;

		class BF_API Component
		{
			private:
				static int globalID;
				int id;

			public:
				enum class Type { Null, Renderable, GUI, Mesh, Audio };
				Type type;

				GameObject* gameObject;

			public:
				Component();
				virtual ~Component();

				inline int GetID() const { return id; }
		};
	}
}