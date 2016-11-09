#pragma once
#include <GL/glew.h>
#include <GL/wglew.h>
#include "BF/Application/Window.h"
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
						Application::Window* window;
						HDC hDC;
						HGLRC context;
						GLuint GL_PRIMITIVE_TYPE;
						const unsigned short OPENGL_CONTEXT_MAJOR_VERSION = 4;
						const unsigned short OPENGL_CONTEXT_MINOR_VERSION = 5;

					public:
						WINGLContext(Application::Window* window);
						~WINGLContext();

						void SetPrimitiveType(Graphics::API::PrimitiveType primitiveType);
						void Clear(Math::Vector4 color);
						void Draw(GLsizei count);
						void SwapBuffers();
						void CleanUp();
				};
			}
		}
	}
}