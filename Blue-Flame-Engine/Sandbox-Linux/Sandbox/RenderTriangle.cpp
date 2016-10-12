#include "RenderTriangle.h"

RenderTriangle::RenderTriangle(Window *window) :
	window(window), context(nullptr), shader(nullptr), buffer1(nullptr), /*buffer2(nullptr),*/ indexBuffer(nullptr), vertexBufferLayout(nullptr),
	constentBuffer(nullptr), texture2D(nullptr), objReader(), initBuffer()
{
	context = new Context(window, BF::Graphics::API::RenderAPI::OpenGL);
	shader = new Shader(context);

	buffer1 = new VertexBuffer(context, shader);
	//buffer2 = new VertexBuffer(context, shader);
	texture2D = new Texture2D(context);
	constentBuffer = new ConstentBuffer(context, shader);
	indexBuffer = new IndexBuffer(context);

	objReader.Load("sandbox/deer-obj.obj");

	//create vertices clockwise
	/*tri1Vertices[0].position = Vector3(-1.0f, 1.0f, 0.0f);
	tri1Vertices[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	tri1Vertices[0].UV = Vector2(0.0f, 1.0f);

	tri1Vertices[1].position = Vector3(1.0f, 1.0f, 0.0f);
	tri1Vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	tri1Vertices[1].UV = Vector2(1.0f, 1.0f);

	tri1Vertices[2].position = Vector3(1.0f, -1.0f, 0.0f);
	tri1Vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	tri1Vertices[2].UV = Vector2(1.0f, 0.0f);

	tri1Vertices[3].position = Vector3(-1.0f, -1.0f, 0.0f);
	tri1Vertices[3].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	tri1Vertices[3].UV = Vector2(0.0f, 0.0f);

	unsigned int indices[6] { 0, 1, 2, 2, 3, 0 };*/

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

	shader->Bind();
	buffer1->Create(&objReader.GetVertices()[0], objReader.GetVertices().size() * sizeof(BF::IO::Vertex));
	//buffer2->Create(tri2Vertices, sizeof(tri2Vertices));

	indexBuffer->Create(&objReader.GetIndices()[0], objReader.GetIndices().size());

	initBuffer.modelMatrix = Matrix4::Scale(Vector3(2.0f, 2.0f, 2.0f)) * Matrix4::Translate(Vector3(0.0f, -0.2f, 0.0f));
	initBuffer.color = Vector4(1.0f, 0.0f, 0.5f, 1.0f);
	constentBuffer->Create(&initBuffer, sizeof(initBuffer), 0);

	vertexBufferLayout = new VertexBufferLayout();

	vertexBufferLayout->Push(0, "POSITION", DataType::Float3, sizeof(BF::IO::Vertex), 0);
	//vertexBufferLayout->Push(1, "COLOR", DataType::Float4, sizeof(BF::IO::Vertex), 0);
	//vertexBufferLayout->Push(2, "TEXCOORD", DataType::Float2, sizeof(BF::IO::Vertex), sizeof(BF::Math::Vector3));

	context->SetPrimitiveType(PrimitiveType::TriangleList);

	buffer1->SetLayout(vertexBufferLayout);
	//buffer2->SetLayout(vertexBufferLayout);

	texture2D->Bind();
}

RenderTriangle::~RenderTriangle()
{
}

void RenderTriangle::Draw()
{
	context->Clear(Vector4(0.5, 0.0f, 0.5f, 1.0f));

	angle += 0.050f;
	initBuffer.color = Vector4(0.2f, 0.5f, 0.3f, 1.0f);
	initBuffer.modelMatrix = Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Translate(Vector3(0, -2.0f, 4.0f)) * Matrix4::Perspective(90.0f, window->GetAspectRatio(), 0.1f, 1000.0f);
	constentBuffer->Update(&initBuffer, sizeof(initBuffer));
	
	buffer1->Bind();
	indexBuffer->Bind();
	context->Draw(indexBuffer->GetIndicesCount());
	indexBuffer->Unbind();
	buffer1->Unbind();

	/*
	angle += 0.050f;
	initBuffer.color = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	//initBuffer.modelMatrix = Matrix4::Rotate(angle, Vector3(0, 0, 1)) * Matrix4::Perspective(90.0f, window->GetAspectRatio(), 0.1f, 1000.0f);
	initBuffer.modelMatrix = Matrix4::Translate(Vector3(0, 0.5f, 6.0f)) * Matrix4::Perspective(90.0f, window->GetAspectRatio(), 0.1f, 1000.0f);
	constentBuffer->Update(&initBuffer, sizeof(initBuffer));
	
	buffer2->Bind();
	context->Draw(3);
	buffer2->Unbind();
	*/
	context->SwapBuffers();
}

void RenderTriangle::CleanUp()
{
	shader->CleanUp();
	//context->CleanUp();
}