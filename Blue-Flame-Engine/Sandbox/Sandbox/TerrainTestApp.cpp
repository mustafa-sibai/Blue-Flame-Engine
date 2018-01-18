#include "TerrainTestApp.h"

using namespace BF;
using namespace BF::AI;
using namespace BF::Application;
using namespace BF::Graphics;
using namespace BF::Graphics::API;
using namespace BF::Graphics::Renderers;
using namespace BF::Graphics::GUI;
using namespace BF::Math;
using namespace BF::System;

TerrainTestApp::TerrainTestApp()
{
}

TerrainTestApp::~TerrainTestApp()
{
}

void TerrainTestApp::Initialize()
{
	BF::Engine::GetContext().EnableDepthBuffer(true);
	BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

	fpsCamera.Initialize(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
	terrain.Initialize();

	light.posDir = Vector4f(0, 0, 0, 1);
	constantBuffer.Create(sizeof(LightBuffer), 1);
	materialConstantBuffer.Create(sizeof(terrainMaterial.colorBuffer), 2);
}

void TerrainTestApp::Load()
{
	terrain.Load("Assets/HeightMaps/heightmap.bmp");
}

void TerrainTestApp::Update()
{
	fpsCamera.Update();
	//App::Update();

	if (Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::UpArrow))
		light.posDir.z += 5.0f;

	if (Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::DownArrow))
		light.posDir.z -= 5.0f;

	if (Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::RightArrow))
		light.posDir.x += 5.0f;

	if (Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::LeftArrow))
		light.posDir.x -= 5.0f;
	
	if (Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::O))
		light.posDir.y += 5.0f;

	if (Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::L))
		light.posDir.y -= 5.0f;

	BF_LOG_INFO(light.posDir, " posDir");
}

void TerrainTestApp::Render()
{
	BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
	//App::Render();

	//BF_LOG_INFO(fpsCamera.GetPosition(), "");
	terrainMaterial.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
	terrainMaterial.colorBuffer.diffuseColor = Color(0.0f, 1.0f, 0.0f, 1.0f);
	terrainMaterial.colorBuffer.specularColor = Color(0.0f, 0.0f, 0.5f, 1.0f);
	terrainMaterial.colorBuffer.shininess = 8.0f;
	materialConstantBuffer.Update(&terrainMaterial, sizeof(terrainMaterial.colorBuffer));


	light.ambientColor  = Color(0.5f);
	light.diffuseColor  = Color(0.5f);
	light.specularColor = Color(0.5f);

	constantBuffer.Update(&light, sizeof(LightBuffer));

	terrain.Render();

	BF::Engine::GetContext().SwapBuffers();
}