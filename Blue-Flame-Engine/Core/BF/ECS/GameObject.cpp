#include "GameObject.h"
#include "BF/Application/Scene.h"
#include "BF/Application/App.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace ECS
	{
		using namespace std;
		using namespace BF::Application;
		using namespace BF::Graphics;
		using namespace BF::Graphics::Renderers;
		using namespace BF::Scripting;

		int GameObject::globalID = 0;

		GameObject::GameObject(Scene& scene, const std::string& name) :
			scene(scene), Active(true), Name(name), id(0), added(false), parent(nullptr)
		{
			GameObject::globalID++;
			id = globalID;

			components.emplace_back(new Transform());
			components[0]->gameObject = this;
		}

		GameObject::~GameObject()
		{
		}

		Component* GameObject::AddComponent(Component* component)
		{
			if (!component->added)
			{
				if (component->type == Component::Type::Camera || 
					component->type == Component::Type::Renderable ||
					component->type == Component::Type::Mesh)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene.app.renderPipeline.AddRenderable(component);
					component->added = true;
				}
				else if (component->type == Component::Type::Script)
				{
					component->gameObject = this;
					components.emplace_back(component);
					scene.scriptExecutor.scripts.emplace_back((Script*)component);
					component->added = true;
				}
			}
			else
				//Do copy here
				BFE_LOG_WARNING("This Component of id: \"" + std::to_string(component->id) + "\" has already been added to GameObject \"" +
					Name + "\" of id \"" + std::to_string(id) + "\". This Component will not be added again.", "");

			return component;
		}

		void GameObject::RemoveComponent(Component* component)
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