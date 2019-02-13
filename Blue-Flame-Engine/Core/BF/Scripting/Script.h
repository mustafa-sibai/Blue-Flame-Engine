#pragma once
#include "IScript.h"
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Scripting
	{
		template <class T>
		class Script : public IScript
		{
		public:
			Script();
			virtual ~Script();
		};

#include "Script.inl"
	}
}