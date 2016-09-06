#include <iostream>
#include <BFE/Graphics/Window.h>
#include <BFE/Input/Mouse.h>
#include "RenderTriangle.h"

using namespace BFE::Graphics;
using namespace BFE::Input;

int main()
{BFE::Graphics::Window window("", 0, 0, 1280, 720, Window::Style::Windowed, Renderer::RenderingAPI::DirectX11);

	if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
		window.SetWindowTitle("Blue Flame Engine - DirectX 11");
	else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
		window.SetWindowTitle("Blue Flame Engine - OpenGL 4.5");

	RenderTriangle renderTriangle(window);

	while (window.IsOpen())
	{
		//std::cout << BFE::Input::Mouse::GetPosition() << std::endl;
		window.Update();
		renderTriangle.Draw();
	}

	renderTriangle.CleanUp();
	return 0;
}