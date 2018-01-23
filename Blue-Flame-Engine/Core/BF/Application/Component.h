#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API Component
		{
		public:
			enum class Type { Null, Renderable, GUI, Mesh, Audio };
			Type type;

		public:
			Component();
			virtual ~Component();
		};
	}
}