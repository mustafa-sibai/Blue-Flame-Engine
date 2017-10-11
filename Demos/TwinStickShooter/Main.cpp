#include <BF/BlueFlame.h>
#include "MainScene.h"

using namespace BF;
using namespace BF::Application;
using namespace BF::Graphics::API;

int main()
{
	Engine engine(Application::Window("TwinStickShooter", Math::Rectangle(0, 0, 1920, 1080), Application::WindowStyle::ResizableWindow), RenderAPI::OpenGL);

	MainScene mainScene;
	engine.Run(mainScene);

	return 0;
}