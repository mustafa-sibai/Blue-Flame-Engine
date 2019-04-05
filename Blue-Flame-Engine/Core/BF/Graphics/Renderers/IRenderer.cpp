#include "IRenderer.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			IRenderer::IRenderer(RendererType rendererType) :
				rendererType(rendererType)
			{
			}

			IRenderer::~IRenderer()
			{
			}
		}
	}
}