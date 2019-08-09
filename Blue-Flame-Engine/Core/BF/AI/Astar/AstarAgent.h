#pragma once
#include "BF/AI/Astar/AstarComponent.h"
#include "BF/Math/Vector3.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			class BFE_API AstarAgent : public AstarComponent<AstarAgent>
			{
			private:
				BF::Math::Vector3f startPosition;
				BF::Math::Vector3f goalPosition;

				enum class State { Idle, LookingForPath, FoundPath, FailedToFindPath };
				State state;

			public:
				AstarAgent();
				~AstarAgent();

				void SetDestination(const BF::Math::Vector3f& startPosition, const BF::Math::Vector3f& goalPosition);
			};
		}
	}
}