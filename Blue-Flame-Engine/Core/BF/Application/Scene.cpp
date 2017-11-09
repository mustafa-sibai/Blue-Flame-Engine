#include "Scene.h"
#include "BF/System/Log.h"


namespace BF
{
	namespace Application
	{
		using namespace BF::Graphics::Renderers;

		Scene::Scene() :
			initialized(false), loaded(false), fixedUpdateTicks(0)
		{
		}

		Scene::~Scene()
		{
		}

		void Scene::Initialize()
		{
			spriteRenderer.Initialize();

			for (size_t i = 0; i < gameNodes.size(); i++)
				gameNodes[i]->Initialize();
		}

		void Scene::Load()
		{
			for (size_t i = 0; i < gameNodes.size(); i++)
				gameNodes[i]->Load();
		}

		/*void Scene::FixedUpdate()
		{
		}*/

		void Scene::Update()
		{
			for (size_t i = 0; i < gameNodes.size(); i++)
				gameNodes[i]->Update();
		}

		void Scene::Render()
		{
			for (size_t i = 0; i < gameNodes.size(); i++)
			{
				switch (gameNodes[i]->nodeType)
				{
					case GameNode::NodeType::Sprite:
					{
						spriteRenderer.Render(*(RegularPolygon*)gameNodes[i]);
						break;
					}
					case GameNode::NodeType::Mesh:
					{
						break;
					}
					case GameNode::NodeType::Audio:
					{
						break;
					}
					default:
					{
						break;
					}
				}

				RenderNode(gameNodes[i]);
			}

			spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);
			spriteRenderer.End();
		}

		void Scene::RenderNode(GameNode* node)
		{
			for (size_t i = 0; i < node->gameNodes.size(); i++)
			{
				RenderNode(node->gameNodes[i]);

				switch (gameNodes[i]->nodeType)
				{
					case GameNode::NodeType::Sprite:
					{
						spriteRenderer.Render(*(RegularPolygon*)(node->gameNodes[i]));
						break;
					}
					case GameNode::NodeType::Mesh:
					{
						break;
					}
					case GameNode::NodeType::Audio:
					{
						break;
					}
					default:
					{
						break;
					}
				}
			}
		}
	}
}