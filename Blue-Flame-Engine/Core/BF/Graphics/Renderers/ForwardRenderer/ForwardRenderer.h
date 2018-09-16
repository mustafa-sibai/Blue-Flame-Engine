#pragma once
#include <vector>
#include "BF/Graphics/Mesh.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API ForwardRenderer
			{
				friend class BF::Application::Scene;

				private:
					std::vector<BF::Graphics::Mesh*> meshes;

				public:
					ForwardRenderer();
					~ForwardRenderer();

					void Initialize();
					void Render();
			};
		}
	}
}