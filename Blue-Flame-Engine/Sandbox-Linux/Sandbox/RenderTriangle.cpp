#include "RenderTriangle.h"
/*
RenderTriangle::RenderTriangle(Window &window) :
	window(window), renderer(window), shader(renderer), buffer1(renderer), buffer2(renderer), bufferMapper(renderer), constentBuffer(renderer), initBuffer()
{
	renderer.Initialize();

	//create vertices clockwise
	tri1Vertices[0].position = Vector3(-1.0f, 0.0, 0.0f);
	tri1Vertices[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	tri1Vertices[1].position = Vector3(0.0f, 1.0f, 0.0f);
	tri1Vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	tri1Vertices[2].position = Vector3(1.0f, 0.0f, 0.0f);
	tri1Vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	

	tri2Vertices[0].position = Vector3(0.75f, 0.0, 0.0f);
	tri2Vertices[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	tri2Vertices[1].position = Vector3(0.50f, 0.5f, 0.0f);
	tri2Vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	tri2Vertices[2].position = Vector3(0.25f, 0.0f, 0.0f);
	tri2Vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
		shader.Load("D:\\Projects\\Personal Projects\\Blue Flame Enginee\\Blue Flame Engine\\Output\\Sandbox\\x64\\Binary\\Debug\\VertexShader.cso",
			"D:\\Projects\\Personal Projects\\Blue Flame Enginee\\Blue Flame Engine\\Output\\Sandbox\\x64\\Binary\\Debug\\PixelShader.cso");
	else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
		shader.Load("VertexShader.glsl", "FragmentShader.glsl");
	
	shader.Bind();
	buffer1.Create(tri1Vertices, sizeof(tri1Vertices));
	buffer2.Create(tri2Vertices, sizeof(tri2Vertices));

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

	bufferMapper.Create(&shader, shaderLayout, 2);

	constentBuffer.Create(shader, &initBuffer, sizeof(initBuffer), 0);

	renderer.SetPrimitiveType(Renderer::PrimitiveType::TriangleList);
}

RenderTriangle::~RenderTriangle()
{
}

void RenderTriangle::Draw()
{
	initBuffer.color = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	
	angle += 0.050f;
	initBuffer.modelMatrix = Matrix4::Translate(Vector3(0, 0, 0)) * Matrix4::Perspective(90.0f, window.GetAspectRatio(), 0.1f, 1000.0f);
	constentBuffer.Update(&initBuffer, sizeof(initBuffer));

	renderer.Clear(Vector4(0.5, 0.0f, 0.5f, 1.0f));

	buffer1.Bind();
	bufferMapper.Map(&buffer1);
	buffer1.Unbind();
	
	renderer.Draw(3);

	initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.35f, 1, 1)) * Matrix4::Perspective(90.0f, window.GetAspectRatio(), 0.1f, 1000.0f);
	constentBuffer.Update(&initBuffer, sizeof(initBuffer));

	buffer2.Bind();
	bufferMapper.Map(&buffer2);
	buffer2.Unbind();

	renderer.Draw(3);
	
	renderer.SwapBuffers();
}

void RenderTriangle::CleanUp()
{
	shader.CleanUp();
	renderer.CleanUp();
}*/