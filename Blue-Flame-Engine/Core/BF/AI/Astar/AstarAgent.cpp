#include "AstarAgent.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			using namespace BF::Math;

			AstarAgent::AstarAgent() :
				AstarComponent(AstarComponent::Type::AstarAgent),
				state(State::Idle)
			{
			}

			AstarAgent::~AstarAgent()
			{
			}

			void AstarAgent::SetDestination(const Vector3f& startPosition, const Vector3f& goalPosition)
			{
				this->startPosition = startPosition;
				this->goalPosition = goalPosition;
				state = State::LookingForPath;
			}
		}
	}
}