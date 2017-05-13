#pragma once
#include "BF/Graphics/Color.h"
#include "BF/Math/Math.h"
#include "BF/Platform/API/OpenGL/GLCommon.h"
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
				class BF_API GLContext
				{
					protected:
						GLuint GL_PRIMITIVE_TYPE;
						bool initialized;

					public:
						GLContext();
						~GLContext();

						virtual void Initialize();
						void SetPrimitiveType(Graphics::API::PrimitiveType primitiveType);
						void Clear(const Graphics::Color& color);
						void Render(GLsizei count);
						virtual void SwapBuffers();
						virtual void CleanUp();

						void EnableDepthBuffer(bool state);
						void EnableDepthMask(bool state);
						void EnableBlending(bool state);
						virtual void EnableVsync(bool state);
						void EnableScissor(bool state);

						void SetScissor(const Math::Rectangle& rectangle);
						void SetViewport(const Math::Rectangle& rectangle);
				};
			}
		}
	}
}