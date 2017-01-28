#include "WINGLContext.h"
#include "BF/Engine.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Platform/API/OpenGL/GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
#define OPENGL_CONTEXT_MAJOR_VERSION 4
#define OPENGL_CONTEXT_MINOR_VERSION 5

				using namespace BF::Graphics::API;
				using namespace BF::Math;

				WINGLContext::WINGLContext()
				{
				}

				WINGLContext::~WINGLContext()
				{
				}

				void WINGLContext::Initialize()
				{
					hDC = GetDC(Engine::GetWindow().GetHWND());
					int letWindowsChooseThisPixelFormat = ChoosePixelFormat(hDC, &Engine::GetWindow().GetPixelFormat());
					SetPixelFormat(hDC, letWindowsChooseThisPixelFormat, &Engine::GetWindow().GetPixelFormat());

					HGLRC tempContext = wglCreateContext(hDC);
					wglMakeCurrent(hDC, tempContext);

					int attribs[] =
					{
						WGL_CONTEXT_MAJOR_VERSION_ARB, OPENGL_CONTEXT_MAJOR_VERSION,
						WGL_CONTEXT_MINOR_VERSION_ARB, OPENGL_CONTEXT_MINOR_VERSION,
						WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
						WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
						0
					};

					GLenum err = glewInit();
					if (GLEW_OK != err)
						BF_LOG_ERROR("Error: %s", glewGetErrorString(err));

					if (wglewIsSupported("WGL_ARB_create_context") == 1)
					{
						HGLRC context = wglCreateContextAttribsARB(hDC, 0, attribs);
						wglMakeCurrent(NULL, NULL);
						wglDeleteContext(tempContext);
						wglMakeCurrent(hDC, context);
					}
					else
					{
						wglMakeCurrent(NULL, NULL);
						wglDeleteContext(tempContext);
						BF_LOG_ERROR("Failed to create an OpenGL 3.x and above context.");
					}

					GLCall(glViewport(0, 0, Engine::GetWindow().GetClientWidth(), Engine::GetWindow().GetClientHeight()));

					BF_LOG_INFO("OPENGL VERSION %s", (char*)glGetString(GL_VERSION));
					BF_LOG_INFO("Graphics Card: %s - %s", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
					BF_LOG_INFO("Status: Using GLEW %s", glewGetString(GLEW_VERSION));

					GLint r;
					GLCall(glGetIntegerv(GL_MAX_TEXTURE_SIZE, &r));
					BF_LOG_INFO("%d", r);
				}

				void WINGLContext::SetPrimitiveType(PrimitiveType primitiveType)
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

				void WINGLContext::Clear(const Vector4& color)
				{
					GLCall(glClearColor(color.x, color.y, color.z, color.w));
					GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
				}

				void WINGLContext::Draw(GLsizei count)
				{
					GLCall(glDrawElements(GL_PRIMITIVE_TYPE, count, GL_UNSIGNED_INT, nullptr));
				}

				void WINGLContext::SwapBuffers()
				{
					wglSwapLayerBuffers(hDC, WGL_SWAP_MAIN_PLANE);
				}

				void WINGLContext::CleanUp()
				{
					DeleteDC(hDC);
				}

				void WINGLContext::EnableDepthBuffer(bool state)
				{
					if (state)
						GLCall(glEnable(GL_DEPTH_TEST));
					else
						GLCall(glDisable(GL_DEPTH_TEST));
				}

				void WINGLContext::EnableDepthMask(bool state)
				{
					if (state)
						GLCall(glDepthMask(GL_TRUE));
					else
						GLCall(glDepthMask(GL_FALSE));
				}

				void WINGLContext::EnableBlending(bool state)
				{
					if (state)
					{
						GLCall(glEnable(GL_BLEND));
						GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
					}
					else
						GLCall(glDisable(GL_BLEND));
				}

				void WINGLContext::EnableVsync(bool state)
				{
					wglSwapIntervalEXT(state);
				}
			}
		}
	}
}