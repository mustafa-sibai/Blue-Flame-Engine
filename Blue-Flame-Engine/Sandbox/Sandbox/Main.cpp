#pragma once
#include <BF/BlueFlame.h>
#include "RenderTriangle.h"

int main()
{
	BF::Application::Window window("Blue Flame Engine", 0, 0, 1920, 1080, BF::Application::WindowStyle::ResizableWindow);
	RenderTriangle renderTriangle(&window);

	while (window.IsOpen())
	{

		window.Update();
		renderTriangle.Draw();
	}
	return 0;
}