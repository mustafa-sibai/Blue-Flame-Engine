#include <BF/BlueFlame.h>
#include "../../Sandbox/Sandbox/InputTests.h"
#include "../../Sandbox/Sandbox/_2DScene.h"

int main()
{
	_2DScene::_2DScene _2d;
	InputTests inputTests;
	BF::Engine engine(BF::Application::Window("Blue Flame Engine", BF::Math::Rectangle(800, 250, 1920, 1080), BF::Application::WindowStyle::Windowed), BF::Graphics::API::RenderAPI::OpenGL);
	engine.Run(_2d);

	return 0;
}