#pragma once
/*#include <BFE/Graphics/Window.h>
#include <BFE/Graphics/Buffers/VertexBuffer.h>
#include <BFE/Graphics/Buffers/BufferMapper.h>
#include <BFE/Graphics/Buffers/ConstentBuffer.h>
#include <BFE/Graphics/Shader/Shader.h>
#include <BFE/Math/Math.h>
#include <iostream>

using namespace BFE::Graphics;
using namespace BFE::Graphics::Buffers;
using namespace BFE::Math;

struct Vertex 
{
	Vector3 position;
	Vector4 color;
};

struct InitBuffer
{
	Matrix4 modelMatrix;
	Vector4 color;
};

class RenderTriangle
{
	private:
		Vertex tri1Vertices[3];
		Vertex tri2Vertices[3];

		InitBuffer initBuffer;
		VertexBuffer buffer1, buffer2;
		ConstentBuffer constentBuffer;
		BufferMapper::ShaderLayout shaderLayout[2];
		BufferMapper bufferMapper;
		Window &window;
		Renderer renderer;
		Shader shader;
		float angle = 0;

	public:
		RenderTriangle(Window &window);
		~RenderTriangle();

		void Draw();
		void CleanUp();
};*/