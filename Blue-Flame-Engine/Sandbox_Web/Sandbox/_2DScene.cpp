#include "_2DScene.h"

namespace _2DScene
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::GUI;
	using namespace BF::Math;
	using namespace BF::System;

	_2DScene::_2DScene()
	{
	}

	_2DScene::~_2DScene()
	{
	}

	void _2DScene::Initialize()
	{
	}

	void _2DScene::Load()
	{
	}

	void _2DScene::FixedUpdate()
	{
	}

	void _2DScene::Update()
	{
		if(BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Left))
			BF_LOG_INFO("LEFT PRESSED !!");

		if (BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Right))
			BF_LOG_INFO("Right PRESSED !!");

		if (BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Middle))
			BF_LOG_INFO("Middle PRESSED !!");



		/*if (!BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Left))
			BF_LOG_INFO("LEFT REleased !!");

		if (!BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Right))
			BF_LOG_INFO("Right REleased !!");

		if (!BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Middle))
			BF_LOG_INFO("Middle REleased !!");*/


		//BF_LOG_INFO("MouseX: %f, MouseY: %f", BF::Input::Mouse::GetPosition().x, BF::Input::Mouse::GetPosition().y);
	}

	void _2DScene::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));
		BF::Engine::GetContext().SwapBuffers();
	}
}