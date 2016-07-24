#include "RenderTriangle.h"

RenderTriangle::RenderTriangle(Window &window) :
	window(window), renderer(window), shader(renderer), buffer(renderer), constentBuffer(renderer), initBuffer()
{
	renderer.Initialize();

	//create vertices clockwise
	vertices[0].position = Vector3(-0.5f, 0.0, 0.0f);
	vertices[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	vertices[1].position = Vector3(0.0f, 0.5f, 0.0f);
	vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[2].position = Vector3(0.5f, 0.0f, 0.0f);
	vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	
	if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
		shader.Load("C:/Projects/Personal Projects/Blue Flame Engine/Blue Flame Engine/Output/Sandbox/x64/Binary/Debug/VertexShader.cso", "C:/Projects/Personal Projects/Blue Flame Engine/Blue Flame Engine/Output/Sandbox/x64/Binary/Debug/PixelShader.cso");
	else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
		shader.Load("VertexShader.glsl", "FragmentShader.glsl");
	
	shader.Bind();
	buffer.CreateVertexBuffer(vertices, sizeof(vertices));
	
	BufferMapper bufferMapper(renderer);
	BufferMapper::ShaderLayout shaderLayout[2];

	shaderLayout[0].index = 0;
	shaderLayout[0].name = "POSITION";
	shaderLayout[0].componentCount = 3;
	shaderLayout[0].dataType = BufferMapper::DataType::FLOAT;
	shaderLayout[0].stride = sizeof(Vertex);
	shaderLayout[0].offset = 0;

	shaderLayout[1].index = 1;
	shaderLayout[1].name = "COLOR";
	shaderLayout[1].componentCount = 4;
	shaderLayout[1].dataType = BufferMapper::DataType::FLOAT;
	shaderLayout[1].stride = sizeof(Vertex);
	shaderLayout[1].offset = 12;

	bufferMapper.Map(buffer, shader, shaderLayout, 2);

	initBuffer.modelMatrix = Matrix4::Scale(Vector3(2.0f, 2.0f, 2.0f)) * Matrix4::Translate(Vector3(0.0f, -0.2f, 0.0f));
	initBuffer.color = Vector4(1.0f, 0.0f, 0.5f, 1.0f);
	constentBuffer.CreateConstentBuffer(shader, &initBuffer, sizeof(initBuffer), "shader_data", 0);
}

RenderTriangle::~RenderTriangle()
{
}

void RenderTriangle::Draw()
{
	renderer.Clear(Vector4(0.5, 0.0f, 0.5f, 1.0f));
	renderer.Draw(Renderer::PrimitiveType::TriangleList, 3);
	renderer.SwapBuffers();
}

void RenderTriangle::CleanUp()
{
	shader.CleanUp();
	renderer.CleanUp();
}