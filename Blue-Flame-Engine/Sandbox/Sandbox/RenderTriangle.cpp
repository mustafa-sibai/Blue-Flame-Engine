#include "RenderTriangle.h"

using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::API;
using namespace BF::Graphics::Renderers;
using namespace BF::Math;
using namespace BF::System;

RenderTriangle::RenderTriangle(BF::Application::Window* window) :
	window(window), context(nullptr), shader(nullptr), spriteRenderer(nullptr),/* model(nullptr),*/ constentBuffer(nullptr), /*fpsCamera(nullptr),*/ initBuffer()
{
	timer = new Timer();
	context = new Context(window, RenderAPI::OpenGL);
	shader = new Shader(context);

	constentBuffer = new ConstentBuffer(context, shader);
	//model = new Model(context, shader);
	//fpsCamera = new FPSCamera(Matrix4::Perspective(90.0f, window->GetAspectRatio(), 1.0f, 12.0f));

	
	
#if BF_PLATFORM_WINDOWS
	if (Context::GetRenderAPI() == RenderAPI::DirectX)
		shader->Load("Assets/Shaders/HLSL/Compiled/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/PixelShader.cso");
	else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
		shader->Load("Assets/Shaders/GLSL/VertexShader.glsl", "Assets/Shaders/GLSL/FragmentShader.glsl");

	//model->Load("Assets/A380.obj");
	//model->Load("Assets/Cube.obj_");
	//model->Load("Assets/Models/MultiMeshAndTexturedCubes/MultiMeshAndTexturedCubes.obj");
#endif

#if BF_PLATFORM_LINUX
	if (Context::GetRenderAPI() == RenderAPI::OpenGL)
		shader->Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");

	//texture2D->Load("projects/Sandbox-Linux/Sandbox/silver.png");
	//model->Load("projects/Sandbox-Linux/Sandbox/A380.obj");
#endif

	shader->Bind();

	spriteRenderer = new SpriteRenderer(context, shader);

	initBuffer.modelMatrix = Matrix4::Identity();
	initBuffer.color = Vector4(1.0f, 0.0f, 0.5f, 1.0f);
	constentBuffer->Create(&initBuffer, sizeof(initBuffer), 0);

	context->SetPrimitiveType(PrimitiveType::TriangleList);


	Texture2D* t = new Texture2D(context);
	t->Load("Assets/Textures/silver.png");
	sprites = new std::vector<BF::Graphics::Renderers::Sprite*>();

	//for (size_t y = 0; y < 160; y++)
		//for (size_t x = 0; x < 300; x++)
			sprites->push_back(new Sprite(t, Vector3(910.0f, 490.0f, 0.0f), Vector2(100.0f, 100.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));

	initBuffer.viewMatrix = Matrix4::LookAt(Vector3(15.0f, 0, 0), Vector3(35.0f, 0.0f, 10), Vector3(0, 1, 0));
}

RenderTriangle::~RenderTriangle()
{
}

void RenderTriangle::Draw()
{
	++frames;

	//fpsCamera->Update();
	context->Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

	angle += 0.050f;
	initBuffer.color = Vector4(0.2f, 0.5f, 0.3f, 1.0f);
	//coulmn major in c++ 
	//initBuffer.modelMatrix = fpsCamera->GetProjectionMatrix() * Matrix4::Translate(Vector3(0.0, 0.0f, 1.0f))  * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(0.5f, 0.5f, 0.5f));
	initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, 0.0f, 0.0f));//* * Matrix4::Rotate(angle, Vector3(0, 0, 1));  Matrix4::Scale(Vector3(0.5f, 0.5f, 0.5f));*///Matrix4::Translate(Vector3(0.0, 0.0f, 1.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(0.5f, 0.5f, 0.5f));
	//initBuffer.viewMatrix = fpsCamera->GetViewMatrix();
	//initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, 0.0f, 5.0f));
	//initBuffer.projectionMatrix = Matrix4::Perspective(90.0f, window->GetAspectRatio(), 0.1f, 1500.0f);
	//initBuffer.modelMatrix = Matrix4::Translate(Vector3(100.0f, 100.0f, 0.0f));
	initBuffer.projectionMatrix = Matrix4::Orthographic(0.0f, 1920.0f, 0.0f, 1080.0f, -1.0f, 1.0f);
	constentBuffer->Update(&initBuffer, sizeof(initBuffer));
	//model->Draw();

	
	spriteRenderer->Begin(SpriteRenderer::SubmitType::DynamicSubmit);
	for (size_t i = 0; i < sprites->size(); i++)
		spriteRenderer->Submit(sprites[0][i]);
	spriteRenderer->End();
	

	spriteRenderer->Draw();
	
	context->SwapBuffers();

	if (timer->GetElapsedTimeInSeconds() >= 1.0f)
	{
		std::cout << frames << std::endl;
		timer->Reset();
		frames = 0;
	}
}

void RenderTriangle::CleanUp()
{
	shader->CleanUp();
	//context->CleanUp();
}