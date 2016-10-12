#pragma once
#include <BF/Application/Window.h>
#include <BF/Graphics/API/Context.h>
#include <BF/Graphics/API/Shader.h>
#include <BF/Graphics/API/VertexBuffer.h>
#include <BF/Graphics/API/ConstentBuffer.h>
#include <BF/Graphics/API/Texture2D.h>
#include <BF/Graphics/API/IndexBuffer.h>
#include <BF/IO/OBJReader.h>
#include <BF/Math/Math.h>
#include <vector>
#include <iostream>

using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::API;
using namespace BF::Math;

struct Vertex 
{
	Vector3 position;
	Vector4 color;
	Vector2 UV;
};

struct InitBuffer
{
	Matrix4 modelMatrix;
	Vector4 color;
};

class RenderTriangle
{
	private:
		
		//Vertex tri2Vertices[3];

		Window *window;
		Context *context;
		Shader *shader;
		InitBuffer initBuffer;
		VertexBuffer *buffer1/*, *buffer2*/;
		IndexBuffer *indexBuffer;
		ConstentBuffer *constentBuffer;
		VertexBufferLayout *vertexBufferLayout;
		Texture2D *texture2D;
		BF::IO::OBJReader objReader;
		float angle = 0;

	public:
		RenderTriangle(Window *window);
		~RenderTriangle();

		void Draw();
		void CleanUp();
};