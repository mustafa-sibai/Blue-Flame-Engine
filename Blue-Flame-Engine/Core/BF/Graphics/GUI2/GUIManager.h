#pragma once
#include <vector>
#include "BF/Application/GameObject.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API GUIManager
			{
			public:
				std::vector<BF::Application::GameObject*> canvases;

			public:
				GUIManager();
				~GUIManager();


			};
		}
	}
}