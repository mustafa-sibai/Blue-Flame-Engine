#pragma once
#include <BFE\Graphics\Buffer.h>
#include <BFE\Graphics\BufferMapper.h>
#include <BFE\Graphics\Shader\Shader.h>
#include <BFE\Math\Math.h>

using namespace BFE::Graphics;
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
		Vertex vertices[3];
		InitBuffer initBuffer;
		Buffer buffer, constentBuffer;
		Window &window;
		Renderer renderer;
		Shader shader;

	public:
		RenderTriangle(Window &window);
		~RenderTriangle();

		void Draw();
		void CleanUp();
};