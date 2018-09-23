#pragma once
#include <vector>
#include "BF/Graphics/Camera.h"
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
					BF::Graphics::Camera& camera;
					std::vector<BF::Graphics::Mesh*> meshes;
					BF::Graphics::API::ConstantBuffer materialConstantBuffer;

				public:
					ForwardRenderer(BF::Graphics::Camera& camera);
					~ForwardRenderer();

					void Initialize();
					void Render();
			};
		}
	}
}