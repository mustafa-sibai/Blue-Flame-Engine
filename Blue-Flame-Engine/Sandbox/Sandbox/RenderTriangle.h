#pragma once
#include <BF/Application/Window.h>
#include <BF/Graphics/API/Context.h>
#include <BF/Graphics/API/Shader.h>
#include <BF/Graphics/API/ConstentBuffer.h>
#include <BF/Graphics/API/Texture2D.h>
#include <BF/Graphics/Model.h>
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
		Window *window;
		Context *context;
		Shader *shader;
		InitBuffer initBuffer;
		ConstentBuffer *constentBuffer;
		Model *model;
		Texture2D *texture2D;
		float angle = 0;

	public:
		RenderTriangle(Window *window);
		~RenderTriangle();

		void Draw();
		void CleanUp();
};