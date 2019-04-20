#include "Condition.h"
#include "DataType.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			Condition::Condition(IDataType* lhs, EvaluationOperator evaluationOperator, IDataType* rhs) :
				lhs(lhs), evaluationOperator(evaluationOperator), rhs(rhs)
			{
			}

			Condition::~Condition()
			{
			}

			bool Condition::Evaluate()
			{
				if (lhs->GetInternalDataType() == IDataType::InternalDataType::Int &&
					rhs->GetInternalDataType() == IDataType::InternalDataType::Int)
				{
					AInt* LHS = (AInt*)lhs;
					AInt* RHS = (AInt*)rhs;

					switch (evaluationOperator)
					{
						case Condition::EvaluationOperator::BiggerThan:			return *LHS >  *RHS; break;
						case Condition::EvaluationOperator::BiggerThanOrEqual:	return *LHS >= *RHS; break;
						case Condition::EvaluationOperator::SmallerThan:		return *LHS <  *RHS; break;
						case Condition::EvaluationOperator::SmallerThanOrEqual:	return *LHS <= *RHS; break;
						case Condition::EvaluationOperator::Equal:				return *LHS == *RHS; break;
						default: return false; break;
					}
				}
				else if (lhs->GetInternalDataType() == IDataType::InternalDataType::Float &&
						 rhs->GetInternalDataType() == IDataType::InternalDataType::Float)
				{
					AFloat* LHS = (AFloat*)lhs;
					AFloat* RHS = (AFloat*)rhs;

					switch (evaluationOperator)
					{
						case Condition::EvaluationOperator::BiggerThan:			return *LHS >  *RHS; break;
						case Condition::EvaluationOperator::BiggerThanOrEqual:	return *LHS >= *RHS; break;
						case Condition::EvaluationOperator::SmallerThan:		return *LHS <  *RHS; break;
						case Condition::EvaluationOperator::SmallerThanOrEqual:	return *LHS <= *RHS; break;
						case Condition::EvaluationOperator::Equal:				return *LHS == *RHS; break;
						default: return false; break;
					}
				}
				else if (lhs->GetInternalDataType() == IDataType::InternalDataType::Float &&
						 rhs->GetInternalDataType() == IDataType::InternalDataType::Float)
				{
					ABool* LHS = (ABool*)lhs;
					ABool* RHS = (ABool*)rhs;

					switch (evaluationOperator)
					{
						case Condition::EvaluationOperator::BiggerThan:			return *LHS >  *RHS; break;
						case Condition::EvaluationOperator::BiggerThanOrEqual:	return *LHS >= *RHS; break;
						case Condition::EvaluationOperator::SmallerThan:		return *LHS <  *RHS; break;
						case Condition::EvaluationOperator::SmallerThanOrEqual:	return *LHS <= *RHS; break;
						case Condition::EvaluationOperator::Equal:				return *LHS == *RHS; break;
						default: return false; break;
					}
				}
			}
		}
	}
}