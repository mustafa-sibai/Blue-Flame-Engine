#include "ForwardRenderer.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			ForwardRenderer::ForwardRenderer()
			{
			}

			ForwardRenderer::~ForwardRenderer()
			{
			}

			void ForwardRenderer::Initialize()
			{
			}

			void ForwardRenderer::Render()
			{
				for (size_t i = 0; i < meshes.size(); i++)
				{
					meshes[i]->Bind();
					Engine::GetContext().Draw((unsigned int)meshes[i]->GetIndices().size());
					meshes[i]->Unbind();
				}
			}
		}
	}
}