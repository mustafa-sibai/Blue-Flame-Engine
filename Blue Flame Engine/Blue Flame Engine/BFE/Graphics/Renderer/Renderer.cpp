#include "Renderer.h"
#include "../Window.h"

namespace BFE
{
	namespace Graphics
	{
		Renderer::RenderingAPI Renderer::renderingAPI;

		Renderer::Renderer(Window &window) :
			window(window), dx11Renderer(window), glRenderer(window), GL_PRIMITIVE_TYPE(0)
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

		void Renderer::SetPrimitiveType(PrimitiveType primitiveType)
		{
			D3D_PRIMITIVE_TOPOLOGY D3DPrimitiveType = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;

			switch (primitiveType)
			{
				case Renderer::PointList:
				{
					if (renderingAPI == RenderingAPI::DirectX11)
						D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
					else if (renderingAPI == RenderingAPI::OpenGL4_5)
						GL_PRIMITIVE_TYPE = GL_POINTS;
					break;
				}
				case Renderer::LineList:
				{
					if (renderingAPI == RenderingAPI::DirectX11)
						D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
					else if (renderingAPI == RenderingAPI::OpenGL4_5)
						GL_PRIMITIVE_TYPE = GL_LINES;
					break;
				}
				case Renderer::LineStrip:
				{
					if (renderingAPI == RenderingAPI::DirectX11)
						D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP;
					else if (renderingAPI == RenderingAPI::OpenGL4_5)
						GL_PRIMITIVE_TYPE = GL_LINE_STRIP;
					break;
				}
				case Renderer::TriangleList:
				{
					if (renderingAPI == RenderingAPI::DirectX11)
						D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
					else if (renderingAPI == RenderingAPI::OpenGL4_5)
						GL_PRIMITIVE_TYPE = GL_TRIANGLES;
					break;
				}
				case Renderer::TriangeStrip:
				{
					if (renderingAPI == RenderingAPI::DirectX11)
						D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
					else if (renderingAPI == RenderingAPI::OpenGL4_5)
						GL_PRIMITIVE_TYPE = GL_TRIANGLE_STRIP;
					break;
				}
				default:
					break;
			}

			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.GetContext().IASetPrimitiveTopology(D3DPrimitiveType);
		}

		void Renderer::Clear(Math::Vector4 Color)
		{
			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.Clear(Color);
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
				glRenderer.Clear(Color);
		}

		void Renderer::Draw(const unsigned int vertexCount)
		{
			if (renderingAPI == RenderingAPI::DirectX11)
				dx11Renderer.GetContext().Draw(vertexCount, 0);
			else if (renderingAPI == RenderingAPI::OpenGL4_5)
				glDrawArrays(GL_PRIMITIVE_TYPE, 0, vertexCount);
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