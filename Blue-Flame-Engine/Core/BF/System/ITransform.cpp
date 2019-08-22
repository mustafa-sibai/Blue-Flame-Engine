#include "ITransform.h"

namespace BF
{
	namespace System
	{
		ITransform::ITransform() :
			Component(IComponent::Type::Transform)
		{
		}

		ITransform::~ITransform()
		{
		}
	}
}