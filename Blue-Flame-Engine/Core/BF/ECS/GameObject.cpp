#include "GameObject.h"
#include "BF/Application/Scene.h"
#include "BF/Application/App.h"
#include "BF/Graphics/Model.h"
#include "BF/Graphics/GUI3/IWidget.h"
#include "BF/Physics/ICollider.h"
#include "BF/AI/Astar/AstarNode.h"
#include "BF/System/Debug.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/IRenderable.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/RectangleShape.h"

namespace BF
{
	namespace ECS
	{
		using namespace std;
		using namespace BF::Application;
		using namespace BF::Graphics;
		using namespace BF::Graphics::GUI;
		using namespace BF::Graphics::Animation;
		using namespace BF::Graphics::Renderers;
		using namespace BF::Graphics::Renderers::SpriteRendererComponents;
		using namespace BF::Physics;
		using namespace BF::Scripting;
		using namespace BF::AI::Astar;
		using namespace BF::System;
		using namespace BF::System;
		using namespace BF::Math;

		int GameObject::globalID = 0;

		GameObject::GameObject(const std::string& name) :
			scene(nullptr), Active(true), Name(name), id(0), added(false), parent(nullptr)
		{
			GameObject::globalID++;
			id = globalID;

			//components.emplace_back(new Transform());
			//components[0]->gameObject = this;
		}

		GameObject::~GameObject()
		{
		}

		RectangleShape& GameObject::AddComponent(Vector2i& size, Vector2f& pivot, Vector2f& position, RectangleShape& rectangleShape)
		{
			rectangleShape.gameObject = this;

			//Transform* transform = (Transform*)components[0];

			//transform->transformables.emplace_back(new RenderableTransform(size, pivot));
			//rectangleShape.transfrom = (RenderableTransform*)(transform)->transformables[transform->transformables.size() - 1];

			//components.emplace_back(rectangleShape);
			rectangleShape.SetPosition(size, pivot, position);
			scene->app.renderPipeline.AddRectangle(rectangleShape);

			rectangleShape.added = true;

			return rectangleShape;
		}

		/*IRenderable* GameObject::AddComponent(Vector2i& size, Vector2f& pivot, IRenderable* iRenderable)
		{
			iRenderable->gameObject = this;

			Transform* transform = (Transform*)components[0];

			transform->transformables.emplace_back(new RenderableTransform(size, pivot));
			iRenderable->transfrom = (RenderableTransform*)(transform)->transformables[transform->transformables.size() - 1];

			components.emplace_back(iRenderable);
			scene->app.renderPipeline.AddRenderable(iRenderable);

			iRenderable->added = true;

			return iRenderable;
		}*/

		/*IRenderable* GameObject::AddComponent(Vector2i& size, Vector2f& pivot, IRenderable* iRenderable)
		{
			iRenderable->gameObject = this;

			Transform* transform = (Transform*)components[0];

			transform->transformables.emplace_back(new RenderableTransform(size, pivot));
			iRenderable->transfrom = (RenderableTransform*)(transform)->transformables[transform->transformables.size() - 1];

			components.emplace_back(iRenderable);
			scene->app.renderPipeline.AddRenderable(iRenderable);

			iRenderable->added = true;

			return iRenderable;
		}*/

		IComponent* GameObject::AddComponent(IComponent* component)
		{
			if (!component->added)
			{
				if (component->type == IComponent::Type::Physics)
				{
					component->gameObject = this;
					components.emplace_back(component);
					//ICollider* collider = (ICollider*)component;
					//collider->cameraManager = &scene->app.cameraManager;
					scene->app.physicsEngine.AddComponent(component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Camera)
				{
					component->gameObject = this;
					components.emplace_back(component);
					Camera* camera = (Camera*)component;
					camera->cameraManager = &scene->app.cameraManager;
					scene->app.cameraManager.AddCamera(camera);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Widget)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene->app.guiSystem.AddWidget((IWidget*)component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Animator)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene->app.animationSystem.AddAnimator((Animator*)component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Model)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene->app.renderPipeline.AddRenderable(component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Script)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene->app.scriptExecutor.scripts.emplace_back((IScript*)component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Astar)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene->app.astarSystem.AddComponent((AstarNode*)component);
					component->added = true;
				}
			}
			else
				//Do copy here
				BFE_LOG_WARNING("This Component of id: \"" + std::to_string(component->id) + "\" has already been added to GameObject \"" +
					Name + "\" of id \"" + std::to_string(id) + "\". This Component will not be added again.", "");

			return component;
		}

		void GameObject::RemoveComponent(IComponent* component)
		{
			/*if (component->type == Component::Type::Renderable)
			{
				for (std::vector<Renderable*>::iterator it = scene.spriteRenderer.renderables.begin(); it != scene.spriteRenderer.renderables.end(); ++it)
				{
					if (((Component*)*it)->GetID() == component->GetID())
					{
						scene.spriteRenderer.renderables.erase(it);
						break;
					}
				}
			}

			for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
			{
				if (((Component*)*it)->GetID() == component->GetID())
				{
					components.erase(it);
					break;
				}
			}

			delete component;*/
		}

		void GameObject::SetParent(GameObject* parent)
		{
			this->parent = parent;
		}
	}
}