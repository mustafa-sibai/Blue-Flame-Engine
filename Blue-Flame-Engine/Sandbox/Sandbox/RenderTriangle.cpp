#include "RenderTriangle.h"

RenderTriangle::RenderTriangle(Window *window) :
	window(window), context(nullptr), shader(nullptr), model(nullptr), constentBuffer(nullptr), texture2D(nullptr), initBuffer()
{
	context = new Context(window, BF::Graphics::API::RenderAPI::OpenGL);
	shader = new Shader(context);

	texture2D = new Texture2D(context);
	constentBuffer = new ConstentBuffer(context, shader);
	model = new Model(context, shader);

	if (BF::Graphics::API::Context::GetRenderAPI() == BF::Graphics::API::RenderAPI::DirectX)
	{
		shader->Load("D:/Projects/Personal-Projects/Blue-Flame-Engine/Blue-Flame-Engine/Output/Sandbox/Windows/x64/Binary/Debug/VertexShader.cso",
			"D:/Projects/Personal-Projects/Blue-Flame-Engine/Blue-Flame-Engine/Output/Sandbox/Windows/x64/Binary/Debug/PixelShader.cso");
	}
	else if (BF::Graphics::API::Context::GetRenderAPI() == BF::Graphics::API::RenderAPI::OpenGL)
	{
		shader->Load("Sandbox/VertexShader.glsl", "Sandbox/FragmentShader.glsl");
	}
	
	texture2D->Load("Sandbox/test.png");
	model->Load("sandbox/untitled.obj_");

	shader->Bind();

	initBuffer.modelMatrix = Matrix4::Scale(Vector3(2.0f, 2.0f, 2.0f)) * Matrix4::Translate(Vector3(0.0f, -0.2f, 0.0f));
	initBuffer.color = Vector4(1.0f, 0.0f, 0.5f, 1.0f);
	constentBuffer->Create(&initBuffer, sizeof(initBuffer), 0);

	context->SetPrimitiveType(PrimitiveType::TriangleList);
	texture2D->Bind();
}

RenderTriangle::~RenderTriangle()
{
}

void RenderTriangle::Draw()
{
	context->Clear(Vector4(0.5, 0.0f, 0.5f, 1.0f));

	angle += 1.50f;
	initBuffer.color = Vector4(0.2f, 0.5f, 0.3f, 1.0f);
	initBuffer.modelMatrix = Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(0.5f, 0.5f, 0.5f)) * Matrix4::Translate(Vector3(0, -2.0f, 5.0f)) * Matrix4::Perspective(90.0f, window->GetAspectRatio(), 0.1f, 1000.0f);
	constentBuffer->Update(&initBuffer, sizeof(initBuffer));
	
	model->Draw();
	context->SwapBuffers();
}

void RenderTriangle::CleanUp()
{
	shader->CleanUp();
	//context->CleanUp();
}