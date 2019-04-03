#include "IScript.h"

namespace BF
{
	namespace Scripting
	{
		IScript::IScript()
		{
			type = IComponent::Type::Script;
		}

		IScript::~IScript()
		{
		}

		void IScript::Start()
		{
		}

		void IScript::Update()
		{
		}
	}
}