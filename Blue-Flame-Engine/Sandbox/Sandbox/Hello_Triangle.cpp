#include "Hello_Triangle.h"

namespace Hello_Triangle
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;

	Hello_Triangle::Hello_Triangle()
	{
	}

	Hello_Triangle::~Hello_Triangle()
	{
	}

	void Hello_Triangle::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableDepthBuffer(true);
		BF::Engine::GetContext().EnableVsync(false);
		//BF::Engine::LimitFrameRate(60.0f);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);

		//camera.Initialize(Matrix4::Orthographic(-((int)Engine::GetWindow().GetClientWidth() / 2), (int)(Engine::GetWindow().GetClientWidth() / 2), ((int)Engine::GetWindow().GetClientHeight() / 2), -(int)(Engine::GetWindow().GetClientHeight() / 2), -1.0f, 1.0f));

		App::Initialize();

		GameObject* cameraGameObject = scene->AddGameObject(new GameObject("Camera"));
		Camera* camera = (Camera*)cameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(-5, 5, 5, -5, -10.0f, 10.0f)));
		camera->gameObject->GetTransform()->SetPosition(Vector3f(0, 0, -1));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.5, 0.0f, 0.0f, 1.0f));


		//-------------------------------------------------------- 3D Model --------------------------------------------------------
		Model* model = new Model();

		//------------------------------------ Materials ------------------------------------------
		BF::Graphics::API::Shader* shader = new Shader();
		shader->LoadStandardShader(BF::Graphics::API::ShaderType::P);

		MeshMaterialColorBuffer meshAMaterialColorBuffer;
		meshAMaterialColorBuffer.ambientColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
		meshAMaterialColorBuffer.diffuseColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
		meshAMaterialColorBuffer.specularColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
		meshAMaterialColorBuffer.shininess = 256;

		model->AddMaterial(MeshMaterial(shader, meshAMaterialColorBuffer));

		MeshMaterialColorBuffer meshBMaterialColorBuffer;
		meshBMaterialColorBuffer.ambientColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
		meshBMaterialColorBuffer.diffuseColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
		meshBMaterialColorBuffer.specularColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
		meshBMaterialColorBuffer.shininess = 256;

		model->AddMaterial(MeshMaterial(shader, meshBMaterialColorBuffer));
		//------------------------------------ Materials ------------------------------------------

		//------------------------------------ Mesh A ------------------------------------------
		std::vector<BF::Graphics::MeshData::PVertexData>* meshAVertices = new std::vector<BF::Graphics::MeshData::PVertexData>();
		std::vector<unsigned int>* meshAIndices = new std::vector<unsigned int>();

		meshAVertices->emplace_back(BF::Graphics::MeshData::PVertexData(Vector3f(-0.5, 0.5, 0)));
		meshAVertices->emplace_back(BF::Graphics::MeshData::PVertexData(Vector3f(0.5, 0.5, 0)));
		meshAVertices->emplace_back(BF::Graphics::MeshData::PVertexData(Vector3f(0.5, -0.5, 0)));

		meshAIndices->emplace_back(0);
		meshAIndices->emplace_back(1);
		meshAIndices->emplace_back(2);

		MeshData* meshAData = new MeshData(meshAVertices, meshAIndices, 0, BF::Graphics::MeshData::VertexStructVersion::P);
		//------------------------------------ Mesh A ------------------------------------------

		//------------------------------------ Mesh B ------------------------------------------
		std::vector <BF::Graphics::MeshData::PVertexData>* meshBVertices = new std::vector<BF::Graphics::MeshData::PVertexData>();
		std::vector<unsigned int>* meshBIndices = new std::vector<unsigned int>();

		meshBVertices->emplace_back(BF::Graphics::MeshData::PVertexData(Vector3f(0.5, -0.5, 0)));
		meshBVertices->emplace_back(BF::Graphics::MeshData::PVertexData(Vector3f(-0.5, -0.5, 0)));
		meshBVertices->emplace_back(BF::Graphics::MeshData::PVertexData(Vector3f(-0.5, 0.5, 0)));

		meshBIndices->emplace_back(0);
		meshBIndices->emplace_back(1);
		meshBIndices->emplace_back(2);

		MeshData* meshBData = new MeshData(meshBVertices, meshBIndices, 1, BF::Graphics::MeshData::VertexStructVersion::P);
		//------------------------------------ Mesh B ------------------------------------------

		model->AddMesh(Mesh(meshAData));
		model->AddMesh(Mesh(meshBData));

		//-------------------------------------------------------- 3D Model --------------------------------------------------------

		GameObject* planeGameObject = scene->AddGameObject(new GameObject("Plane"));
		planeModel = (Model*)planeGameObject->AddComponent(model);
		planeModel->gameObject->GetTransform()->SetPosition(Vector3f(0, -1, 5));
		planeModel->gameObject->GetTransform()->SetScale(Vector3f(3, 3, 3));
	}

	void Hello_Triangle::Load()
	{
		App::Load();
	}

	void Hello_Triangle::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void Hello_Triangle::Update(double deltaTime)
	{
		App::Update(deltaTime);
	}

	void Hello_Triangle::Render()
	{
		position.y += 0.0001f;

		App::Render();
	}
}