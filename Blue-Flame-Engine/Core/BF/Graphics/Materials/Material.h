#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class Mesh;

		namespace Materials
		{
			class BFE_API Material
			{
				friend class MaterialManager;
				friend class Mesh;

			private:
				static int globalID;
				int id;

			protected:
				int index;

			public:
				Material();
				virtual ~Material();

				inline int GetID() const { return id; }
			};
		}
	}
}