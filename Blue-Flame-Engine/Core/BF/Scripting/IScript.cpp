#include "IScript.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Scripting
	{
		using namespace BF::Physics;

		IScript::IScript() :
			Component(IComponent::Type::Script)
		{
		}

		IScript::~IScript()
		{
		}

		void IScript::OnTriggerEnter(ICollider& other)
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