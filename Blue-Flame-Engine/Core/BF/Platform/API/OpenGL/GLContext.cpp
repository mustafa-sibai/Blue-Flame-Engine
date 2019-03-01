#include "GLContext.h"
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
				using namespace BF::Graphics;
				using namespace BF::Graphics::API;

				GLContext::GLContext() :
					initialized(false)
				{
				}

				GLContext::~GLContext()
				{
				}

				void GLContext::Initialize()
				{
				}

				void GLContext::SetPrimitiveType(PrimitiveType primitiveType)
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

				void GLContext::Clear(BufferClearType bufferClearType, const Color& color)
				{
					switch (bufferClearType)
					{
					case BufferClearType::ColorAndDepth:
					{
						GLCall(glClearColor(color.r, color.g, color.b, color.a));
						GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
						break;
					}
					case BufferClearType::Color:
					{
						GLCall(glClearColor(color.r, color.g, color.b, color.a));
						GLCall(glClear(GL_COLOR_BUFFER_BIT));
						break;
					}
					case BufferClearType::Depth:
					{
						GLCall(glClear(GL_DEPTH_BUFFER_BIT));
						break;
					}
					default:
						break;
					}
				}

				void GLContext::Render(GLsizei count)
				{
					GLCall(glDrawElements(GL_PRIMITIVE_TYPE, count, GL_UNSIGNED_INT, nullptr));
				}

				void GLContext::SwapBuffers()
				{
				}

				void GLContext::CleanUp()
				{
				}

				void GLContext::EnableDepthBuffer(bool state)
				{
					if (state)
						GLCall(glEnable(GL_DEPTH_TEST));
					else
						GLCall(glDisable(GL_DEPTH_TEST));
				}

				void GLContext::EnableDepthMask(bool state)
				{
					if (state)
					{
						GLCall(glDepthMask(GL_TRUE));

						//GLCall(glDepthFunc(GL_LESS));
					}
					else
					{
						GLCall(glDepthMask(GL_FALSE));

						//GLCall(glDepthFunc(GL_EQUAL));
					}
				}

				void GLContext::EnableBlending(bool state)
				{
					if (state)
					{
						GLCall(glEnable(GL_BLEND));
						GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
						//GLCall(glBlendFunc(GL_ONE, GL_ONE));
					}
					else
						GLCall(glDisable(GL_BLEND));
				}

				void GLContext::EnableVsync(bool state)
				{
				}

				void GLContext::EnableScissor(bool state)
				{
					if (state)
						glEnable(GL_SCISSOR_TEST);
					else
						glDisable(GL_SCISSOR_TEST);
				}

				void GLContext::SetScissor(const Math::Rectangle& rectangle)
				{
					int height = Engine::GetWindow().GetClientSize().y - rectangle.height - rectangle.y;
					glScissor(rectangle.x, height, rectangle.width, Engine::GetWindow().GetClientSize().y - height - rectangle.y);
				}

				void GLContext::SetViewport(const Math::Rectangle& rectangle)
				{
					if (initialized)
						GLCall(glViewport(rectangle.x, rectangle.y, rectangle.width, rectangle.height));
				}

				void GLContext::SetWindingOrder(WindingOrder windingOrder)
				{
					switch (windingOrder)
					{
					case WindingOrder::Clockwise:
					{
						GLCall(glFrontFace(GL_CW));
						break;
					}
					case WindingOrder::CounterClockwise:
					{
						GLCall(glFrontFace(GL_CCW));
						break;
					}
					default:
						break;
					}
				}

				void GLContext::CullFace(CullingType cullingType)
				{
					switch (cullingType)
					{
					case CullingType::None:
					{
						glDisable(GL_CULL_FACE);
						break;
					}
					case CullingType::Front:
					{
						GLCall(glEnable(GL_CULL_FACE));
						GLCall(glCullFace(GL_FRONT));
						break;
					}
					case CullingType::Back:
					{
						GLCall(glEnable(GL_CULL_FACE));
						GLCall(glCullFace(GL_BACK));
						break;
					}
					case CullingType::FrontAndBack:
					{
						GLCall(glEnable(GL_CULL_FACE));
						GLCall(glCullFace(GL_FRONT_AND_BACK));
						break;
					}
					default:
						break;
					}
				}
			}
		}
	}
}