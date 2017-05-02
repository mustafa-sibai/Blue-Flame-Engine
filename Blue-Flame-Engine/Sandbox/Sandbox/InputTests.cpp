#include "InputTests.h"

using namespace BF;
using namespace BF::Graphics;
using namespace BF::Input;

InputTests::InputTests()
{
}

InputTests::~InputTests()
{
}

void InputTests::Initialize()
{
}

void InputTests::Load()
{
}

/*void InputTests::FixedUpdate()
{
}*/

void InputTests::Update()
{
	if (BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Left))
		BF_LOG_INFO("LEFT PRESSED !!");

	if (BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Right))
		BF_LOG_INFO("Right PRESSED !!");

	if (BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Middle))
		BF_LOG_INFO("Middle PRESSED !!");

	/*
		Window Issues:-
		F10 not detected
		print Screen not detected
		Enter and Numpad Enter Should be different
		Left and right shit should be different
		Alt keys not working
		Right and Left Control Should be different
	*/

	if (Keyboard::IsKeyPressed(Keyboard::Key::Escape))
		BF_LOG_INFO("Escape");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F1))
		BF_LOG_INFO("F1");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F2))
		BF_LOG_INFO("F2");

	//if (Keyboard::IsKeyPressed(Keyboard::Key::F3))
		//BF_LOG_INFO("F3");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F4))
		BF_LOG_INFO("F4");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F5))
		BF_LOG_INFO("F5");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F6))
		BF_LOG_INFO("F6");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F7))
		BF_LOG_INFO("F7");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F8))
		BF_LOG_INFO("F8");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F9))
		BF_LOG_INFO("F9");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F10))
		BF_LOG_INFO("F10");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F11))
		BF_LOG_INFO("F11");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F12))
		BF_LOG_INFO("F12");

	if (Keyboard::IsKeyPressed(Keyboard::Key::PrintScreen))
		BF_LOG_INFO("PrintScreen");

	if (Keyboard::IsKeyPressed(Keyboard::Key::ScrollLock))
		BF_LOG_INFO("ScrollLock");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Pause))
		BF_LOG_INFO("Pause");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Backquote))
		BF_LOG_INFO("Backquote");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num1))
		BF_LOG_INFO("Num1");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num2))
		BF_LOG_INFO("Num2");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num3))
		BF_LOG_INFO("Num3");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num4))
		BF_LOG_INFO("Num4");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num5))
		BF_LOG_INFO("Num5");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num6))
		BF_LOG_INFO("Num6");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num7))
		BF_LOG_INFO("Num7");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num8))
		BF_LOG_INFO("Num8");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num9))
		BF_LOG_INFO("Num9");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Num0))
		BF_LOG_INFO("Num0");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Minus))
		BF_LOG_INFO("Minus");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Equal))
		BF_LOG_INFO("Equal");

	if (Keyboard::IsKeyPressed(Keyboard::Key::BackSpace))
		BF_LOG_INFO("BackSpace");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Insert))
		BF_LOG_INFO("Insert");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Home))
		BF_LOG_INFO("Home");

	if (Keyboard::IsKeyPressed(Keyboard::Key::PageUp))
		BF_LOG_INFO("PageUp");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumLock))
		BF_LOG_INFO("NumLock");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumpadDivide))
		BF_LOG_INFO("NumpadDivide");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumpadMultiply))
		BF_LOG_INFO("NumpadMultiply");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumpadSubtract))
		BF_LOG_INFO("NumpadSubtract");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Tab))
		BF_LOG_INFO("Tab");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Q))
		BF_LOG_INFO("Q");

	if (Keyboard::IsKeyPressed(Keyboard::Key::W))
		BF_LOG_INFO("W");

	if (Keyboard::IsKeyPressed(Keyboard::Key::E))
		BF_LOG_INFO("E");

	if (Keyboard::IsKeyPressed(Keyboard::Key::R))
		BF_LOG_INFO("R");

	if (Keyboard::IsKeyPressed(Keyboard::Key::T))
		BF_LOG_INFO("T");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Y))
		BF_LOG_INFO("Y");

	if (Keyboard::IsKeyPressed(Keyboard::Key::U))
		BF_LOG_INFO("U");

	if (Keyboard::IsKeyPressed(Keyboard::Key::I))
		BF_LOG_INFO("I");

	if (Keyboard::IsKeyPressed(Keyboard::Key::O))
		BF_LOG_INFO("O");

	if (Keyboard::IsKeyPressed(Keyboard::Key::P))
		BF_LOG_INFO("P");

	if (Keyboard::IsKeyPressed(Keyboard::Key::OpenBracket))
		BF_LOG_INFO("OpenBracket");

	if (Keyboard::IsKeyPressed(Keyboard::Key::ClosedBracket))
		BF_LOG_INFO("ClosedBracket");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Backslash))
		BF_LOG_INFO("Backslash");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Delete))
		BF_LOG_INFO("Delete");

	if (Keyboard::IsKeyPressed(Keyboard::Key::End))
		BF_LOG_INFO("End");

	if (Keyboard::IsKeyPressed(Keyboard::Key::PageDown))
		BF_LOG_INFO("PageDown");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad7))
		BF_LOG_INFO("Numpad7");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad8))
		BF_LOG_INFO("Numpad8");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad9))
		BF_LOG_INFO("Numpad9");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumpadAdd))
		BF_LOG_INFO("NumpadAdd");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::CapsLock))
		BF_LOG_INFO("CapsLock");

	if (Keyboard::IsKeyPressed(Keyboard::Key::A))
		BF_LOG_INFO("A");

	if (Keyboard::IsKeyPressed(Keyboard::Key::S))
		BF_LOG_INFO("S");

	if (Keyboard::IsKeyPressed(Keyboard::Key::D))
		BF_LOG_INFO("D");

	if (Keyboard::IsKeyPressed(Keyboard::Key::F))
		BF_LOG_INFO("F");

	if (Keyboard::IsKeyPressed(Keyboard::Key::G))
		BF_LOG_INFO("G");

	if (Keyboard::IsKeyPressed(Keyboard::Key::H))
		BF_LOG_INFO("H");

	if (Keyboard::IsKeyPressed(Keyboard::Key::J))
		BF_LOG_INFO("J");

	if (Keyboard::IsKeyPressed(Keyboard::Key::K))
		BF_LOG_INFO("K");

	if (Keyboard::IsKeyPressed(Keyboard::Key::L))
		BF_LOG_INFO("L");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Semicolon))
		BF_LOG_INFO("Semicolon");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Quote))
		BF_LOG_INFO("Quote");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Enter))
		BF_LOG_INFO("Enter");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad4))
		BF_LOG_INFO("Numpad4");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad5))
		BF_LOG_INFO("Numpad5");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad6))
		BF_LOG_INFO("Numpad6");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::LeftShift))
		BF_LOG_INFO("LeftShift");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Z))
		BF_LOG_INFO("Z");

	if (Keyboard::IsKeyPressed(Keyboard::Key::X))
		BF_LOG_INFO("X");

	if (Keyboard::IsKeyPressed(Keyboard::Key::C))
		BF_LOG_INFO("C");

	if (Keyboard::IsKeyPressed(Keyboard::Key::V))
		BF_LOG_INFO("V");

	if (Keyboard::IsKeyPressed(Keyboard::Key::B))
		BF_LOG_INFO("B");

	if (Keyboard::IsKeyPressed(Keyboard::Key::N))
		BF_LOG_INFO("N");

	if (Keyboard::IsKeyPressed(Keyboard::Key::M))
		BF_LOG_INFO("M");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Comma))
		BF_LOG_INFO("Comma");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Period))
		BF_LOG_INFO("Period");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Slash))
		BF_LOG_INFO("Slash");

	if (Keyboard::IsKeyPressed(Keyboard::Key::RightShift))
		BF_LOG_INFO("RightShift");

	if (Keyboard::IsKeyPressed(Keyboard::Key::UpArrow))
		BF_LOG_INFO("UpArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad1))
		BF_LOG_INFO("Numpad1");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad2))
		BF_LOG_INFO("Numpad2");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad3))
		BF_LOG_INFO("Numpad3");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumpadEnter))
		BF_LOG_INFO("NumpadEnter");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::LeftControl))
		BF_LOG_INFO("LeftControl");

	if (Keyboard::IsKeyPressed(Keyboard::Key::WindowKey))
		BF_LOG_INFO("WindowKey");

	if (Keyboard::IsKeyPressed(Keyboard::Key::LeftAlt))
		BF_LOG_INFO("LeftAlt");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Space))
		BF_LOG_INFO("Space");

	if (Keyboard::IsKeyPressed(Keyboard::Key::RightAlt))
		BF_LOG_INFO("RightAlt");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Menu))
		BF_LOG_INFO("Menu");

	if (Keyboard::IsKeyPressed(Keyboard::Key::RightControl))
		BF_LOG_INFO("RightControl");

	if (Keyboard::IsKeyPressed(Keyboard::Key::LeftArrow))
		BF_LOG_INFO("LeftArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::DownArrow))
		BF_LOG_INFO("DownArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::RightArrow))
		BF_LOG_INFO("RightArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Numpad0))
		BF_LOG_INFO("Numpad0");

	if (Keyboard::IsKeyPressed(Keyboard::Key::NumpadDecimal))
		BF_LOG_INFO("NumpadDecimal");
}

void InputTests::Render()
{
	Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));
	Engine::GetContext().SwapBuffers();
}