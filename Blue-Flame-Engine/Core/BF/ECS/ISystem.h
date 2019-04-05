#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace ECS
	{
		class BFE_API ISystem
		{
		protected:
			virtual ~ISystem() { }

			virtual void Initialize()			  = 0;
			virtual void Load()					  = 0;
			virtual void PostLoad()				  = 0;
			virtual void Update(double deltaTime) = 0;
			virtual void Render()				  = 0;
		};
	}
}