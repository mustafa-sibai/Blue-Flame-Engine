#include "Script.h"

namespace BF
{
	namespace Scripting
	{
		Script::Script()
		{
			Component::type = Component::Type::Script;
		}

		Script::~Script()
		{
		}

		void Script::Start()
		{
		}

		void Script::Update()
		{
		}
	}
}