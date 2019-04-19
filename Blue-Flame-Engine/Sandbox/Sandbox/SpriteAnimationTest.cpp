#include "SpriteAnimationTest.h"
#include "BF/Graphics/Animation/DataType.h"
#include "BF/Graphics/Animation/Condition.h"
#include "BF/Graphics/Animation/AnimationController.h"
#include "BF/Graphics/Animation/AnimationData.h"
#include "BF/Graphics/Animation/AnimationNode.h"

namespace SpriteAnimationTest
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::GUI;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Animation;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::Graphics::Renderers::SpriteRendererComponents;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;
	using namespace BF::IO;


	SpriteAnimationTest::SpriteAnimationTest()
	{
	}

	SpriteAnimationTest::~SpriteAnimationTest()
	{
	}

	void SpriteAnimationTest::Initialize()
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
		BF::Math::Rectangle rect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(rect.x, rect.width, rect.y, rect.height, -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.0, 0.0f, 0.0f, 1.0f));

		App::Initialize();
	}

	void SpriteAnimationTest::Load()
	{
		App::Load();
	}

	std::vector<Sequence>* sequence = new std::vector<Sequence>();
	std::vector<KeyFrame>* walkingLeftKeyframes = new std::vector<KeyFrame>;
	std::vector<KeyFrame>* walkingRightKeyframes = new std::vector<KeyFrame>;

	void SpriteAnimationTest::PostLoad()
	{
		App::PostLoad();

		GameObject* playerGameObject = scene->AddGameObject(new GameObject("player"));

		AnimationController* animationController = new AnimationController();
		animationController->dataTypes.emplace_back(new AInt(20));

		//-----------------------------------------------------------------------------------------------------------------------------------

		for (size_t i = 0; i < 8; i++)
			walkingLeftKeyframes->emplace_back(KeyFrame(100 * (i + 1), BF::Math::Rectangle(32 * i, 0, 32, 48)));
		
		for (size_t i = 0; i < 6; i++)
			walkingRightKeyframes->emplace_back(KeyFrame(100 * (i + 1), BF::Math::Rectangle(32 * i, 48, 32, 48)));

		sequence->emplace_back(walkingLeftKeyframes);
		sequence->emplace_back(walkingRightKeyframes);

		AnimationData data("../Sandbox/Assets/Textures/player.png", sequence);
		data.filePath = "../Sandbox/Assets/Textures/player.png";

		Texture2D* texture = new Texture2D();
		texture->Create(ResourceManager::Load<TextureData>(data.textureName), Texture::Format::R8G8B8A8);

		BF::Graphics::Animation::Animation* walkingLeftAnimation = new BF::Graphics::Animation::Animation(texture, &(*data.sequences)[0], true);
		BF::Graphics::Animation::Animation* walkingRightAnimation = new BF::Graphics::Animation::Animation(texture, &(*data.sequences)[1], true);

		//-----------------------------------------------------------------------------------------------------------------------------------

		AnimationNode* walkingLeftAnimationNode = new AnimationNode();
		walkingLeftAnimationNode->animation = walkingLeftAnimation;

		AnimationNode* walkingRightAnimationNode = new AnimationNode();
		walkingRightAnimationNode->animation = walkingRightAnimation;

		//-----------------------------------------------------------------------------------------------------------------------------------

		Transition* startingNodeTransition = new Transition(walkingLeftAnimationNode, true);
		Condition* startingCondition = new Condition(animationController->dataTypes[0], Condition::EvaluationOperator::BiggerThan, new AInt(10));
		startingNodeTransition->conditions.emplace_back(startingCondition);

		animationController->startingAnimationNode->transition = startingNodeTransition;

		//-----------------------------------------------------------------------------------------------------------------------------------

		Transition* walkingLeftTransition = new Transition(walkingRightAnimationNode, true);
		Condition* walkingLeftCondition = new Condition(animationController->dataTypes[0], Condition::EvaluationOperator::BiggerThan, new AInt(10));
		walkingLeftTransition->conditions.emplace_back(walkingLeftCondition);

		walkingLeftAnimationNode->transitions.emplace_back(walkingLeftTransition);

		//-----------------------------------------------------------------------------------------------------------------------------------

		Animator* animator = (Animator*)playerGameObject->AddComponent(new Animator(animationController));
		//animator->gameObject->GetTransform()->SetScale(Vector3f(3, 3, 3));

		App::RunScene(*scene);
	}

	void SpriteAnimationTest::Update(double deltaTime)
	{
		App::Update(deltaTime);

		orthographicRectangle = BF::Math::Rectangle(0, 0, Engine::GetWindow().GetClientSize().x, Engine::GetWindow().GetClientSize().y, Vector2f(0.5, 0.5f));
		BF::Math::Rectangle rect = orthographicRectangle.GetEdgeOffsetByPivot();

		camera->SetProjectionMatrix(Matrix4::Orthographic(rect.x, rect.width, rect.y, rect.height, -1.0f, 1.0f));
	}

	void SpriteAnimationTest::Render()
	{
		App::Render();
	}
}