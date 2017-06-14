#include "_3D_Scene_Single_Light_Test.h"

namespace _3D_Scene_Single_Light_Test
{
	using namespace BF;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Input;

	_3D_Scene_Single_Light_Test::_3D_Scene_Single_Light_Test() :
		cubeModel(shader), cubeMaterial(shader)
	{
	}

	_3D_Scene_Single_Light_Test::~_3D_Scene_Single_Light_Test()
	{
	}

	void _3D_Scene_Single_Light_Test::Initialize()
	{
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);
		fpsCamera.Initialize(Matrix4::Perspective(45.0f, Engine::GetWindow().GetAspectRatio(), 0.1f, 1000.0f));
		constantBuffer.Create(sizeof(LightBuffer), 1);
		materialConstantBuffer.Create(sizeof(cubeMaterial.colorBuffer), 2);
	}

	void _3D_Scene_Single_Light_Test::Load()
	{
		shader.LoadStandardShader(ShaderType::SingleLight3D);
		BF::Engine::GetContext().EnableDepthBuffer(true);
		cubeModel.Load("Assets/Models/TexturedCube/TexturedCube.bfx");

		cubeMaterial.diffuseMap.Load("Assets/Textures/diffuseMap.png");
		cubeMaterial.specularMap.Load("Assets/Textures/specularMap.png");
		cubeMaterial.normalMap.Load("Assets/Textures/normalMap.jpg");

		cubeMaterial.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		cubeMaterial.colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		cubeMaterial.colorBuffer.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		cubeMaterial.colorBuffer.shininess = 128.0f;
		materialConstantBuffer.Update(&cubeMaterial, sizeof(cubeMaterial.colorBuffer));

		light.posDir = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
		light.ambientColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		light.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		light.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		constantBuffer.Update(&light, sizeof(LightBuffer));
	}

	void _3D_Scene_Single_Light_Test::Update()
	{
		fpsCamera.Update();
	}

	void _3D_Scene_Single_Light_Test::Render()
	{
		Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));
		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, 0.0f, 10.0f)) * Matrix4::Scale(Vector3(1.0f)));
		shader.Bind();
		cubeMaterial.Bind();
		cubeModel.Render();
		cubeMaterial.Unbind();
		shader.Unbind();
		Engine::GetContext().SwapBuffers();
	}
}