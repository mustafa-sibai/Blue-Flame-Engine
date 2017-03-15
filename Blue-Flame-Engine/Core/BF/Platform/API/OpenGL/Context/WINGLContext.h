#pragma once
#include <GL/glew.h>
#include <GL/wglew.h>
#include "BF/Graphics/Color.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class PrimitiveType;
		}
	}

	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API WINGLContext
				{
					private:
						HDC hDC;
						HGLRC context;
						GLuint GL_PRIMITIVE_TYPE;

					public:
						WINGLContext();
						~WINGLContext();

						void Initialize();
						void SetPrimitiveType(Graphics::API::PrimitiveType primitiveType);
						void Clear(const Graphics::Color& color);
						void Render(GLsizei count);
						void SwapBuffers();
						void CleanUp();

						void EnableDepthBuffer(bool state);
						void EnableDepthMask(bool state);
						void EnableBlending(bool state);
						void EnableVsync(bool state);

						void EnableScissor(bool state);
						void SetScissor(const Math::Rectangle& rectangle);
				};
			}
		}
	}
}