#pragma once
#include "DependencyHeaders/EGL/egl.h"
#include "DependencyHeaders/GLES3/gl3.h"
#include "BF/Graphics/Color.h"

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
				class WEBGLContext
				{
				private:
					EGLContext context;
					EGLint width;
					EGLint height;

					GLuint GL_PRIMITIVE_TYPE;

				public:
					WEBGLContext();
					~WEBGLContext();

					void Initialize();
					void SetPrimitiveType(Graphics::API::PrimitiveType primitiveType);
					void Clear(Graphics::Color color);
					void Render(GLsizei count);
					void SwapBuffers();
				};
			}
		}
	}
}