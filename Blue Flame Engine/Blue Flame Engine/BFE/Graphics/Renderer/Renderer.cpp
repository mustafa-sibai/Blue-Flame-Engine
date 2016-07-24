#include "Renderer.h"
#include "../Window.h"

namespace BFE
{
	namespace Graphics
	{
		Renderer::RenderingAPI Renderer::renderingAPI;

		Renderer::Renderer(Window &window) :
			window(window), dx11Renderer(window), glRenderer(window)
		{

		}

		Renderer::~Renderer()
		{
		}

		void Renderer::Initialize()
		{
			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.Initialize();
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
				glRenderer.Initialize();
		}

		void Renderer::Clear(Math::Vector4 Color)
		{
			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.Clear(Color);
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
				glRenderer.Clear(Color);
		}

		void Renderer::Draw(PrimitiveType primitiveType, const unsigned int vertexCount)
		{
			if (renderingAPI == RenderingAPI::DirectX11)
			{
				switch (primitiveType)
				{
					case Renderer::PointList:
					{
						dx11Renderer.GetContext().IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
						break;
					}
					case Renderer::LineList:
					{
						dx11Renderer.GetContext().IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
						break;
					}
					case Renderer::LineStrip:
					{
						dx11Renderer.GetContext().IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
						break;
					}
					case Renderer::TriangleList:
					{
						dx11Renderer.GetContext().IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
						break;
					}
					case Renderer::TriangeStrip:
					{
						dx11Renderer.GetContext().IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
						break;
					}
					default:
						break;
				}

				dx11Renderer.GetContext().Draw(vertexCount, 0);
			}
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
			{
				GLuint PRIMITIVE_TYPE = 0;

				switch (primitiveType)
				{
					case Renderer::PointList:
					{
						PRIMITIVE_TYPE = GL_POINTS;
						break;
					}
					case Renderer::LineList:
					{
						PRIMITIVE_TYPE = GL_LINES;
						break;
					}
					case Renderer::LineStrip:
					{
						PRIMITIVE_TYPE = GL_LINE_STRIP;
						break;
					}
					case Renderer::TriangleList:
					{
						PRIMITIVE_TYPE = GL_TRIANGLES;
						break;
					}
					case Renderer::TriangeStrip:
					{
						PRIMITIVE_TYPE = GL_TRIANGLE_STRIP;
						break;
					}
					default:
						break;
				}

				glDrawArrays(PRIMITIVE_TYPE, 0, vertexCount);
			}
		}

		void Renderer::SwapBuffers()
		{
			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.SwapBuffers();
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
				glRenderer.SwapBuffers();
		}

		void Renderer::CleanUp()
		{
			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.CleanUp();
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
				glRenderer.CleanUp();
		}
	}
}