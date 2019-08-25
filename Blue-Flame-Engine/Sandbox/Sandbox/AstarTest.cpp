#include "AstarTest.h"

namespace AstarTest
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::GUI;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::Graphics::Renderers::SpriteRendererComponents;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;
	using namespace BF::IO;
	using namespace BF::AI::Astar;

	AstarTest::AstarTest()
	{
	}

	AstarTest::~AstarTest()
	{
	}

	void AstarTest::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		defaultRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.GetDefaultRenderLayer();
		spriteRenderLayer = renderPipeline.spriteRenderer->renderLayerManager.AddRenderLayer(new RenderLayer("Sprites", RenderLayer::SortingOrder::BackToFrontRightToLeft));

		GameObject* CameraGameObject = scene->AddGameObject(new GameObject("Camera"));

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		App::Initialize();
	}

	void AstarTest::SetupNodes()
	{
		/*for (size_t i = 0; i < 5; i++)
		{
			GameObject* gameObject = scene->AddGameObject(new GameObject("Astar node" + std::to_string(i + 1)));

			nodes.emplace_back(gameObject);
			gameObject->AddComponent(new Sprite(nodeTexture, Vector2f(0.5, 0.5), defaultRenderLayer));
			gameObject->AddComponent(new AstarNode());
		}*/

		AstarNode* topLeftNode		= nodes[0]->GetComponent<AstarNode>();
		AstarNode* topRightNode		= nodes[1]->GetComponent<AstarNode>();
		AstarNode* bottomRightNode	= nodes[2]->GetComponent<AstarNode>();
		AstarNode* bottomLeftNode	= nodes[3]->GetComponent<AstarNode>();
		AstarNode* centerNode		= nodes[4]->GetComponent<AstarNode>();

		//Top Left
		nodes[0]->Name = "Top Left Node";
		nodes[0]->GetTransform()->SetPosition(Vector3f(-500, 200, 0));
		topLeftNode->neighbours.emplace_back(topRightNode);
		topLeftNode->neighbours.emplace_back(bottomLeftNode);
		topLeftNode->neighbours.emplace_back(centerNode);

		//Top Right
		nodes[1]->Name = "Top Right Node";
		nodes[1]->GetTransform()->SetPosition(Vector3f(500, 200, 0));
		topRightNode->neighbours.emplace_back(topLeftNode);
		topRightNode->neighbours.emplace_back(bottomRightNode);
		topRightNode->neighbours.emplace_back(centerNode);

		//Bottom Right
		nodes[2]->Name = "Bottom Right Node";
		nodes[2]->GetTransform()->SetPosition(Vector3f(500, -200, 0));
		bottomRightNode->neighbours.emplace_back(topRightNode);
		bottomRightNode->neighbours.emplace_back(bottomLeftNode);
		bottomRightNode->neighbours.emplace_back(centerNode);

		//Bottom Left
		nodes[3]->Name = "Bottom Left Node";
		nodes[3]->GetTransform()->SetPosition(Vector3f(-500, -200, 0));
		bottomLeftNode->neighbours.emplace_back(topLeftNode);
		bottomLeftNode->neighbours.emplace_back(bottomRightNode);
		bottomLeftNode->neighbours.emplace_back(centerNode);

		//Center
		nodes[4]->Name = "Center Node";
		nodes[4]->GetTransform()->SetPosition(Vector3f(0, 0, 0));
		centerNode->neighbours.emplace_back(topLeftNode);
		centerNode->neighbours.emplace_back(topRightNode);
		centerNode->neighbours.emplace_back(bottomRightNode);
		centerNode->neighbours.emplace_back(bottomLeftNode);

		for (size_t i = 0; i < nodes.size(); i++)
		{
			AstarNode* node = nodes[i]->GetComponent<AstarNode>();

			for (size_t j = 0; j < node->neighbours.size(); j++)
			{
				Vector3f currentNodePosition = node->gameObject->GetTransform()->GetPosition();
				Vector3f neighbourNodePosition = node->neighbours[j]->gameObject->GetTransform()->GetPosition();

				nodes[i]->AddComponent(new LineShape(Vector2f(currentNodePosition.x, currentNodePosition.y), Vector2f(neighbourNodePosition.x, neighbourNodePosition.y), 2, defaultRenderLayer));
			}
		}

		/*astarAgent = scene->AddGameObject(new GameObject("Astar agent"));

		astarAgent->AddComponent(new Sprite(astarAgentTexture, Vector2f(0.5, 0.5), defaultRenderLayer));
		astarAgent->AddComponent(new AstarAgent());*/

		//astarAgent
	}

	void AstarTest::Load()
	{
		App::Load();

		astarAgentTexture = new Texture2D();
		astarAgentTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/agent.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);

		startingNodeTexture = new Texture2D();
		startingNodeTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/startingNode.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);

		endNodeTexture = new Texture2D();
		endNodeTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/endNode.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);

		nodeTexture = new Texture2D();
		nodeTexture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/Astar/node.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);
	}

	void AstarTest::PostLoad()
	{
		App::PostLoad();

		SetupNodes();

		/*GameObject* startingNodeGameObject = scene->AddGameObject(new GameObject("Starting Node"));
		startingNodeGameObject->AddComponent(new Sprite(startingNodeTexture, Vector2f(0.5, 0.5), defaultRenderLayer));
		startingNodeGameObject->GetTransform()->SetPosition(Vector3f(-500, 200, 0));

		GameObject* endNodeGameObject = scene->AddGameObject(new GameObject("end Node"));
		endNodeGameObject->AddComponent(new Sprite(endNodeTexture, Vector2f(0.5, 0.5), defaultRenderLayer));
		endNodeGameObject->GetTransform()->SetPosition(Vector3f(400, -250, 0));




		GameObject* lineGameObject = scene->AddGameObject(new GameObject("line"));
		lineGameObject->AddComponent(new LineShape(Vector2f(-500, 200), Vector2f(400, -250), defaultRenderLayer));
		lineGameObject->GetTransform()->SetPosition(Vector3f(0, 0, 0));*/

		App::RunScene(*scene);
	}

	BF::Math::Vector2f pos(640, 360);

	void AstarTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5f, 0.5f));
		BF::Math::Rectangle orthoRect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(orthoRect.x, orthoRect.width, orthoRect.y, orthoRect.height, -1.0f, 1.0f));

		BF::Math::Vector2f mousePosition = BF::Input::Mouse::GetPosition();

		/*BF::Math::Vector3f newPos = camera->ScreenToWorldPoint(Vector3f(mousePosition.x, mousePosition.y, 0), Vector2f(0.5f, 0.5f));
		
		line->startPoint = Vector2f(0);

		Vector3f v3 = Camera::ScreenToWorldPoint(Vector3f(BF::Input::Mouse::GetPosition().x, BF::Input::Mouse::GetPosition().y, 0), Vector2f(0.5f, 0.5f));
		line->endPoint = Vector2f(v3.x, v3.y);

		BF::Math::Vector2f diff = BF::Input::Mouse::GetPosition() - pos;

		BF::Math::Vector2f n(diff.y, diff.x);
		n = n.Normalize();

		BFE_LOG_INFO("" + line->endPoint, "");*/
	}

	void AstarTest::Render()
	{
		App::Render();
	}
}