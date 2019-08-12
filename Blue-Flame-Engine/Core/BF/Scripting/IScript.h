#pragma once
#include "BF/ECS/Component.h"
#include "BF/Physics/Collider.h"
#include "BF/Common.h"

namespace BF
{
	namespace Scripting
	{
		class BFE_API IScript : public BF::ECS::Component<IScript>
		{
		public:
			IScript();
			virtual ~IScript();

			virtual void OnTriggerEnter(BF::Physics::ICollider& other);

			virtual void Start();
			virtual void Update();
		};
	}
}