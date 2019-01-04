#include "ScriptExecutor.h"

namespace BF
{
	namespace Scripting
	{
		ScriptExecutor::ScriptExecutor()
		{
		}

		ScriptExecutor::~ScriptExecutor()
		{
		}

		void ScriptExecutor::Start()
		{
			for (size_t i = 0; i < scripts.size(); i++)
				scripts[i]->Start();
		}

		void ScriptExecutor::Update()
		{
			for (size_t i = 0; i < scripts.size(); i++)
				scripts[i]->Update();
		}
	}
}