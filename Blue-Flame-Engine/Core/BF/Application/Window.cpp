#include "Window.h"

namespace BF
{
	namespace Application
	{
		Window::Window(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style) :
			title(title), rectangle(rectangle), style(style), clientWidth(0), clientHeight(0), borderWidth(0), borderHeight(0), borderThickness(0)
		{
		}

		Window::~Window()
		{
		}
	}
}