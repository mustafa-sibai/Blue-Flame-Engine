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

		void ScriptExecutor::Initialize()
		{
		}

		void ScriptExecutor::Load()
		{
		}

		void ScriptExecutor::PostLoad()
		{
			for (size_t i = 0; i < scripts.size(); i++)
				scripts[i]->Start();
		}

		void ScriptExecutor::Update(double deltaTime)
		{
			for (size_t i = 0; i < scripts.size(); i++)
				scripts[i]->Update();
		}

		void ScriptExecutor::Render()
		{
		}
	}
}