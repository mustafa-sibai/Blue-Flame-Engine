#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			class BFE_API Material
			{
				friend class MaterialManager;

			private:
				static int globalID;
				int id;
				int index;

			public:
				Material();
				virtual ~Material();

				inline int GetID() const { return id; }
			};
		}
	}
}