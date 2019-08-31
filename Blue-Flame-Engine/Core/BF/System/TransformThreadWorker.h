#pragma once
#include <vector>
#include "BF/System/Transform.h"
#include "Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BFE_API TransformThreadWorker
		{
		public:
			enum class State { None, UpdatingTransformsInProgress, FinishedUpdatingTransforms };
			State state;

			Timer timer;

			unsigned int beginning;
			unsigned int end;

		public:
			TransformThreadWorker(unsigned int beginning, unsigned int end, State state);
			~TransformThreadWorker();

			static void Execute(std::vector<Transform*>* transforms, TransformThreadWorker* transformThreadWorker);
		};
	}
}