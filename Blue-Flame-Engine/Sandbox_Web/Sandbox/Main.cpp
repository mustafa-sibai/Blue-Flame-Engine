#include <BF/BlueFlame.h>
#include "_2DScene.h"

int main()
{
	BF::Engine engine(BF::Application::Window("Blue Flame Engine", BF::Math::Rectangle(800, 250, 1920, 1080), BF::Application::WindowStyle::Windowed), BF::Graphics::API::RenderAPI::OpenGL);

	BF::Application::SceneManager::AddNewScene(new _2DScene::_2DScene());
	BF::Application::SceneManager::GetScene(0).Run();
	engine.Run();

	return 0;
}