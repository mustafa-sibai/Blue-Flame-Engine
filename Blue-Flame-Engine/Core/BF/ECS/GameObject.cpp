#include "GameObject.h"
#include "BF/Application/Scene.h"
#include "BF/Application/App.h"
#include "BF/Graphics/Model.h"
#include "BF/Graphics/GUI3/IWidget.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace ECS
	{
		using namespace std;
		using namespace BF::Application;
		using namespace BF::Graphics;
		using namespace BF::Graphics::GUI;
		using namespace BF::Graphics::Renderers;
		using namespace BF::Graphics::Renderers::SpriteRendererComponents;
		using namespace BF::Scripting;

		int GameObject::globalID = 0;

		GameObject::GameObject(const std::string& name) :
			scene(nullptr), Active(true), Name(name), id(0), added(false), parent(nullptr)
		{
			GameObject::globalID++;
			id = globalID;

			components.emplace_back(new Transform());
			components[0]->gameObject = this;
		}

		GameObject::~GameObject()
		{
		}

		IComponent* GameObject::AddComponent(IComponent* component)
		{
			if (!component->added)
			{
				if (component->type == IComponent::Type::Camera)
				{
					component->gameObject = this;
					components.emplace_back(component);
					Camera* camera = (Camera*)component;
					camera->cameraManager = &scene->app.cameraManager;
					scene->app.cameraManager.AddCamera((Camera*)component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Widget)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene->app.guiSystem.AddWidget((IWidget*)component);
					component->added = true;
				}
				else if (component->type == IComponent::Type::Renderable ||
					component->type == IComponent::Type::Model)
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