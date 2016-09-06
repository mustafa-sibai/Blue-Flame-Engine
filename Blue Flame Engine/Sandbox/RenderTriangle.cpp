#include "RenderTriangle.h"

RenderTriangle::RenderTriangle(Window &window) :
	window(window), renderer(window), shader(renderer), buffer1(renderer), buffer2(renderer), constentBuffer(renderer), initBuffer()
{
	renderer.Initialize();

	//create vertices clockwise
	tri1Vertices[0].position = Vector3(-1.0f, 0.0, 0.0f);
	tri1Vertices[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	tri1Vertices[1].position = Vector3(-0.75f, 0.5f, 0.0f);
	tri1Vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	tri1Vertices[2].position = Vector3(-0.5f, 0.0f, 0.0f);
	tri1Vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	

	tri2Vertices[0].position = Vector3(0.75f, 0.0, 0.0f);
	tri2Vertices[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	tri2Vertices[1].position = Vector3(0.50f, 0.5f, 0.0f);
	tri1Vertices[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	tri2Vertices[2].position = Vector3(0.25f, 0.0f, 0.0f);
	tri2Vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	if (Renderer::renderingAPI == Renderer::RenderingAPI::DirectX11)
		shader.Load("D:\\Projects\\Personal Projects\\Blue Flame Enginee\\Blue Flame Engine\\Output\\Sandbox\\x64\\Binary\\Debug\\VertexShader.cso",
			"D:\\Projects\\Personal Projects\\Blue Flame Enginee\\Blue Flame Engine\\Output\\Sandbox\\x64\\Binary\\Debug\\PixelShader.cso");
	else if (Renderer::renderingAPI == Renderer::RenderingAPI::OpenGL4_5)
		shader.Load("VertexShader.glsl", "FragmentShader.glsl");
	
	shader.Bind();
	buffer1.CreateVertexBuffer(tri1Vertices, sizeof(tri1Vertices));
	
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

	bufferMapper.Map(buffer1, shader, shaderLayout, 2);
	constentBuffer.CreateConstentBuffer(shader, &initBuffer, sizeof(initBuffer), 0);



	buffer2.CreateVertexBuffer(tri2Vertices, sizeof(tri2Vertices));
	//bufferMapper.Map(buffer2, shader, shaderLayout, 2);

	renderer.SetPrimitiveType(Renderer::PrimitiveType::TriangleList);
}

RenderTriangle::~RenderTriangle()
{
}

void RenderTriangle::Draw()
{
	initBuffer.color = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	
	//angle += 0.050f;
	initBuffer.modelMatrix = Matrix4::Translate(BFE::Math::Vector3(0, 0, 0));/*Matrix4::Rotate(angle, Vector3(0, 0, 1))*/;
	constentBuffer.UpdateConstentBuffer(&initBuffer, sizeof(initBuffer));

	renderer.Clear(Vector4(0.5, 0.0f, 0.5f, 1.0f));
	renderer.Draw(3);
	renderer.SwapBuffers();
}

void RenderTriangle::CleanUp()
{
	shader.CleanUp();
	renderer.CleanUp();
}