#pragma once
#include <GL/glew.h>
#include <GL/wglew.h>
#include "BF/Math/Vector4.h"
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
						void Clear(const Math::Vector4& color);
						void Draw(GLsizei count);
						void SwapBuffers();
						void CleanUp();

						void EnableDepthBuffer(bool state);
						void EnableDepthMask(bool state);
						void EnableBlending(bool state);
						void EnableVsync(bool state);
				};
			}
		}
	}
}