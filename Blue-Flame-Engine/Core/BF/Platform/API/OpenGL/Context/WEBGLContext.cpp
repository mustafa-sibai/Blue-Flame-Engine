#include "WEBGLContext.h"
#include "BF/Engine.h"
#include "BF/System/Log.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Platform/API/OpenGL/GLError.h"

#define OPENGL_CONTEXT_MAJOR_VERSION 3
#define OPENGL_CONTEXT_MINOR_VERSION 0

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace BF::Graphics::API;

				WEBGLContext::WEBGLContext()
				{
				}

				WEBGLContext::~WEBGLContext()
				{
				}

				void WEBGLContext::Initialize()
				{
					const EGLint context_attrib_list[] =
					{
						EGL_CONTEXT_CLIENT_VERSION, 2,
						EGL_NONE
					};

					if (!(context = eglCreateContext(Engine::GetWindow().display, Engine::GetWindow().config, 0, context_attrib_list)))
						BF_LOG_ERROR("eglCreateContext() returned error %d", eglGetError());

					if (!eglMakeCurrent(Engine::GetWindow().display, Engine::GetWindow().surface, Engine::GetWindow().surface, context))
						BF_LOG_ERROR("eglMakeCurrent() returned error %d", eglGetError());

					if (!eglQuerySurface(Engine::GetWindow().display, Engine::GetWindow().surface, EGL_WIDTH, &width) || !eglQuerySurface(Engine::GetWindow().display, Engine::GetWindow().surface, EGL_HEIGHT, &height))
						BF_LOG_ERROR("eglQuerySurface() returned error %d", eglGetError());

					Engine::GetWindow().SetClientSize(width, height);

					BF_LOG_INFO("OPENGL VERSION %s", (char*)glGetString(GL_VERSION));
					BF_LOG_INFO("Graphics Card: %s - %s", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
				}

				void WEBGLContext::SetPrimitiveType(PrimitiveType primitiveType)
				{
					switch (primitiveType)
					{
					case PrimitiveType::PointList:
					{
						GL_PRIMITIVE_TYPE = GL_POINTS;
						break;
					}
					case PrimitiveType::LineList:
					{
						GL_PRIMITIVE_TYPE = GL_LINES;
						break;
					}
					case PrimitiveType::LineStrip:
					{
						GL_PRIMITIVE_TYPE = GL_LINE_STRIP;
						break;
					}
					case PrimitiveType::TriangleList:
					{
						GL_PRIMITIVE_TYPE = GL_TRIANGLES;
						break;
					}
					case PrimitiveType::TriangeStrip:
					{
						GL_PRIMITIVE_TYPE = GL_TRIANGLE_STRIP;
						break;
					}
					default:
						break;
					}
				}

				void WEBGLContext::Clear(Graphics::Color color)
				{
					GLCall(glClearColor(color.r, color.g, color.b, color.a));
					GLCall(glClear(GL_COLOR_BUFFER_BIT));
				}

				void WEBGLContext::Render(GLsizei count)
				{
					GLCall(glDrawElements(GL_PRIMITIVE_TYPE, count, GL_UNSIGNED_INT, nullptr));
				}

				void WEBGLContext::SwapBuffers()
				{
					if (eglSwapInterval(Engine::GetWindow().display, 0) != EGL_TRUE)
						BF_LOG_ERROR("eglSwapInterval() returned error %d", eglGetError());
				}
			}
		}
	}
}