#pragma once
#include <BF/BlueFlame.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <vector>

struct Vertex 
{
	BF::Math::Vector3 position;
	BF::Math::Vector4 color;
	BF::Math::Vector2 UV;
};

struct InitBuffer
{
	BF::Math::Matrix4 modelMatrix;
	BF::Math::Matrix4 viewMatrix;
	BF::Math::Matrix4 projectionMatrix;
	BF::Math::Vector4 color;
};

class RenderTriangle
{
	private:
		BF::Application::Window* window;
		BF::Graphics::API::Context* context;
		BF::Graphics::API::Shader* shader;
		InitBuffer initBuffer;
		BF::Graphics::API::ConstentBuffer* constentBuffer;

		BF::Graphics::Renderers::SpriteRenderer* spriteRenderer;
		//BF::Graphics::Model* model;
		//BF::Graphics::API::Texture2D* texture2D;
		//BF::Graphics::FPSCamera* fpsCamera;
		BF::System::Timer* timer;

		std::vector<BF::Graphics::Renderers::Sprite*>* sprites;

		float angle = 0;
		int frames = 0;

	public:
		RenderTriangle(BF::Application::Window* window);
		~RenderTriangle();

		void Draw();
		void CleanUp();
};