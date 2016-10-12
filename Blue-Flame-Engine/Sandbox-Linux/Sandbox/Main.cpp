#include <BF/Application/Window.h>
#include "RenderTriangle.h"

int main()
{
	BF::Application::Window window("", 0, 0, 1280, 720, BF::Application::WindowStyle::Windowed);
	RenderTriangle renderTriangle(&window);

	while (window.IsOpen())
	{
		window.Update();
		renderTriangle.Draw();
	}

	return 0;
}