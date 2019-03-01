#include "Window.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::Math;

		Window::Window(const string& title, const Vector2i& position, const Vector2i& clientSize, WindowStyle style) :
			title(title), position(position), clientSize(clientSize), style(style), borderThickness(0)
		{
		}

		Window::~Window()
		{
		}
	}
}