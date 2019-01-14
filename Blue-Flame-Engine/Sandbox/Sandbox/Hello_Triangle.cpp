#include "Hello_Triangle.h"

namespace Hello_Triangle
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;

	Hello_Triangle::Hello_Triangle()
	{
	}

	Hello_Triangle::~Hello_Triangle()
	{
	}

	void Hello_Triangle::Initialize()
	{
		scene = new Scene(camera);

		App::Initialize();

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetPrimitiveType(BF::Graphics::API::PrimitiveType::TriangleList);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		//camera.Initialize(Matrix4::Orthographic(-((int)Engine::GetWindow().GetClientWidth() / 2), (int)(Engine::GetWindow().GetClientWidth() / 2), ((int)Engine::GetWindow().GetClientHeight() / 2), -(int)(Engine::GetWindow().GetClientHeight() / 2), -1.0f, 1.0f));

		camera.Initialize(Matrix4::Orthographic(-5, 5, 5, -5, -1.0f, 1.0f));

		shader.LoadFromFile("C:/engine/Blue-Flame-Engine/Sandbox/Assets/Shaders/GLSL/Simple/VertexShader.glsl", "C:/engine/Blue-Flame-Engine/Sandbox/Assets/Shaders/GLSL/Simple/PixelShader.glsl");

		vertices[0] = Vector3f(-0.5, -0.5, 0);
		vertices[1] = Vector3f(0, 0.5, 0);
		vertices[2] = Vector3f(0.5, -0.5, 0);

		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;

		vb.Create(sizeof(Vector3f) * 3, &vertices[0]);
		ib.Create(&indices[0], 3);
		vbl.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, sizeof(Vector3f), 0);
		vb.SetLayout(shader, &vbl);
	}

	void Hello_Triangle::Load()
	{
		App::Load();
	}

	void Hello_Triangle::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void Hello_Triangle::Update()
	{
		camera.Update();
		App::Update();
	}

	void Hello_Triangle::Render()
	{
		BF::Engine::GetContext().Clear(BufferClearType::ColorAndDepth, Color(0.5, 0.0f, 0.0f, 1.0f));

		position.y += 0.0001f;
		camera.SetModelMatrix(Matrix4::Translate(position));

		shader.Bind();
		vb.Bind();
		ib.Bind();
		BF::Engine::GetContext().Draw(ib.GetIndicesCount());
		ib.Unbind();
		vb.Unbind();
		shader.Unbind();

		//App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}