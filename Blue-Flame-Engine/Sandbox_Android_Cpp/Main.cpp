//#include <BF/BlueFlame.h>
#include <BF/Engine.h>
#include "AndroidTestScene.h"

int main()
{
	AndroidTestScene androidTestScene;
	BF::Engine engine(BF::Application::Window("Blue Flame Engine", BF::Math::Rectangle(800, 250, 1920, 1080), BF::Application::WindowStyle::ResizableWindow), BF::Graphics::API::RenderAPI::OpenGL);
	engine.Run(androidTestScene);

	return 0;
}