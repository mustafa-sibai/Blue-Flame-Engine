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

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Escape))
		BF_LOG_INFO("Escape");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F1))
		BF_LOG_INFO("F1");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F2))
		BF_LOG_INFO("F2");

	//if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F3))
		//BF_LOG_INFO("F3");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F4))
		BF_LOG_INFO("F4");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F5))
		BF_LOG_INFO("F5");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F6))
		BF_LOG_INFO("F6");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F7))
		BF_LOG_INFO("F7");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F8))
		BF_LOG_INFO("F8");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F9))
		BF_LOG_INFO("F9");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F10))
		BF_LOG_INFO("F10");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F11))
		BF_LOG_INFO("F11");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F12))
		BF_LOG_INFO("F12");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::PrintScreen))
		BF_LOG_INFO("PrintScreen");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::ScrollLock))
		BF_LOG_INFO("ScrollLock");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Pause))
		BF_LOG_INFO("Pause");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Backquote))
		BF_LOG_INFO("Backquote");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num1))
		BF_LOG_INFO("Num1");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num2))
		BF_LOG_INFO("Num2");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num3))
		BF_LOG_INFO("Num3");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num4))
		BF_LOG_INFO("Num4");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num5))
		BF_LOG_INFO("Num5");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num6))
		BF_LOG_INFO("Num6");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num7))
		BF_LOG_INFO("Num7");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num8))
		BF_LOG_INFO("Num8");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num9))
		BF_LOG_INFO("Num9");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num0))
		BF_LOG_INFO("Num0");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Minus))
		BF_LOG_INFO("Minus");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Equal))
		BF_LOG_INFO("Equal");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::BackSpace))
		BF_LOG_INFO("BackSpace");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Insert))
		BF_LOG_INFO("Insert");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Home))
		BF_LOG_INFO("Home");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::PageUp))
		BF_LOG_INFO("PageUp");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumLock))
		BF_LOG_INFO("NumLock");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumpadDivide))
		BF_LOG_INFO("NumpadDivide");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumpadMultiply))
		BF_LOG_INFO("NumpadMultiply");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumpadSubtract))
		BF_LOG_INFO("NumpadSubtract");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Tab))
		BF_LOG_INFO("Tab");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Q))
		BF_LOG_INFO("Q");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::W))
		BF_LOG_INFO("W");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::E))
		BF_LOG_INFO("E");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::R))
		BF_LOG_INFO("R");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::T))
		BF_LOG_INFO("T");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Y))
		BF_LOG_INFO("Y");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::U))
		BF_LOG_INFO("U");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::I))
		BF_LOG_INFO("I");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::O))
		BF_LOG_INFO("O");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::P))
		BF_LOG_INFO("P");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::OpenBracket))
		BF_LOG_INFO("OpenBracket");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::ClosedBracket))
		BF_LOG_INFO("ClosedBracket");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Backslash))
		BF_LOG_INFO("Backslash");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Delete))
		BF_LOG_INFO("Delete");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::End))
		BF_LOG_INFO("End");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::PageDown))
		BF_LOG_INFO("PageDown");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad7))
		BF_LOG_INFO("Numpad7");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad8))
		BF_LOG_INFO("Numpad8");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad9))
		BF_LOG_INFO("Numpad9");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumpadAdd))
		BF_LOG_INFO("NumpadAdd");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::CapsLock))
		BF_LOG_INFO("CapsLock");


	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::A))
		BF_LOG_INFO("A Pressed");

	if (Keyboard::IsKeyDown(Keyboard::Key::Code::A))
		BF_LOG_INFO("A Down");

	if (Keyboard::IsKeyUp(Keyboard::Key::Code::A))
		BF_LOG_INFO("A Up");


	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::S))
		BF_LOG_INFO("S");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::D))
		BF_LOG_INFO("D");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::F))
		BF_LOG_INFO("F");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::G))
		BF_LOG_INFO("G");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::H))
		BF_LOG_INFO("H");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::J))
		BF_LOG_INFO("J");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::K))
		BF_LOG_INFO("K");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::L))
		BF_LOG_INFO("L");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Semicolon))
		BF_LOG_INFO("Semicolon");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Quote))
		BF_LOG_INFO("Quote");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Enter))
		BF_LOG_INFO("Enter");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad4))
		BF_LOG_INFO("Numpad4");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad5))
		BF_LOG_INFO("Numpad5");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad6))
		BF_LOG_INFO("Numpad6");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::LeftShift))
		BF_LOG_INFO("LeftShift");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Z))
		BF_LOG_INFO("Z");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::X))
		BF_LOG_INFO("X");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::C))
		BF_LOG_INFO("C");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::V))
		BF_LOG_INFO("V");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::B))
		BF_LOG_INFO("B");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::N))
		BF_LOG_INFO("N");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::M))
		BF_LOG_INFO("M");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Comma))
		BF_LOG_INFO("Comma");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Period))
		BF_LOG_INFO("Period");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Slash))
		BF_LOG_INFO("Slash");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::RightShift))
		BF_LOG_INFO("RightShift");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::UpArrow))
		BF_LOG_INFO("UpArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad1))
		BF_LOG_INFO("Numpad1");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad2))
		BF_LOG_INFO("Numpad2");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad3))
		BF_LOG_INFO("Numpad3");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumpadEnter))
		BF_LOG_INFO("NumpadEnter");

	//-----------------------------------------------------------------

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::LeftControl))
		BF_LOG_INFO("LeftControl");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::WindowKey))
		BF_LOG_INFO("WindowKey");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::LeftAlt))
		BF_LOG_INFO("LeftAlt");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Space))
		BF_LOG_INFO("Space");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::RightAlt))
		BF_LOG_INFO("RightAlt");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Menu))
		BF_LOG_INFO("Menu");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::RightControl))
		BF_LOG_INFO("RightControl");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::LeftArrow))
		BF_LOG_INFO("LeftArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::DownArrow))
		BF_LOG_INFO("DownArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::RightArrow))
		BF_LOG_INFO("RightArrow");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Numpad0))
		BF_LOG_INFO("Numpad0");

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::NumpadDecimal))
		BF_LOG_INFO("NumpadDecimal");


	//---------------------------------------------------------
	//Controller Test
	//---------------------------------------------------------


	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::A))
		BF_LOG_INFO("A Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::B))
		BF_LOG_INFO("B Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::X))
		BF_LOG_INFO("X Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Y))
		BF_LOG_INFO("Y Pressed !");

	//---------------------------------------------------------

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Up))
		BF_LOG_INFO("Up Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Down))
		BF_LOG_INFO("Down Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Left))
		BF_LOG_INFO("Left Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Right))
		BF_LOG_INFO("Right Pressed !");

	//---------------------------------------------------------

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::LeftShoulder))
		BF_LOG_INFO("LeftShoulder Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::RightShoulder))
		BF_LOG_INFO("RightShoulder Pressed !");

	BF_LOG_INFO("leftBumperX %f, leftBumperY %f RightBumperX %f, RightBumperY %f ", BF::Input::Controllers::Primary().GetLeftStike().x, BF::Input::Controllers::Primary().GetLeftStike().y,
																					BF::Input::Controllers::Primary().GetRightStike().x, BF::Input::Controllers::Primary().GetRightStike().y);
	//---------------------------------------------------------

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Start))
		BF_LOG_INFO("Start Pressed !");

	if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Back))
		BF_LOG_INFO("Back Pressed !");

	//---------------------------------------------------------

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::A))
		BF_LOG_INFO("A Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::B))
		BF_LOG_INFO("B Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::X))
		BF_LOG_INFO("X Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Y))
		BF_LOG_INFO("Y Pressed !");

	//---------------------------------------------------------

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Up))
		BF_LOG_INFO("Up Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Down))
		BF_LOG_INFO("Down Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Left))
		BF_LOG_INFO("Left Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Right))
		BF_LOG_INFO("Right Pressed !");

	//---------------------------------------------------------

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Start))
		BF_LOG_INFO("Start Pressed !");

	if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Back))
		BF_LOG_INFO("Back Pressed !");
}

void InputTests::Render()
{
	Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));
	Engine::GetContext().SwapBuffers();
}