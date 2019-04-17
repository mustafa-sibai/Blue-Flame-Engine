#pragma once
#include "BF/Graphics/Animation/IDataType.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API Condition
			{
			public:
				enum class EvaluationOperator { None, BiggerThan, BiggerThanOrEqual, SmallerThan, SmallerThanOrEqual, Equal };
				EvaluationOperator evaluationOperator;

				IDataType* lhs;
				IDataType* rhs;

				Condition(IDataType* lhs, EvaluationOperator evaluationOperator, IDataType* rhs);
				~Condition();

				bool Evaluate();
			};
		}
	}
}